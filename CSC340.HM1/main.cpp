//  Author: Consuelo Jimenez
//  ID #  : 910073832
//  Assign: CSC340 Homework 1
//  Date  : February 6, 2015
//  Email : consuelo@mail.sfsu.edu
//  Copyright (c) 2015 Consuelo Jimenez. All rights reserved.

#include <iostream>
#include <vector>
#include <regex>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>


using namespace std;

vector<int> getLeastFreqLetter(string p);
void countWordFreq(string p);
void getMostFreqWord(string p);
unsigned int split(const string &txt, vector<string> &strs, char ch);


struct Word{
    string word;
    int count = 0;
};

int main() {
    string paragraph;
    //vector<int> leastLetter;
    //Read in a paragraph, "pragraph" and get the length of the lines.
    cout << "Please enter a paragraph: " << endl;
    getline(cin, paragraph);
    
    
    //Call functions and determine the specified values for all varibales
    vector<int> LFL = getLeastFreqLetter(paragraph);
    cout << "\nThe least frequent letters are/is : ";
    for(int i = 0; i < LFL.size(); i++){
        char c = LFL[i] + 'a';
        cout << " " << c << " ";
    }
    cout << endl;
    //countWordFreq(paragraph);
    //getMostFreqWord(paragraph);
    
        return 0;
}

vector<int> getLeastFreqLetter(string p){
    int LetterFreq[26];
    for( int i=0; i<26; i++) LetterFreq[i] = 0;       //Initialize array
    
    //Scan through input paragraph one letter at a time, increase frequency of letter as it scans along
    int asci;
    int min = 1000;
    vector<int> leastLetter;
    //int index =0;
    
    for(int i=0; i<p.length(); i++){
        if(!isalpha(p[i])){
            continue;
        }
        asci = tolower(p[i]) - 'a';
        LetterFreq[asci]++;
    }
    for(int j = 0; j<26; j++){
        
       // char c = j + 'a';
        //cout << c << " " << LetterFreq[j] << endl;
        
        if(LetterFreq[j] < min)
            min = LetterFreq[j];
    }
    cout << endl << "The minimum frequency is " << min << endl;
    for(int i = 0; i<26; i++){
        if(LetterFreq[i] == min) {
            leastLetter.push_back(i);
        }
    }
    
   // cout << "\nThe Least Frequent Letters are/is: ";
   // for(int k=0; k < leastLetter.size(); k++){
   //     char c = leastLetter[k] + 'a';
   //     cout <<  " " << c << " ";
   // }
    return leastLetter;

}


void countWordFreq(string p)
{
    }

void getMostFreqWord(string paragraph)
{
    

}

unsigned int split(const string &txt, vector<string> &strs, char ch)
{
    unsigned int pos = txt.find(ch);
    unsigned int initialPos = 0;
    strs.clear();
    
    // Decompose statement
    while (pos != string::npos) {
        strs.push_back(txt.substr(initialPos, pos - initialPos + 1));
        initialPos = pos + 1;
        
        pos = txt.find(ch, initialPos);
    }
    
    // Add the last one
    strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));
    
    return strs.size();
}
