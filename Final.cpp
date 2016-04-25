/* Author: Maxine Hartnett
*Class: CSCI 2270
*Information on heaps and priority queues found here: <http://pages.cs.wisc.edu/~vernon/cs367/notes/11.PRIORITY-Q.html>
*/


#include <iostream>
#include "PQueue.h"
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
int main(){

    PQueue q;
    string s="";
    int i=-1;
    while(i!=7){
        cout << "======Main Menu======" << endl;
        cout << "1. Enter a new patient" << endl; //To add a new patient to the heap
        cout << "2. Print patients" << endl; //Will print out the names and urgencies of all the patients currently in the heap
        //Will return and remove the patient with the highest urgency from the heap. Used for getting the next patient who needs to
        //be treated.
        cout << "3. Get next patient" << endl;
        cout << "4. Remove patient from queue" << endl; //Will remove a patient by name.
        cout << "5. Find a patient" << endl; //Will print out the info for a patient searched by name.
        cout << "6. Edit patient" << endl; //Will delete an entered patient and allow you to re-enter the data.
        cout << "7. Quit" << endl;
        cin >> s;
        try{
            i=stoi(s);
        }
        catch(...){
            i=0;
            cout << "Error: Please enter an integer." << endl;
        }
        if(i==1){
            bool correct=false;
            string name, notes, u;
            int urgency=-1;
            while(!correct){

                cout << "Please enter the name of the patient. " << endl;
                cin.ignore();
                getline(cin, name);
                while(urgency==-1){
                    cout << "Please enter the urgency as a number. The higher the number, the more urgency and the earlier in the queue." << endl;
                    getline(cin, u);
                    try{
                        urgency=stoi(u);

                    }
                    catch(...){
                        urgency=-1;
                        cout << "Error: Please enter an integer for the urgency." << endl;
                    }
                }
                //cout << "Please enter the specialist for the patient. If none, enter 'none'" << endl;
                //getline(cin, special);
                cout << "Please enter any special notes about the patient. If none, enter 'none'" << endl;
                getline(cin, notes);
                cout << "Is this information correct?" << endl;
                cout << "Name: " << name << ", Urgency: " << urgency << ", notes: " << notes << endl;
                string check;
                getline(cin, check);
                if(check=="no"||check=="n"||check=="NO"||check=="N"){
                    cout << "Please re-enter the information." << endl;
                }
                else
                    correct=true;

            }

            q.insertNewPatient(name, urgency,  notes); //Inserts the new patient into the heap

        }
        if(i==2){
            q.printArray();

        }
        if(i==3){
            cout << "Next Patient: " << endl;
            Patient * p=q.pop();
            if(p==NULL){
                cout << "Queue Empty." << endl;
            }
            else{
                q.printPatientPointer(p); //Will print out name, urgency, and notes.
            }

        }
        if(i==4){
            cout << "Enter a patient name. "  << endl;
            string findName;
            cin.ignore();
            getline(cin, findName);
            int removed=q.removePatient(findName);
            if(removed!=0){
                cout << "Error removing patient." << endl;
            }
            else{
                cout << "Successfully removed patient." << endl;
            }

        }
        if(i==5){
            cout << "Enter a patient name. "  << endl;
            string findName;
            cin.ignore();
            getline(cin, findName);
            q.printPatientData(findName);
        }
        if(i==6){
            cout << "Enter a patient name. "  << endl;
            string findName;
            cin.ignore();
            getline(cin, findName);

            q.removePatient(findName);

            bool correct=false;
            string name,  notes, u;
            int urgency;
            while(!correct){

                cout << "Please enter the name of the patient. " << endl;
                getline(cin, name);
                cout << "Please enter the urgency as a number. The higher the number, the more urgency and the earlier in the queue." << endl;
                getline(cin, u);
                urgency=stoi(u);
                //cout << "Please enter the specialist for the patient. If none, enter 'none'" << endl;
                //getline(cin, special);
                cout << "Please enter any special notes about the patient. If none, enter 'none'" << endl;
                getline(cin, notes);
                cout << "Is this information correct?" << endl;
                cout << "Name: " << name << ", Urgency: " << urgency << ", notes: " << notes << endl;
                string check;
                getline(cin, check);
                if(check=="no"||check=="n"||check=="NO"||check=="N"){
                    cout << "Please re-enter the information." << endl;
                }
                else
                    correct=true;

            }
            cout << "Inserting" << endl;
            cout << "***********" << endl;
            q.insertNewPatient(name, urgency, notes);

        }



    }
    cout << "Goodbye!" << endl;



}
