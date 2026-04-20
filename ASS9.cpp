#include <iostream>
#include <fstream>

using namespace std;


// Function to write into file
void writeFile() {
    ofstream fout;

    // Open file
    fout.open("data1.txt");

    // Write data
    fout << "Hello World!";

    // Close file
    fout.close();
}

// Function to read from file
void readFile() {
    ifstream fin;

    // Open file
    fin.open("data1.txt");

    string content;

    // Read one line
    getline(fin, content);

    // Display content
    cout << "Read: " << content << endl;

    // Close file
    fin.close();
}

// Function to update file (append mode)
void updateFile() {
    ofstream fout;

    // Open file in append mode
    fout.open("data1.txt", ios::app);

    // Append data
    fout << " This is updated.";

    // Close file
    fout.close();
}

// Function to copy file content
void copyFile() {
    ifstream sourceFile;
    ofstream destinationFile;

    // Open source and destination
    sourceFile.open("data1.txt");
    destinationFile.open("copy.txt");

    string line;

    // Copy line by line
    while (getline(sourceFile, line)) {
        destinationFile << line << endl;
    }

    // Close both files
    sourceFile.close();
    destinationFile.close();
}

// Function to merge two files
void mergeFiles() {
    ifstream file1, file2;
    ofstream mergedFile;

    // Open files
    file1.open("data1.txt");
    file2.open("copy.txt");
    mergedFile.open("merged.txt");

    string line;

    // Copy first file content
    while (getline(file1, line)) {
        mergedFile << line << endl;
    }

    // Copy second file content
    while (getline(file2, line)) {
        mergedFile << line << endl;
    }

    // Close all files
    file1.close();
    file2.close();
    mergedFile.close();
}

int main() {

    cout << "Performing File Operations..." << endl;

    // Step 1: Write
    writeFile();

    // Step 2: Read
    readFile();

    // Step 3: Update
    updateFile();

    // Step 4: Copy
    copyFile();

    // Step 5: Merge
    mergeFiles();

    cout << "All Operations Done Successfully!" << endl;

    return 0;
}