#include<iostream>
#include <vector>
#include <map>
#include <string>
#include "edge.h"

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
    void add(string source, string target, string type) {
		bool lineType;
		if (type == "line") lineType = false;
		else lineType = true;
		adjacencyList[source].push_back(new edge(source, target, lineType));
		adjacencyList[target].push_back(new edge(target, source, lineType));
    }
    
    std::string write() {
		string result;
		string lineType;
		result += "[";
		bool first = true;
		for (pair<string, vector<edge*> > edgeList : adjacencyList) {
		    for (edge* E : edgeList.second) {
				lineType = (E->type) ? "bold" : "line";
				if (first){
					first = false;
				} else {
					result += ",";
				}
				result += "{\"source\":\"" + E->source;
				result += "\",\"target\":\"" + E->target;
				result += "\",\"type\":\"" + lineType + "\"}";
		    }
		}
		result += "]";
		return result;
    }
};

//{"source":"Troy","target":"Travis","type":"line"}

