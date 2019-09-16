#include <iostream>
#include <queue>
#include "priorityQueueLL.h"

using namespace std;

EmergencyRoom::EmergencyRoom(){}
EmergencyRoom::~EmergencyRoom(){}

void EmergencyRoom::addArray(patient toAdd, int numElements)
{
	patientData[numElements] = toAdd;
}
swap

void EmergencyRoom::printArray()
{
	for (int i = 0; i < 880; i++) 
	{
		cout << "Name: " <<  patientData[i].name << " " << "Priority: " << patientData[i].priority << " " << "Treatment Time: " << patientData[i].treatment << endl;
 	}
}

void EmergencyRoom::insertLL(string name, int priority, int treatment)
{
	patientLL *current = head;
	patientLL *temp = new patientLL(name, priority, treatment);

	if (head == NULL)
	{
		head = temp;
	}
	 else 
	 {
		//insert new node before head
		if (*head > *temp)
		{
			temp->next = head;
			head = temp;
		}
		//traverse list and find a new position to enter it
		else
		{
			while(current->next != NULL && *current->next < *temp)
			{
				current = current->next;
			}

			//at end of list or position 
			temp->next = current->next;
			current->next = temp;
		}
	}
}

void EmergencyRoom::buildLL(int numTimes)
{
	for (int i = 0; i < numTimes; i++)
	{
		string name = patientData[i].name;
		int priority = patientData[i].priority;
		int treatment = patientData[i].treatment;
		insertLL(name, priority, treatment);
	}
}
void EmergencyRoom::deleteLL()
{
	patientLL *current = head;
	while(current != NULL)
	{
		patientLL *deleteNode = current;
		current = current->next;
		delete deleteNode;
	}
	head = NULL;
}


void EmergencyRoom::printLL()
{
	patientLL *current = head;
	while (current != NULL)
	{
		cout << "Patient Name:" << current->name << endl;
		cout << "Priority:" << current->priority << endl;
		cout << "Treatment Time:" << current->treatment << endl;
		current = current->next;
	}
};
struct patientLL{
	string name;
	int priority;
	int treatment;
	patientLL *next;

	patientLL(){};

	patientLL(string initName, int initPriority, int initTreatment)
	{
		name = initName;
		priority = initPriority;
		treatment = initTreatment;
		next = NULL;
	};
	bool operator<(const patientLL & p)const{
			if( this->priority < p.priority ) return true;
			else if( this->priority > p.priority ) return false;
			else if( this->treatment < p.treatment ) return true;
			return false;
	}
	bool operator>(const patientLL & p)const{
			if( this->priority > p.priority ) return true;
			else if( this->priority < p.priority ) return false;
			else if( this->treatment > p.treatment ) return true;			
			return false;
	}	
};
