#include<iostream>
#include<vector>

using namespace std;


struct edge {
    string source;
    string target;
    bool type;
    int v;
    //vector<>
edge(string s, string t, bool ty) : source(s), target(t), type(ty), v(1) {} 


    //overloaded operator< for the priority queue to work
    //friend bool operator<(const edge left, const edge right) { return left.v > right.v; }


};
