// dijsktras.cpp
// Michael McRoskey, David Mellitt, Troy Prince

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"

std::string exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer, 128, pipe.get()) != NULL)
			result += buffer;
	}
	return result;
}

using namespace std;
int main(int argc, char *argv[]) {
	
	// INPUT GRAPH FILE-----------------------------
	
	ifstream infile; 
	infile.open("www/graph.txt");
	string line;
	Graph A;
	
	if (infile.is_open()){
		while (getline(infile, line)){
			string parsed = exec("./filter.sh");
			parsed.erase(0,1);
			parsed.pop_back();
			
			stringstream ss(parsed);
			string dump, source, target, type;
			while (ss >> dump >> source >> dump >> target >> dump >> type){
				A.add(source, target, type);
			}
		}
		infile.close();
	}
	
	// INPUT FRIENDS TO SEARCH----------------------
		
	string friend_1, friend_2;
	cin >> friend_1 >> friend_2;
	
	// PERFORM DIJSKTRAS----------------------------
	
	
	
	
	// RE-WRITE FILE WITH BOLD LINKS----------------
	
	ofstream rewrite;
	rewrite.open("www/graph.txt");

	if(rewrite.is_open()){
		rewrite << A.write();            
	}
	rewrite.close();
	
	
}