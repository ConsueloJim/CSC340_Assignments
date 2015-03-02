#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>


using namespace std;

void merge_files(string file1_name, string file2_name);

int main() {
    string file1_name;
    string file2_name;

    cout << "Enter the name of the file to be merged into : ";
    cin >> file1_name;
    cout << "\nEnter the name of the file to be merged : ";
    cin >> file2_name;

    merge_files(file1_name, file2_name);


    return 0;
}

void merge_files(string file1_name, string file2_name){

    string  num1, num2;

    ifstream file1,file2;
    ofstream write_file;

    write_file.open("merge.txt", ios::out);
    file1.open(file1_name, ios::in);
    file2.open(file2_name, ios::in);

    while(file1 >> num1 && file2 >> num2)
    {
        cout << num1 << " " << num2 << endl;
        if(num1 <= num2)
        {
            write_file << num1 << "\n";
            write_file << num2 << "\n";
        }
        else { write_file << num2 << "\n"; write_file << num1 << "\n";}
    }
    file1.close();
    file2.close();
    write_file.close();

}
