
#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>


using namespace std;
struct Word{
string word;
int count;
};

vector<int> getLeastFreqLetter(string p);
std::vector<Word> countWordFreq(string p);

void getMostFreqWord(vector<Word> w);
unsigned int split(const string &txt, vector<string> &strs, char ch);

int main() {
vector<Word> w;
string paragraph;
//Read in a paragraph and get the length of the lines.
cout << "Please enter a paragraph: " << endl;
getline(cin, paragraph);


//Call functions and determine the specified values for all varibales
vector<int> LFL = getLeastFreqLetter(paragraph);
cout << "\nThe least frequent letters are/is : ";

for (int i = 0; i < LFL.size(); i++){
	char c = LFL[i] + 'a';
	cout << " " << c << " ";
}
cout << endl;
w = countWordFreq(paragraph);
getMostFreqWord(w);

system("pause");

return 0;
}

vector<int> getLeastFreqLetter(string p)
{
int LetterFreq[26];
for (int i = 0; i<26; i++) LetterFreq[i] = 0;       //Initialize array

//Scan through input paragraph one letter at a time, increase frequency of letter as it scans along
int asci;
int min = 1000;
vector<int> leastLetter;

//Iterate through p.length and grab all non whitespace letters 
for (int i = 0; i<p.length(); i++){
	if (!isalpha(p[i])){
	continue;
}
asci = tolower(p[i]) - 'a';      //Convert to ascii code 
LetterFreq[asci]++;              //Incemenct frequency of letter 
}
for (int j = 0; j<26; j++){

if (LetterFreq[j] < min)        //Sort the vector and determine minimum 
	min = LetterFreq[j];
}

cout << endl << "The minimum frequency is " << min << endl;
//For all the letters equal to the minimum store them into a vector to be returned to main. 
for (int i = 0; i<26; i++){
	if (LetterFreq[i] == min) {
		leastLetter.push_back(i);
	}
}

return leastLetter;
}


std::vector<Word> countWordFreq(string p){

vector<string> stringThatWasSplit;
vector <Word> vecOfWords;
split(p, stringThatWasSplit,' ');

//Strip whitespace from words calling remove function 
for (int i = 0; i < stringThatWasSplit.size(); i++) {
    remove(stringThatWasSplit[i].begin(), stringThatWasSplit[i].end(),' ');
}
//Iterate along vector and create temp struct Word and set current word 
for (int i = 0; i < stringThatWasSplit.size(); i++)
{
    if (stringThatWasSplit[i] != "")
    {
        Word tempW;
        tempW.word = stringThatWasSplit[i];
        tempW.count = 0;
  //Compare if word is equal to tempW and if they are equal increment the count.      
    for (int j = 0; j < stringThatWasSplit.size(); j++)
    {
        if (stringThatWasSplit[j].compare(tempW.word) == 0)
        {
        tempW.count++;
        stringThatWasSplit[j] = "";     //Sets word to zero so that it is not recounted. 
        }
    }
    vecOfWords.push_back(tempW);        //Add new unique word to vector 
	}
}
//iterate through our vector of words and print frequency or each.
for (int i = 0; i < vecOfWords.size(); i++)
{
    cout << "Word: " << vecOfWords.at(i).word << "   Frequency: " << vecOfWords.at(i).count << endl;
}
return vecOfWords;
}

void getMostFreqWord(vector<Word> w)
{
	int large = w[0].count;
	int index = 0;
	for(int i = 0; i < w.size(); i++)
	{
		if(w[i].count > large)
		{
			large = w[i].count;
			index = i;
		}
	}
	cout << "Largest Frequency: " << large << "   Word: " << w[index].word << endl; 
}

//Split the string into words. 
unsigned int split(const string &txt, vector<string> &strs, char ch)
{
unsigned int pos = txt.find(ch);
unsigned int initialPos = 0;
strs.clear();

// Decompose statement
while (pos != string::npos)
{
strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
initialPos = pos + 1;

pos = txt.find(ch, initialPos);
}

// Add the last one
strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

return strs.size();
}
