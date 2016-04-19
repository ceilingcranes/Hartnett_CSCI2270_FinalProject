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
    while(i!=7){
        cout << "======Main Menu======" << endl;
        cout << "1. Enter a new patient" << endl;
        cout << "2. Print patients" << endl;
        cout << "3. Get next patient" << endl;
        cout << "4. Remove patient from queue" << endl;
        cout << "5. Find a patient" << endl;
        cout << "6. Edit patient" << endl;
        /*cout << "6. Get next specialty patient" << endl;
        cout << "7. List specialty doctors" << endl;
        cout << "8. Add a new doctor" << endl;*/
        cout << "7. Quit" << endl;
        cin >> s;
        i=stoi(s);
        if(i==1){
        }
        if(i==2){

        }
        if(i==3){

        }
        if(i==4){

        }
        if(i==5){

        }
        if(i==6){

        }



    }
    cout << "Goodbye!" << endl;



}
