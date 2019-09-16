#include <iostream>
#include <string>
#include <sstream>
#include "Queue.h"

using namespace std;


Queue::Queue(int size) 
{
  queueSize = size;
  queueHead = 0;
  queueTail = 0;
  queueCount = 0;
  arrayQueue = new string[queueSize];
}
Queue::~Queue(){}

void Queue::enqueue(string value)
{
	if (queueIsFull())
	{
		cout << "Queue is full." << endl;
		return;
	}
	arrayQueue[queueTail] = value;
	queueCount++;
	queueTail++;
	if (queueTail >= queueSize) 
	{
		queueTail = 0;
	}
	cout << "E: " << value << endl;
	cout << "H: " << queueHead << endl;
	cout << "T: " << queueTail << endl;
	return;
}

void Queue::enqueueSentence(string sentence)
{
  stringstream stream(sentence);
  string myString;
  while(getline(stream, myString, ' ')) 
  {
    enqueue(myString);
  }
}

void Queue::dequeue()
{
  if (queueIsEmpty()) 
  {
    cout << "Queue is empty." << endl;
    return;
  }
  string myString = arrayQueue[queueHead];
  arrayQueue[queueHead];
  queueCount--;

  if (queueHead == queueSize - 1) 
  {
    queueHead = 0;
  }

  else 
  {
    queueHead++;
  }
  cout << "H: " << queueHead << endl;
  cout << "T: " << queueTail << endl;
  cout << "word: " << myString << endl;
}

void Queue::printQueue()
{
	if (queueIsEmpty())
	{
		cout << "Empty" << endl;
		return;
	}
	int count =	queueHead;
	for (int i = 0; i < queueCount; i++)
	{
		cout << count << ": " << arrayQueue[count] << endl;
		count++;
		if (count >= queueSize)
		{
			count = 0;
		}
	}
	return;
}

bool Queue::queueIsFull()
{
  return (queueCount == queueSize);
}


bool Queue::queueIsEmpty()
{
	return queueCount == 0;
}


