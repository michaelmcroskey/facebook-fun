#include<iostream>
#include<vector>
#include<map>
#include<node.h>
using namespace std;

struct Graph {
    //map of person ID's to a vector of pointers to connected nodes
    map<string, vector<node*> > adjacecyList;  

    Graph() {
	string ID;
	string Name_First;
	string Name_Last;

    }
};

