// dijsktras.cpp
// Michael McRoskey, David Mellitt, Troy Prince

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "graph.h"
#include <memory>
using namespace std;

int main(int argc, char *argv[]) {
	
	// INPUT GRAPH FILE-----------------------------
	
	//ifstream infile; 
	//infile.open("www/graph.txt");
    string source, target;
    Graph A;
    string inputFile;
    //cout << "What is the name of the input file?" << endl;
    //cin >> inputFile;
    //ifstream infile;
    //infile.open(inputFile);

    string friend_1, friend_2;
    cin >> friend_1 >> friend_2;

	
    while(cin >> source) {
	cin >> target;
	
	A.add(source, target, "line");
   
    }
    //infile.close();
	// INPUT FRIENDS TO SEARCH----------------------
    
    //string friend_1, friend_2;
    //cin >> friend_1 >> friend_2;
	
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
	rewrite.open("www/graphTest.txt", std::ofstream::trunc);

	if(rewrite.is_open()){
		rewrite << A.write();
	}
	rewrite.close();
}
