#include "priorityQueueHeap.h"
#include <time.h>
#include <queue>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void test(Patient *data[], int index);
 
int main(int argc, char* argv[])
{
	ifstream myFile;
	std::string myLine;
	Patient *data[880];
	int index = 0;
	myFile.open(argv[1]); 
	if (myFile.is_open()) 
	{
		cout << "opened successfully" << endl;
		string header;
		getline(myFile,header,'\r');
		while(getline(myFile,myLine,'\r'))
		{
			string data_;
			stringstream ss(myLine);
			Patient * temp = new Patient;
			for(int i = 0; i < 3; i++)
			{
				if(i == 0)
				{
					getline(ss,data_,',');
					temp->name = data_;
				}
				else if(i == 1)
				{
					getline(ss,data_,',');
					temp->priority = stoi(data_);
				}
				else if(i == 2)
				{
					getline(ss,data_);
					temp->operationTime = stoi(data_);
				}
			}
			data[index] = temp;
			index++;
		}
		for(int size = 100; size <= 800; size += 100)
		{

			int r = rand()%(index-size);
			Patient * temp[size];
			for(int i = 0; i < size; i++)
			{
				temp[i] = data[i+r];
			}
			test(temp,size);

		}

	}

	return 0;
}



void test(Patient *data[], int index)
{
	QueueBH *q2 = new QueueBH(880); //
	priority_queue <Patient, vector<Patient>,compare> pq;
	for(int j = 0; j < 500; j++)
	{
		clock_t t1, t2;
	    t1 = clock();
		for( int i = 0; i < index; i++)
		{
			q2->push(*data[i]);

		}
		t2 = clock();
		cout << " |  BH Enqueue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

		t1 = clock();
		for( int i=1; i<index;i++)
		{
			q2->pop();
		}
		t2 = clock();
		cout << " |  BH Dequeue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

		t1 = clock();
		for( int i=1; i<index;i++)
		{
			pq.push(*data[i]);
		}
		t2 = clock();
		cout << " | STL Enqueue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

		t1 = clock();
		for( int i = 0; i < index; i++)
		{
			pq.pop();
		}
		t2 = clock();
		cout << " | STL Dequeue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;

	}

}