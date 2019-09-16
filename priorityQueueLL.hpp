#ifndef PRIORITYQUEUELL_H
#define PRIORITYQUEUELL_H
#include <iostream>
//#include <queue>
struct patient
{
	string name;
	int priority;
	int treatment;
	patient(string n, int p, int t) : name(n), priority(p), treatment(t) {};
	patient(): name(""), priority(-1000), treatment(-1000) {};

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
		if(this) {
			if( this->priority < p.priority ) return true;
			else if( this->priority > p.priority ) return false;
			else if( this->treatment < p.treatment ) return true;
		}
		return false;
	}
	bool operator>(const patientLL & p)const{
		if(this) {
			if( this->priority > p.priority ) return true;
			else if( this->priority < p.priority ) return false;
			else if( this->treatment > p.treatment ) return true;			
		}
		return false;
	}	
};
class EmergencyRoom {
	public:
		EmergencyRoom();
		~EMergencyRoom();
		void addArray(patient toAdd, int numElements);
		void printArray();
		void buildLL();
		void insertLL(string name, int priority, int treatment);
		void printLL():
		void deleteLL();
	private:
	//patient patientData[880]; //Heap not compile

 };