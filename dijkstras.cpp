// dijsktras.cpp
// Michael McRoskey, David Mellitt, Troy Prince

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"
#include <memory>
using namespace std;

string exec(const char* cmd) {
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
	
	// Return error if incorrect input (doesn't exist or same person)
	
	string error = "SUCCESS";
	
	if (friend_1 == friend_2){
		string same_person = "Error: " + friend_1 + " is the same person";
		error = same_person;
		cout << error;
		return 0;
	}
		
	if (A.search_for(friend_1)){
		// Found friend_1
		if (A.search_for(friend_2)){
			// Found friend_2
		} else {
			string no_friend_2 = "Error: " + friend_2 + " does not exist in this network";
			error = no_friend_2;
			cout << error;
			return 0;
		}
	} else if (A.search_for(friend_2)){
		string no_friend_2 = "Error: " + friend_1 + " does not exist in this network";
		error = no_friend_2;
		cout << error;
		return 0;
	} else {
		string no_friends = "Error: Neither " + friend_1 + " nor "+ friend_2 + " exists in this network";
		error = no_friends;
		cout << error;
		return 0;
	}
		
	// PERFORM DIJSKTRAS----------------------------
	
	A.shortestPath(friend_1, friend_2);
	
	cout << "SUCCESS";
	
	// RE-WRITE FILE WITH BOLD LINKS----------------
	
	ofstream rewrite;
	rewrite.open("www/graph.txt", std::ofstream::trunc);

	if(rewrite.is_open()){
		rewrite << A.write();
	}
	rewrite.close();
}