#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ofstream file1;
    file1.open("color.txt");

    if (file1.is_open()) {
        file1 << "Blue\n";
        file1 << "Indigo\n";
        file1 << "Pink\n";
        file1 << "Lime\n";
        file1 << "Red\n";
        cout << "File succesfully created.\n";
    } else {
        cout << "Error creating file!\n";
        return 0;
    }

    file1.close();

    ifstream file2;
    file2.open("color.txt");

    ofstream file3;
    file3.open("color_copy.txt");

    if (!file2.is_open() || !file3.is_open()) {
        cout << "Error opening the files!\n";
        return 0;
    }

    string data;

    while (!file2.eof()) {
        getline(file2, data);
        if (data != "") {
            file3 << data << endl;
        }
    }

    cout << "File successfully copied!.\n";

    file2.close();
    file3.close();

    return 0;
}