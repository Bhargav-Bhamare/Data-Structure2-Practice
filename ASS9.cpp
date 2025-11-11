#include <iostream>
#include <fstream>
using namespace std;

//File Management using FStream package

int main() {
    // --- Write ---
    ofstream fout("data1.txt");
    fout << "Hello World!";
    fout.close();

    // --- Read ---
    ifstream fin("data1.txt");
    string s; 
    getline(fin, s);
    cout << "Read: " << s << endl;
    fin.close();

    // --- Update ---
    ofstream fout2("data1.txt", ios::app);
    fout2 << " This is updated.";
    fout2.close();

    // --- Copy ---
    ifstream src("data1.txt");
    ofstream dst("copy.txt");
    string line;
    while(getline(src,line)) dst << line << endl;
    src.close(); dst.close();

    // --- Merge ---
    ifstream f1("data1.txt"), f2("copy.txt");
    ofstream fmerge("merged.txt");
    while(getline(f1,line)) fmerge << line << endl;
    while(getline(f2,line)) fmerge << line << endl;
    f1.close(); f2.close(); fmerge.close();

    cout << "Operations Done!" << endl;
}
