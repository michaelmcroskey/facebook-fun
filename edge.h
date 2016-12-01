#include<iostream>
#include<vector>

using namespace std;


struct edge {
    string source;
    string target;
    bool type;
    //vector<>
edge(string s, string t, bool ty) : source(s), target(t), type(ty) {} 
};
