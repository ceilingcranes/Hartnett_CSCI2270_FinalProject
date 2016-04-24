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
            bool correct=false;
            string name, special, notes, u;
            int urgency;
            while(!correct){

                cout << "Please enter the name of the patient. " << endl;
                cin.ignore();
                getline(cin, name);
                cout << "Please enter the urgency as a number. The higher the number, the more urgency and the earlier in the queue." << endl;
                getline(cin, u);
                urgency=stoi(u);
                cout << "Please enter the specialist for the patient. If none, enter 'none'" << endl;
                getline(cin, special);
                cout << "Please enter any special notes about the patient. If none, enter 'none'" << endl;
                getline(cin, notes);
                cout << "Is this information correct?" << endl;
                cout << "Name: " << name << ", Urgency: " << urgency << ", Specialist: " << special << ", notes: " << notes << endl;
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
            q.insertNewPatient(name, urgency, special, notes);

        }
        if(i==2){
            q.printArray();

        }
        if(i==3){
                cout << "Next Patient: " << endl;
            Patient * p=q.pop();
            if(p==NULL){
                cout << "Queue Empty.(main)" << endl;
            }
            else{
                cout << p->name << endl;
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
            string name, special, notes, u;
            int urgency;
            while(!correct){

                cout << "Please enter the name of the patient. " << endl;
                getline(cin, name);
                cout << "Please enter the urgency as a number. The higher the number, the more urgency and the earlier in the queue." << endl;
                getline(cin, u);
                urgency=stoi(u);
                cout << "Please enter the specialist for the patient. If none, enter 'none'" << endl;
                getline(cin, special);
                cout << "Please enter any special notes about the patient. If none, enter 'none'" << endl;
                getline(cin, notes);
                cout << "Is this information correct?" << endl;
                cout << "Name: " << name << ", Urgency: " << urgency << ", Specialist: " << special << ", notes: " << notes << endl;
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
            q.insertNewPatient(name, urgency, special, notes);

        }



    }
    cout << "Goodbye!" << endl;



}
