#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "BST.h"

using namespace std;

int main(int argc, char* argv[]) {
    // File I/O
    ifstream in (argv[1]);
    ofstream out (argv[2]);

    // Process Input File
    string line, command, token;
    while (getline(in, line)) {
        try {
            // Process File Strings
            if (line.size() == 0) continue;
            istringstream iss(line);
            iss >> command;
            
            if (command == "INT") {
                // Process
            } else if (command == "STRING") {
                // Process
            } else if (command == "add") {
                iss >> token;

                // Process
            } else if (command == "remove") {
                iss >> token;

                // Process
            } else if (command == "clear") {
                // Process
            } else if (command == "size") {
                // Process
            } else if (command == "print") {
                // Process
            } else if (command == "find") {
                iss >> token;

                // Process
            } else if (command == "copy") {
                // Process
            } else if (command == "printcopy") {
                // Process
            } else if (command == "tree") {
                // Process
                // Extra Credit
            } else {
                out << endl;
            }
 

        } catch (string e) {
            out << "Error" << endl;
        }
    }

}