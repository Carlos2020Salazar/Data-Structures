//Carlos Salazar
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;


struct word_Item
{
    string word;
    int count;
};

int Split(string str_1, char seperator, word_Item words[], int array_size)
{
    string words_1 = "";
    int count = 0;
    if(str_1 == "")
    {
        return 0;
    }
    for(int i = 0; i < str_1.length(); i++)
    {
        if(str_1[i] == seperator)
        {
           words[count].word = words_1;
           count++;
           words_1 = "";
        }
        else
        {
            words_1 += str_1[i];
        }
    }
    words[count].word =  words_1;
    return count+1;
}
void getStopWords(char *ignoreWordFileName, string ignoreWords[])
{
    ifstream myFile;
    string line;
    int count = 0;
    myFile.open(ignoreWordFileName);
    if(myFile.is_open())
    {
        while(!myFile.eof())
        {
            getline(myFile,line);
            ignoreWords[count] = line;
            count++;
 
 
        }
 
 
    }
}
bool isStopWord(string word, string ignoreWords[])
{
    bool flag;
    for(int i = 0; i < 50; i++)
    {
        if(word == ignoreWords[i])
        {
            flag = true;
            break;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
 
}
int getTotalNumberNonStopWords(word_Item list[],int numberOfUniqueWords)
{
    int count;
    for(int i = 0; i < numberOfUniqueWords; i++)
    {
        if(list[i].word != '')
        {
            count++;
        }
    }
    return count;
}

void arraySort(word_Item list[], int length)
{
    for(int i = 0;i < length-1; i++)
    {
        for(int j = 0;j < length-i-1; j++)
        {
            if(list[j].count > list[j+1].count)
            {
                int swap = list[j].count;
                list[j].count = list[j+1].count;
                list[j+1] = swap;
            }
        }
    }
 
 
 
}
void printTopN(word_Item wordItemList[],int topN)
{
    for(int i=length;i<length-topN;i++)
    {
        cout<<wordItemList[i].word;
    }
 
}
int main(int argc, char *argv[])
{
    word_Item text[100];
    ifstream myFile;
    string line;
    myFile.open(argv[1]);
    if(myFile.is_open())
    {
        while(getline(myFile,line))
        {
 
            Split(line,' ',text,100);
 
 
        }
    }
 
}