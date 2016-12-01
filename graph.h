#include<iostream>
#include<vector>
#include<map>
#include<string>
#include"edge.h"
using namespace std;

struct Graph {
    //map of person ID's to a vector of pointers to connected nodes
    map<string, vector<edge*> > adjacencyList;  

    /*Graph() {
	string source;
	string target;
	while(cin >> source) {
	    cin >> target;
	    adjacencyList[source].push_back(new edge(source, target, false));
	    adjacencyList[target].push_back(new edge(target, source, false));
	}
    }*/
    void add(string source, string target) {
	adjacencyList[source].push_back(new edge(source, target, false));
	adjacencyList[target].push_back(new edge(target, source, false));
    }
    
    void write() {
	string lineType;
	cout << "[";
	for(pair<string, vector<edge*> > edgeList : adjacencyList) {
	    for(edge* E : edgeList.second) {
		lineType = (E->type) ? "bold" : "line";
		cout << "{\"source\":\"" << E->source;
		cout << "\",\"target\":\"" << E->target;
		cout << "\",\"type\":\"" << lineType << "\"},";
	    }
	}
	cout << "]" << endl;
    }
};

//{"source":"Troy","target":"Travis","type":"line"}

