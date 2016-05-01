/* Author: Maxine Hartnett
*Class: CSCI 2270
*Information on heaps and priority queues found here: <http://pages.cs.wisc.edu/~vernon/cs367/notes/11.PRIORITY-Q.html>
*/

#include <iostream>
#include <vector>

struct Patient{
    std::string name;
    int urgency; //The higher the number, the more urgent
    //std::string specialist;
    std::string notes;
    Patient *parent;
    Patient *left;
    Patient *right;
    Patient(std::string n, int u, std::string note){
        name=n;
        urgency=u;
        //s=specialist;
        notes=note;
    }

};

class PQueue{
public:
    PQueue();
    ~PQueue();
    void insertNewPatient(std::string name, int urgency, std::string notes); //creates a new patient and adds it to the queue.
    Patient *pop(); //gets the root of the heap- the patient with the maximum urgency.
    void printArray(); //prints out every patient in the array, with their indexes.
    void doubleArray(); //Doubles the size of the array- this is called when you try and add a patient to a full array.
    Patient * findPatient(std::string name); //Will search through heap for a pointer with name "name"
    int removePatient(std::string name); //Will remove a patient from name- finds the pointer and index, then calls deletePatient
    int deletePatient(Patient * nextP, int patientIndex); //removes a patient and restructures the heap.
    void printPatientData(std::string name); //Will find a patient with name "name" and print out the name, urgency, and notes.
    void printPatientPointer(Patient * p); //Will print out the name, urgency, and notes of pointer p.
    void printPatients();

private:
    //std::vector <Patient* > patientQueue;
    int arraySize=10; //the initial size of the array
    Patient ** patientArray; //The array that holds the structure of the heap
    Patient * largestChild(Patient* parent); //Will find and return the child of Patient * parent with the highest urgency.
    void swapPatientsByIndex(int indChild, int indParent); //Will swap the pointers at indChild and indParent
    void swapPatients(Patient *child, Patient* parent); //Will swap child and parent within the heap.
};
