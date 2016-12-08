#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cassert>
#include <queue>
#include "edge.h"

using namespace std;

struct Graph {
    //map of person ID's to a vector of pointers to connected nodes
    map<string, vector<edge*> > adjacencyList;  
    priority_queue<edge*, vector<edge*>, PEdgeCost> F;
    map<string, string> marked;
    
    void add(string source, string target, string type) {
	if(search_for_Node(source, target) != -1) return;
	adjacencyList[source].push_back(new edge(source, target, false));
	adjacencyList[target].push_back(new edge(target, source, false));
    }

    bool search_for(string source) {
	if (adjacencyList.find(source) != adjacencyList.end())
	    return true;
	else
	    return false;
    }

    int search_for_Node(string source, string target) {
	if(!search_for(source)) return -1;
	else {
	    for(size_t i=0; i < adjacencyList[source].size(); ++i) {
		if (adjacencyList[source][i]->target == target) return i;
	    }
	}
	return -1;
    }

    
    string write() {
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
    
   
    void shortestPath(string start, string end) {
	bool connected = true;
        int dist=0;  //reset distance
        addEdgesToF(start); //begin start

        //loop until you find the desired value
        int i = 0;
        while(1) {
            i++;
            ///cout << i << endl;
            if (i>10000) {
		connected = false;
		break;
	    }
            //pop from frontier, pass over if its been recahed already
	    if (F.empty()) {
		connected = false;
		break;
	    }
            edge* E = F.top();
            F.pop();
            if(marked.find(E->target) != marked.end()) continue;

	    //cout << E->source << " " << E->target << endl;
	    //E->type = 1;
            marked[E->target] = E->source;  //add to marked
	    if(E->target == end) break;

	    for (auto u : adjacencyList[E->target]) {
		u->v = u->v + E->v;
		F.push(u);
	    }
		//addEdgesToF(E->target); //add this nodes edges to frontier
            dist += E->v;  //increment distance
        }
	if(connected) {
	    int j=0;
	    while(start != end) {
		//cout << end << ' ';
		adjacencyList[end][search_for_Node(end, marked[end])]->type = 1;
		end = marked[end];
		//cout << end  << endl;
		j++;
		//if (j==100) break;
	    }
	}
        //clear marked and F
        marked.clear();
        F = priority_queue<edge*, vector<edge*>, PEdgeCost>();
    }

    //adds edges of a node to the frontier
    void addEdgesToF(string source)  {
	for(edge* E : adjacencyList[source]) {
	    F.push(E);
	}
    
    }

};





//{"source":"Troy","target":"Travis","type":"line"}

