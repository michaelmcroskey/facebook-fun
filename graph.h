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
    priority_queue<edge*> F;
    map<string, string> marked;
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
	//if(search_for_Node(source, target)) return;
//	assert(search_for_Node(target, source));// && "Error because the path was not stored multi-directionally")
	if(search_for_Node(source, target) != -1) return;
	//assert(search_for_Node(target, source));// && "Error because the path was not stored multi-directionally"); 
		bool lineType;
		if (type == "line") lineType = false;
		else lineType = true;
		adjacencyList[source].push_back(new edge(source, target, lineType));
		adjacencyList[target].push_back(new edge(target, source, lineType));
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
	    for(size_t i=0; i< adjacencyList[source].size(); ++i) {
		if (adjacencyList[source][i]->target == target) return i;
	    }
	}
	return -1;
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

    void prims() {
	size_t N = adjacencyList.size();
	//while(1) {
	int dist=0;  //reset distance
        //G = makeGraph(N);  //make graph from input
	edge* E = adjacencyList.begin()->second[0]; //get starting node
        addEdgesToF(E->target);//, F);  //begin with first in graph
        marked[E->target] = E->source;
        //loop until all nodes have been acounted for
        int i = 0;
        while(marked.size() < N) {
            i++;
	    //cout << i << endl;
            if (i>1000) break;
            //pop from frontier, pass over if its been recahed already
            E = F.top();
            F.pop();
            if(marked.find(E->target) != marked.end()) continue;


	    adjacencyList[E->source][search_for_Node(E->source, E->target)]->type = 1;
            marked[E->target] = E->source;  //add to marked
            addEdgesToF(E->target); //add this nodes edges to frontier
            dist += E->v;  //increment distance
        }
        //display
//        cout << dist;
        //display(marked);

	//clear marked and F
        marked.clear();
	F = priority_queue<edge*>();

    }
   
    void shortestPath(string start, string end) {
      
        int dist=0;  //reset distance
        addEdgesToF(start);//, F);  //begin with first in graph
        //marked[E->target] = E->source;
        //loop until you find the desired value
        int i = 0;
        while(1) {//marked.size() < N) {
            i++;
            ///cout << i << endl;
            if (i>100) break;

            //pop from frontier, pass over if its been recahed already
	    if (F.empty()) break;
            edge* E = F.top();
            F.pop();
            if(marked.find(E->target) != marked.end()) continue;

	    //cout << E->source << " " << E->target << endl;
	    //E->type = 1;
            //adjacencyList[E->source][search_for_Node(E->source, E->target)]->type = 1;
            marked[E->target] = E->source;  //add to marked
	    if(E->target == end) break;

	    for (auto u : adjacencyList[E->target]) {
		u->v = u->v + E->v;
		F.push(u);
	    }
		//addEdgesToF(E->target); //add this nodes edges to frontier
            dist += E->v;  //increment distance
        }

	while(start != end) {
	    adjacencyList[end][search_for_Node(end, marked[end])]->type = 1;
	    end = marked[end];
	}
        //display
	//        cout << dist;
        //display(marked);

        //clear marked and F
        marked.clear();
        F = priority_queue<edge*>();
    }

    //adds edges of a node to the frontier
    void addEdgesToF(string source)  {
	for(edge* E : adjacencyList[source]) {
	    F.push(E);
	    
	}

    //size_t j = sz(Node);
    //for(size_t i=0; i<G.size(); ++i) {
        //if(G[i][j] != -1) {
    //      F.push(edge(G[i][j], i, j));
    //  }
    
    }

};





//{"source":"Troy","target":"Travis","type":"line"}

