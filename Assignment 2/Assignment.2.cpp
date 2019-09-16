//Carlos Salazar
//Hoenigman 10am
//Assignment: 2
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct Word 
{
  string word;
  int count;
};

// finds the correpsonding index of a word inside an array of 'Word' structs
int findIndex(Word *arrayOfWords, int lengthOfArray, string word) 
{
  int index = -1;
  for (int i = 0; i < lengthOfArray; i++) 
  {
    if (arrayOfWords[i].word == word) 
    {
      index = i;
      break;
    }
  }
  return index;
}

//will double array logic
void doubleWordArraySize(Word **arrayOfWords, int *currentSize, int *timesDoubled) 
{
  int desiredSize = *currentSize * 2;
  Word *doubledArray = new Word[desiredSize];
  for (int i = 0; i < *currentSize; i++) 
  {
    doubledArray[i] = (*arrayOfWords)[i];
  }
  delete [] (*arrayOfWords);
  *currentSize = desiredSize;
  *arrayOfWords = doubledArray;
  *timesDoubled = *timesDoubled + 1;
}

// determines whether or not word is to be counted
bool isStopWord(string word)
{
  bool status = true;

  string badWordList[51] = {"the", "be", "to", "of", "and", "a", "in", "that",
    "have", "i", "it", "for", "not", "on", "with", "he",
    "as", "you", "do", "at", "this", "but", "his", "by",
    "from", "they", "we", "say", "her", "she", "or", "an",
    "will", "my", "one", "all", "would", "there", "their",
    "what", "so", "up", "out", "if", "about", "who",
    "get", "which", "go", "me", ""};
  
  for (int j = 0; j < 51; j++) 
  {
    if (badWordList[j] == word) 
    {
      status = false;
      break;
    }
  }

  return status;
}

// Reads the file, will filter through the lines/spaces
// Determines if word is already present in the given; increment if found
// otherwise add it to array
void populateWordArray(Word **arrayOfWords, int *lengthOfArray, int *lengthUsed, string filename, int *timesDoubled, int *total) 
{
  ifstream myFile;
  myFile.open(filename, ifstream::in);
  string currentLine;
  while(getline(myFile, currentLine)) 
  {
    stringstream ss_Line(currentLine);
    string currentWord;
    while(getline(ss_Line, currentWord, ' '))
    {
      if (isStopWord(currentWord))
      {
        int indexWord = findIndex(*arrayOfWords, *lengthOfArray, currentWord);
        if (*lengthUsed == *lengthOfArray)
        {
          doubleWordArraySize(arrayOfWords, lengthOfArray, timesDoubled);
        }
        if (indexWord == -1)
        {
          Word curr_Word;
          curr_Word.word = currentWord;
          curr_Word.count = 1;
          (*arrayOfWords)[*lengthUsed] = curr_Word;
          *lengthUsed = *lengthUsed + 1;
        } 
        else 
        {
          
          (*arrayOfWords)[indexWord].count++;
        }
        *total = *total + 1;
      }
    }
  }
}

// Will use insertion for sort
void arraySort(Word *arrayOfWords, int length) 
{
  int a;
  int Index = length;
  Word temp;
  for (int i = 0; i < Index; i++) 
  {
    a = i;
    while (a > 0 && arrayOfWords[a].count > arrayOfWords[a-1].count) 
    {
      temp = arrayOfWords[a];
      arrayOfWords[a] = arrayOfWords[a-1];
      arrayOfWords[a-1] = temp;
      a--;
    }
  }
}

// prints words based on spec format
void printTopN(Word *arrayOfWords, int topN) 
{
  for(int i = 0; i < topN; i++) 
  {
    cout << arrayOfWords[i].count << " - " << arrayOfWords[i].word << endl;
  }
}

int main(int argc, char *argv[])
{
  string filename = argv[2];
  int top_Words = stoi(argv[1]);
  int arraySize = 100;
  int total = 0;
  int length = 0;
  int timesDoubled = 0;
  int *lengthUsedPointer = &length;
  int *arraySizePointer = &arraySize;
  int *timesDoubledPointer = &timesDoubled;
  int *totalPointer = &total;
  Word *arrayOfWords = new Word[arraySize];
  populateWordArray(&arrayOfWords,arraySizePointer, lengthUsedPointer, filename, timesDoubledPointer, totalPointer);
  arraySort(arrayOfWords, length);
  printTopN(arrayOfWords, top_Words);
  cout << "#" << endl << "Array doubled: " << timesDoubled << endl;
  cout << "#" << endl << "Unique non-common words: " << length << endl;
  cout << "#" << endl << "Total non-common words: " << total << endl;
}