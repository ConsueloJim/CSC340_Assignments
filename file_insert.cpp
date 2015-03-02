#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <istream>
#include <queue>

using namespace std;


int main() {


    queue<string> storeNums;
    string str1;
    fstream file;

    file.open("file1.txt", ios::in | ios::out);
    int pos = 0;
    if(file.fail()){
        cerr << "Failed to open file : " << "file1.txt" << endl;
    }

    file.seekg(30000);

    while(!file.eof()) {
       file >> str1;
       storeNums.push(str1);
    }
    file.clear();
    pos = file.tellg();
    file.seekp(pos);

    for(int i=7777; i < 7782; i++){
       file << i << endl;

    }

   for(int i=0; i < storeNums.size(); i++){
       file << storeNums.front() << endl;
       storeNums.pop();
    }

 // file.clear();
 // file.seekp(0, file.beg);
  file.close();

 return 0;
}
