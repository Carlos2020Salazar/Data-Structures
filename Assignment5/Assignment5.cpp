
#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

void display()
{
	cout << "======Main Menu=====" << endl;
	cout << "1. Enqueue word" << endl;
	cout << "2. Dequeue word" << endl;
	cout << "3. Print queue" << endl;
	cout << "4. Enqueue sentence" << endl;
	cout << "5. Quit" << endl;
}

int main() {

	Queue myQue(10);
	bool flag = true;

	while (flag) 
	{
		int option;
		string myWord;

		string mySent;
		stringstream stream;
		display();
		cin >> option;

		switch (option) 
		{
		case 1:
			string S;
			cout << "myWord: ";
			cin >> S;
			getline(S, myWord);
			myQue.enqueue(myWord);
			break;

		case 2:
			myWord = myQue.dequeue();
			break;

		case 3:
			myQue.printQueue();
			break;

		case 4:
			string S;
			cout << "mySent: ";
			cin >> S;
			getline(S, mySent);
			stream << mySent;
			while (getline(ss, myWord, ' ')) 
			{
				myQue.enqueue(myWord);
			}
			break;

		case 5:
			cout << "Goodbye!" << endl;
			flag = false;
			break;

		default:
			break;
		}
	}
return 0;
}
