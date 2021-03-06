#!/usr/bin/env python2.7

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
from SocketServer   import ForkingMixIn

import getopt, json, logging, mimetypes
import os, subprocess, sys

# Constants

WWW_PORT = 9001
WWW_ROOT = os.path.abspath('www')

# Utility Functions

def determine_mimetype(url):
    return mimetypes.guess_type(url)[0] or 'text/plain'

# Handlers

class ForkingHTTPServer(ForkingMixIn, HTTPServer):
    pass

class WWWHandler(BaseHTTPRequestHandler):

    def do_GET(self):
        if self.path == '/':
            self.path = '/index.html'

        mimetype = determine_mimetype(self.path)
        realpath = os.path.abspath(WWW_ROOT + self.path)

        if not realpath.startswith(WWW_ROOT):
            self.send_error(404, 'Invalid file path: {}'.format(self.path))
            return

        try:
            with open(realpath, 'rb') as fh:
                self.send_response(200)
                self.send_header('Content-type', mimetype)
                self.end_headers()
                self.wfile.write(fh.read())
        except IOError as e:
            self.send_error(404, 'File Not Found: {}\n{}'.format(self.path, e))

    def do_POST(self):
        data = self.rfile.read(int(self.headers.getheader('content-length')))
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()
        
        # if data is friends list
        if (data[0] == 'f' and data[7] == ':'):
            addFriends(data)
        elif (data[0] == 'p' and data[3] == 'h'):
            d_input = processDijkstrasInput(data)
            p = subprocess.Popen(['./dijkstras'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
            d = p.communicate(d_input)[0]
            try:
                if (d[0] == 'E'):
                    self.wfile.write(d)
                    print "Dijkstras found an input error: " + d
                elif (d[0] == 'S'):
                    self.wfile.write(d)
                    print d
            except:
                self.wfile.write("Error: No friends in common.")
                print "Exception"

def processDijkstrasInput(data):
    first = True
    string = ""
    nodes = data.split('\n')
    string = nodes[1] + " " + nodes[2]
    return string

def addFriends(data):
    first = True
    comma = False
    string = ""
    for friend in data.split('\n'):
        if first:
            person = friend.split(":")[1].split(" ")[0]
            first = False;
            continue
        if comma:
            string += ","
        else:
            comma = True
        name = friend.split(",")[0].split(" ")[0]
        f_id = friend.split(",")[1]
        
        print person + name
        
        string += "{\"source\":\"" + person + "\",\"target\":\"" + name + "\",\"type\":\"line\"}"
    
    # CASE 1: FILE EXISTS
    # APPENDING FILE: READ IN AND STRIP STRING, APPEND FRIENDS
    if os.path.exists("www/graph.txt"):
        # Read in graph.txt
        f = open("www/graph.txt", "r")
        data = f.read()
        data = ''.join(data.split())[:-1] # strip whitespace
        f.close()
        # Append graph.txt
        f = open("www/graph.txt", "w")
        f.write(data + "," + string + "]")
        print "wer gunna right:"
        print data + "," + string + "]"
        f.close()
        # de-duplicating occurs in the Javascript forEach function?
    else:
        # CASE 2: FILE DOESN'T EXIST
        # ADD "[" "]" BEFORE AND AFTER
        f = open("www/graph.txt", "w+")
        f.write("[" + string + "]")
        f.close()

# Usage

def usage(exit_code):
    print >>sys.stderr, 'usage: {} -d WWW_ROOT -p WWW_PORT'.format(os.path.basename(sys.argv[0]))
    sys.exit(exit_code)

# Main Execution

if __name__ == '__main__':
    try:
        options, arguments = getopt.getopt(sys.argv[1:], "hd:p:")
    except getopt.GetoptError as e:
        usage(1)

    for option, value in options:
        if option == '-h':
            usage(0)
        elif option == '-d':
            WWW_ROOT = value
        elif option == '-p':
            WWW_PORT = int(value)
        else:
            usage(1)
    
    server = ForkingHTTPServer(('', WWW_PORT), WWWHandler)
    print 'Started HTTP Server on port', WWW_PORT
    server.serve_forever()

# vim: set sts=4 sw=4 ts=8 expandtab ft=python:
