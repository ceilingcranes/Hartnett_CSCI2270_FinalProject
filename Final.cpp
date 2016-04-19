#include <iostream>
#include "Graph.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
int main(int argc, char* argv[]){
    if(argc!=2){
        cout << "Error with command line arguments." << endl;
        return 1;
    }
    string filename=argv[1];
    ifstream inFile;
    inFile.open(filename);


    string s="";
    int i=-1;
    while(i!=4){
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Quit" << endl;
        cin >> s;
        i=stoi(s);
        if(i==1){
            g.displayEdges();
        }
        if(i==2){
            g.assignDistricts();
            //g.displayEdges();
        }
        if(i==3){
            string st;
            string en;
            cout << "Enter a starting city:" << endl;
            cin.ignore();
            getline(cin, st);
            cout << "Enter an ending city:" << endl;
            //cin.ignore();
            getline(cin, en);
            //cout << "st: " << st << " en: " << en<< endl;
            g.shortestPath(st, en);
        }



    }
    cout << "Goodbye!" << endl;



}
