#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ofstream f1;
    f1.open("original.txt");

    if (f1.is_open()) {
        f1 << "One\n";
        f1 << "Two\n";
        f1 << "Three\n";
        f1 << "Four\n";
        f1 << "Five\n";
        f1 << "Six\n";
        cout << "The original.txt file created successfully.\n";
    } else {
        cout << "Error writing file\n";
        return 0;
    }

    f1.close();

    ifstream f2;
    f2.open("original.txt");

    if (!f2.is_open()) {
        cout << "Error reading file\n";
        return 0;
    }

    vector<string> list;
    string temp;

    while (!f2.eof()) {
        getline(f2, temp);
        if (temp != "") {
            list.push_back(temp);
        }
    }

    f2.close();

    sort(list.begin(), list.end());

    ofstream f3;
    f3.open("sorted.txt");

    if (!f3.is_open()) {
        cout << "Error creating sorted file\n";
        return 0;
    }

    for (int i = 0; i < list.size(); i++) {
        f3 << list[i] << endl;
    }

    cout << "The sorted.txt file created successfully!\n";

    f3.close();

    return 0;
}