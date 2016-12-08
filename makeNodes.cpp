#include<iostream>
#include<cstdio>
#include<ctime>
#include<random>
using namespace std;


char getRandomChar(int R) {
    
    //static char c = 'A' + rand()%24;
    return 'A' + (char)(rand()%(R)); //(char)(random(127-33) + 33);
}

string MDigetName(int M, int R) {
    string Name = "";
    for(int i=0; i<M; ++i) {
	Name += getRandomChar(R);
    }
    return Name;
}

int main() {
    srand(time(0));
    int N, M, R;
    cout << "How many letters of the alphabet to consider?" << endl;
    cin >> R;
    cout << "How many letters in random node?" << endl;
    cin >> N;
    cout << "How many edges?" << endl;
    cin >> M;

   
    for(int i=0; i<M; ++i) {
	cout << MDigetName(N, R) << " " << MDigetName(N, R) << endl;
    }
}
