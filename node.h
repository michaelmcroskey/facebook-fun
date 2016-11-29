#include<iostream>
#include<vector>

using namespace std;


struct node {
    string firstName;
    string lastName;
    string ID;
    //vector<>
    node(string f, string l, string id) : firstName(f), lastName(l), ID(id) {} 
};
