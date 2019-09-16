#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <queue>
#include "priorityQueueLL.h"
using namespace std;

int main(int argc, char *argv[]) 
{
	EmergencyRoom ERpatient; //object for class
	string myString;
	string input;
	int numLines = 0;
	bool running = true;

	//read in the file 
	ifstream inFile;
	inFile.open(argv[1]); //read csv file
	getline(inFile, myString, '\r');

	while(getline(inFile, myString, '\r'))
	{
		stringstream ss(myString);
		string name;
		string strPriority;
		string strTreatment;
		getline(ss, name, ',');
		getline(ss, strPriority, ',');
		getline(ss, strTreatment, ',');
		int priority = stoi(stringPriority); //convert the strings to integers
		int treatment = stoi(stringTreatment);
		patient toAdd = patient(name, priority, treatment);
		ERpatient.addArray(toAdd, numLines);
		numLines++;
	}
	//ERpatient.printArray(); viewing the array that will be list
	clock_t t1, t2;
	t1 = clock();
	ERpatient.buildLL(880);
	t2 = clock();
	cout << " |  LL Enqueue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;
	ERpatient.printLL();
	cout << "Goodbye!" << endl;	

	
	clock_t t3, t4;
	t3 = clock();
	ERpatient.deleteLL();
	t4 = clock();
	cout << " |  LL Dequeue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;
}



