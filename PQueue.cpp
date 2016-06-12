#include "PQueue.h"

PQueue::PQueue(){
    //std::cout << "Creating new queue" << std::endl;
    arraySize = 10;
    patientArray=new Patient*[arraySize]; //set to ten
    for(int i=0; i< arraySize; i++)
        patientArray[i]=NULL;

}

PQueue::~PQueue(){
    for(int i=0; i< arraySize; i++){
        if(patientArray[i]!=NULL){
            delete patientArray[i];
        }
    }
   // std::cout << "Deleted Values!" << std::endl;

}

void PQueue::printPatients(){
    for(int k=0; k < arraySize; k++){
        if(patientArray[k]!=NULL){
            printPatientPointer(patientArray[k]);
        }
        //else
           // std::cout << "patientArray[" << k << "]: NULL" << std::endl;
    }

}

void PQueue::printArray(){
    for(int k=0; k < arraySize; k++){
        if(patientArray[k]!=NULL){
            std::cout << "patientArray[" << k << "]: " << patientArray[k]->name;
            std::cout <<", urgency: " << patientArray[k]->urgency << std::endl;
        }
        else
            std::cout << "patientArray[" << k << "]: NULL" << std::endl;
    }

}


void PQueue::printPatientData(std::string name){
        Patient * p = findPatient(name);
        if(p==NULL){
            std::cout<< "Patient not found." << std::endl;
        }
        else{
            printPatientPointer(p);
        }
}

void PQueue::printPatientPointer(Patient * p){
    std::cout << "^^^^^^^^^^^^^^" << std::endl;
    std::cout << "Patient Name: " << p->name << std::endl;
    std::cout << "Urgency: " << p->urgency << std::endl;
    //std::cout << "Specialist: " << p->specialist << std::endl;
    std::cout << "Notes: " << p->notes << std::endl;
    std::cout << "^^^^^^^^^^^^^^" << std::endl;
}

void PQueue::insertNewPatient(std::string name, int urgency, std::string notes){
    Patient* p=new Patient(name, urgency, notes);
    //std::cout << "New patient: " << p->name << std::endl;
    Patient* prevP=patientArray[1]; //the root of the heap
    int index=1;
    if(prevP==NULL){
        //std::cout << "Root" << std::endl;
    }
    while(prevP!=NULL&&index<arraySize){
        index++;

        prevP=patientArray[index];
    }

    //std::cout << "Index: " << index << std::endl;

    //Index is now equal to the next empty spot in the array.
    if(index==1){ //heap is empty
        patientArray[index] = p;
        p->parent=NULL;
        p->left=NULL;
        p->right=NULL;
    }
    else{
        if(index == arraySize){
            doubleArray();
        }
        patientArray[index]=p;
        Patient *parent=patientArray[index/2];
        if(parent->left==NULL){
            parent->left=p;
        }
        else if(parent->right==NULL){
            parent->right=p;
        }
        else{
            std::cout << "Error finding parent!" << std::endl;
        }
        p->parent=parent;
        p->left=NULL;
        p->right=NULL;
        if(parent!=NULL){
            //std::cout << "Parent: " << parent->name << std::endl;
        }
        //else
            //std::cout << "Parent is null. Parent index: " << index/2 <<std::endl;
        //to maintain heap properties: The parent has to have higher urgency

        while(parent!=NULL&&parent->urgency < p->urgency){
            /*std::cout << "Parent: " << parent->name << " Parent urgency: " <<parent->urgency << ", child urgency: " << p->urgency << std::endl;

            std::cout << "Swapping" << std::endl;
            std::cout << "indChild: " << index << " indParent: " << index/2 << std::endl;
            std::cout << "Child: " << p->name << " Parent: " << parent->name << std::endl;*/

            swapPatientsByIndex(index, index/2);
            if(p->parent!=NULL){
                parent=p->parent;
                //std::cout << "Setting new parent to " << parent->name << std::endl;
            }
            else
                parent=NULL;
        }



    }
    /*for(int k=0; k < arraySize; k++){
        if(patientArray[k]!=NULL)
            std::cout << "patientArray[" << k << "]: " << patientArray[k]->name << std::endl;
        else
            std::cout << "patientArray[" << k << "]: NULL" << std::endl;
    }*/

}


//Will swap the two patients within the array- used for maintaining heap rules
void PQueue::swapPatients(Patient* child, Patient* parent){
    int ch=-1, pa=-1;
    for(int i=0; i< arraySize; i++){
        if(patientArray[i]==child){
            ch=i;
        }
        if(patientArray[i]==parent){
            pa=i;
        }
    }
    if(ch==-1||pa==-1){
        std::cout << "One or both not found in swapPatients" << std::endl;
    }
    else{
        swapPatientsByIndex(ch, pa);
    }

}

//will swap two elements in the array at indexes indChild and indParent
void PQueue::swapPatientsByIndex(int indChild, int indParent){
    //std::cout << "Starting swap" << std::endl;
    Patient * child=patientArray[indChild];
    Patient * parent=patientArray[indParent];
    if(child==NULL){
        std::cout << "Child null" << std::endl;
    }
    if(parent==NULL){
        std::cout << "Parent null" << std::endl;
    }
    //std::cout << "parent: " << parent->name << " child: " << child->name << std::endl;
    Patient *otherChild;
    bool left=false;
    if(parent->left==child){
        //std::cout << "child to left" << std::endl;
        otherChild=parent->right;
        left=true;
    }
    else{
        otherChild=parent->left;
    }
    //std::cout << "Setting parents" << std::endl;
    child->parent=parent->parent;
    if(parent->parent!=NULL){
        if(parent->parent->left==parent)
            parent->parent->left=child;
        else
            parent->parent->right=child;
    }
    parent->parent=child;
    //std::cout << "Parents set" << std::endl;
    if(child->left!=NULL)
        child->left->parent=parent;
    if(child->right!=NULL)
        child->right->parent=parent;
    parent->left=child->left;
    parent->right=child->right;
    //std::cout << "Children set" << std::endl;
    if(otherChild!=NULL)
        otherChild->parent=child;
    if(left){
        child->left=parent;
        child->right=otherChild;
    }
    else{
        child->right=parent;
        child->left=otherChild;
    }
    //std::cout << "Setting in array" << std::endl;
    patientArray[indChild]=parent;
    patientArray[indParent]=child;
    //std::cout << "Swapped " << parent->name << " with " << child->name << std::endl;


}


//Will return the patient with the greatest urgency, and remove it from the queue.
Patient * PQueue::pop(){
    Patient * nextP = patientArray[1]; //the root of the array, the patient with max urgency
    if(nextP==NULL){
        //std::cout << "Queue empty (pop)" << std::endl;
        return NULL;
    }
    int i=deletePatient(nextP, 1);
    if(i==0){
        //std::cout << "Successfully deleted" << std::endl;
    }

    return nextP;

}

//Deletes patient nextP at indexToDelete
//returns 0 if successful, 1 otherwise
int PQueue::deletePatient(Patient * nextP, int indexToDelete){
    if(indexToDelete > arraySize){
        std::cout << "Error: Index greater than array size" << std::endl;
        return 1;
    }
    Patient * endOfArray=patientArray[1];
    int i=1;
    while(patientArray[i+1]!=NULL&&i<arraySize){
        i++;
        endOfArray=patientArray[i];
    }

    //std::cout << "End of array: " << endOfArray->name <<std::endl;
    if(i!=1){ //if there is more than one element in the heap

        patientArray[indexToDelete]=endOfArray;
        patientArray[i]=NULL;
        //std::cout << "Setting array at " << i << " to null. " << std::endl;
        if(endOfArray->parent->left==endOfArray){
            endOfArray->parent->left=NULL;
        }
        else
            endOfArray->parent->right=NULL;
        endOfArray->left=nextP->left;
        if(endOfArray->left!=NULL){
            //std::cout << "new left child: " << endOfArray->left->name << std::endl;

        }
        else
            //std::cout << "Left child null." << std::endl;
        if(endOfArray->right!=NULL){
            //std::cout << "new right child: " << endOfArray->right->name << std::endl;

        }
       // else
            //std::cout << "Right child null." << std::endl;
        endOfArray->right=nextP->right;
        endOfArray->parent=nextP->parent;
        //If the new root has children that are higher urgency (Should always be true, basically)
        Patient * largerChild=NULL;
        largerChild= largestChild(endOfArray);

        while(largerChild!=NULL){
           // std::cout << "New Root: " << endOfArray->name << ", largest Child: " << largerChild->name << std::endl;
            if(largerChild->urgency > endOfArray->urgency){
                //std::cout << "Swapping " << endOfArray->name << " and " << largerChild->name <<std::endl;
                swapPatients(largerChild, endOfArray);
                largerChild = largestChild(endOfArray);
            }
            else{
                largerChild=NULL;
            }

        }

    }
    else{ //If there is only one patient in the array
        patientArray[1]=NULL;

    }


    return 0;

}
 //returns one if unsuccessful. Will delete a patient based off of a name.
int PQueue::removePatient(std::string name){
    Patient *p=NULL;
    int index=0;
    for(int i=0; i<arraySize; i++){
        if(patientArray[i]!=NULL && patientArray[i]->name == name){
            p=patientArray[i];
            index=i;
        }
    }
    if(p!=NULL){
        return deletePatient(p, index);
    }

    return 1;
}


Patient* PQueue::largestChild(Patient* parent){
    Patient* largerChild=NULL;
    if(parent->left!=NULL||parent->right!=NULL){

            if(parent->left!=NULL){
                if(parent->right!=NULL){
                    if(parent->left->urgency > parent->right->urgency) //the left is larger
                        largerChild = parent->left;
                    else
                        largerChild = parent->right;

                }
                else //If left exist and right is null
                    largerChild = parent->left;

            }
            else //If right exists and left is null
                largerChild = parent->right;

        }
    return largerChild;

}

void PQueue::doubleArray(){
    Patient ** temp=new Patient*[arraySize*2];
    for(int i=0; i<arraySize; i++){
        temp[i]=patientArray[i];

    }
    for(int k=arraySize; k<arraySize*2; k++){
        temp[k]=NULL;
    }
    delete[] patientArray;
    patientArray=temp;
    arraySize=arraySize*2;
    //std::cout << "Array doubled" << std::endl;

}

Patient * PQueue::findPatient(std::string name){
    Patient * p=NULL;
    for(int i=0; i<arraySize; i++){
        if(patientArray[i]!=NULL && patientArray[i]->name == name){
            p=patientArray[i];
        }
    }
    return p;

}


