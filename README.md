# Hartnett_CSCI2270_FinalProject
My project will use a priority queue to create an example interface for a hospital. My prioriy queue class will let you add a new patient, using a struct to store the patient data, and allow you to find the next patient to be treated, based off of the order of arrival and the urgency of the injury. The main file will have options to add a new patient, find the next patient to be treated, list the waiting patients, list the patients that have passed through the hospital, and delete patients, amoung others. 

I will implement this using a priority queue in the form of a heap. This will allow me to organize the patients by urgency and by the order of their arrival. 

I found information on heaps and priority queues here:
http://pages.cs.wisc.edu/~vernon/cs367/notes/11.PRIORITY-Q.html


Menu Options:

1. Enter a new patient
2. Print patients
3. Get Next patient to be treated (highest urgency in the heap)
4. Remove a patient
6. Edit a patient- Basically delete and re-enter a patient in one menu option
7. Quit


##TO RUN PROGRAM (in VM):

1. in terminal, enter
"git clone https://github.com/ceilingcranes/Hartnett_CSCI2270_FinalProject"

2. Navigate to the main directory ( /Hartnett_CSCI2270_FinalProject )

3. Compile by typing into the terminal
"g++ -std=c++11 Final.cpp PQueue.cpp"

4. Run by typing into the terminal 
"./a.out"

5. Type a number and hit enter to select the menu options.


To run program in general: Clone the respository, then compile and run as you would any c++ program.

Dependencies: None

System Requirements: Only tested on linux, should work on any OS that can run and compile the assignments 

Group Members: Maxine Hartnett

Contributors: None

Open bugs/issues: There may be a bug when entering a new patient that causes and infinite loop, but I haven't been able to replicate it, and it was several versions ago.

Enhancement request: Find a more reliable way of identifying patients than name- such as a unique identifying number - and when searching for a patient with that name, if there are multiple, confirm the patient.
I also have some structuring for adding speciality doctors, so that you could pull the next patient assigned to that doctor, but that's no where close to being finished- it's more something I implemented in case I had time to add the funtionality.


**Please let me know if you encounter any errors!**

