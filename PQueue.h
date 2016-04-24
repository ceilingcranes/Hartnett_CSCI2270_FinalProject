#include <iostream>
#include <vector>

struct Patient{
    std::string name;
    int urgency; //The higher the number, the more urgent
    std::string specialist;
    std::string notes;
    Patient *parent;
    Patient *left;
    Patient *right;
    Patient(std::string n, int u, std::string s, std::string note){
        name=n;
        urgency=u;
        s=specialist;
        notes=note;
    }

};

class PQueue{
public:
    PQueue();
    ~PQueue();
    void insertNewPatient(std::string name, int urgency, std::string doctor, std::string notes);
    Patient *pop();
    void printArray();
    void doubleArray();
    Patient * findPatient(std::string name);
    int removePatient(std::string name);
    int deletePatient(Patient * nextP, int patientIndex);
    void printPatientData(std::string name);

private:
    //std::vector <Patient* > patientQueue;
    int arraySize=10; //set to ten
    Patient ** patientArray;
    Patient * largestChild(Patient* parent);
    void swapPatientsByIndex(int indChild, int indParent);
    void swapPatients(Patient *child, Patient* parent);
};
