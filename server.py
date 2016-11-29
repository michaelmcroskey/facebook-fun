#!/usr/bin/env python2.7

from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
from SocketServer   import ForkingMixIn

import getopt, json, logging, mimetypes
import os, subprocess, sys, facebook, requests

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
        self.send_header('Content-type', 'application/json')
        self.end_headers()

        print data
        
#        p = subprocess.Popen(['./src/dijkstras'], stdin=subprocess.PIPE, stdout=subprocess.PIPE)
#        d = [map(int, line.split()) for line in p.communicate(data)[0].splitlines()]
#        json.dump({'path': d[1:], 'cost': d[0]}, self.wfile)

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
