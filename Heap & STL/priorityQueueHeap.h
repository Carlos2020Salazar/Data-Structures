#ifndef PRIORITYQUEUEHEAP_H
#define PRIORITYQUEUEHEAP_H
#include <iostream>
struct Patient
{
    string name;
    int priority;
    int Treatment;
};
class QueueBH
{
    public:
        QueueBH(int);
        ~QueueBH();     
        void push(Patient);
        Patient pop();  
    private:
    	Patient *arr;
		int capacity;
		int heapSize;
		void heapify(int);
		int right(int);
        int parent(int);
        int left(int);
        

};
#endif 