
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
struct patient
{
    public:
        string name;
        int priority;
        int treatment;
};
struct Comp
{
    bool operator()(const patient& a, const patient& b)
    {
        if(a.priority == b.priority)
        	return (a.treatment > b.treatment);
        else
        return (a.priority > b.priority);
    }
};
int main()
{
    patient list[880];
	ifstream myFile;
	myFile.open("patientData2270.csv");
	string ID;
	myFile.ignore(24,'\n');
	int k = 0;
	while(getline(myFile, ID, '\r')) 
	{
		stringstream ss(ID);
		string name;
		string stringPriority;
		string stringTreatment;
		getline(ss, name, ',');
		getline(ss, stringPriority, ',');
		getline(ss, stringTreatment, ',');
		list[k].name = name;
		list[k].priority = stoi(stringPriority);
		list[k].treatment = stoi(stringTreatment);
		k++;
	}
	priority_queue< patient, vector<patient>, Comp> pq;

	clock_t t1,t2;
	t1 = clock();
	for(int i = 0; i < 880; i++)
	{
		pq.push(list[i]);
	} //Will be highest priority
	t2 = clock();
	cout << "STL Enqueue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << "s" <<endl;
	patient Priority= pq.top();  
	cout << Priority.name << " " << Priority.priority << " " << Priority.treatment << endl;
	t1 = clock();
	for( int i = 0; i < 880; i++)
	{
		pq.pop();
	}
	t2 = clock();
	cout << "STL Dequeue time: " << ((float)t2-(float)t1) / CLOCKS_PER_SEC << " s" << endl;
      //result is Angelina
    return 0;
}
