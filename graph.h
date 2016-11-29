#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"node.h"
using namespace std;

struct Graph {
    //map of person ID's to a vector of pointers to connected nodes
    map<string, vector<node*> > adjacencyList;  

    Graph() {
	string Name_First;
	string Name_Last;
	string ID;
	while(cin >> Name_First) {
	    cin >> Name_Last;
	    cin >> ID;
	    adjacencyList["X"].push_back(new node(Name_First, Name_Last, ID));
	    adjacencyList[ID].push_back(new node("First", "Last", "X"));
	}
    }
    void display() {
	for(auto it = adjacencyList.begin(); it !=adjacencyList.end(); ++it) {
	    cout << it->first << "     " << it->second[0]->firstName << endl;
	}
    }
};

