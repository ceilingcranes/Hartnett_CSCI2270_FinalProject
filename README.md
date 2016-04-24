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

