#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "BST.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Binary Search Tree Pointers
    BST<int> *myIntBST = NULL;
    BST<int> *myIntBSTCopy = NULL;

    BST<string> *myStringBST = NULL;
    BST<string> *myStringBSTCopy = NULL;

    // File I/O
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    // ifstream in (argv[1]);
    // ofstream out (argv[2]);

    // BST Type
    string activeTreeType;

    // Process Input File
    for (string line; getline(in, line);) {
        string command, token;
        if (line.size() == 0) continue;

        istringstream iss(line);
        iss >> command;

        try { 
            out << command;

            if (command == "INT") {

                // Clear Old BST
                if (myIntBST != NULL) {
                    myIntBST->clearTree();
                }

                // Instantiate new BST
                myIntBST = new BST <int>;

                // Set treeType
                activeTreeType = "INT";

                out << " OK\n";
            } else if (command == "STRING") {
                // Clear Old BST
                if (myStringBST != NULL) {
                    myStringBST->clearTree();
                }

                // Instantiate new BST
                myStringBST = new BST <string>;
                
                // Set treeType
                activeTreeType = "STRING";

                out << " OK\n";
            } else if (command == "add") {
                iss >> token;
                out << " " << token;

                // Perform operations on the correct tree type
                if (activeTreeType == "INT") {

                    // Output OK if command is successful else output error
                    if (myIntBST->addNode(stoi(token))) {
                        out << " OK" << endl;
                    } else {
                        throw token;
                    }

                } else if (activeTreeType == "STRING") {
                    // Output OK if command is successful else output error
                    if (myStringBST->addNode(token)) {
                        out << " OK" << endl;
                    } else {
                        throw token;
                    }
                }
            } else if (command == "remove") {
                iss >> token;
                out << " " << token;

                // Perform operations on the correct tree type
                if (activeTreeType == "INT") {
                    // Output OK if command is successful else output error
                    if (myIntBST->removeNode(stoi(token))) {
                        out << " OK" << endl;
                    } else {
                        throw token;
                    }
                } else { 
                    // Output OK if command is successful else output error
                    if (myStringBST->removeNode(token)) {
                        out << " OK" << endl;
                    } else {
                        throw token;
                    }
                }

            } else if (command == "clear") {
                // Perform operations on the correct tree type
                if (activeTreeType == "INT") {
                    myIntBST->clearTree();
                    out << " OK" << endl;
                } else if (activeTreeType == "STRING") { 
                    myStringBST->clearTree();
                    out << " OK" << endl;
                }
            } else if (command == "size") {
                // Perform operations on the correct tree type
                if (activeTreeType == "INT") {
                    out << " " << myIntBST->size() << endl;
                } else if (activeTreeType == "STRING") { 
                    out << " " << myStringBST->size() << endl;
                }
            } else if (command == "print") {
                // Perform operations on the correct tree type
                if (activeTreeType == "INT") {
                    out << *myIntBST << endl;

                } else if (activeTreeType == "STRING") { 
                    out << *myStringBST << endl;
                }
            } else if (command == "find") {
                iss >> token;

                // Perform operations on the correct tree type
                if (activeTreeType == "INT") {
                    // Return "found" if node exists else return "not found"
                    if (myIntBST->find(stoi(token))) {
                        out << "found" << endl;
                    } else {
                        out << "found" << endl;
                    }
                } else if (activeTreeType == "STRING") { 
                    // Return "found" if node exists else return "not found"
                    if (myStringBST->find(token)) {
                        out << "found" << endl;
                    } else {
                        out << "found" << endl;
                    }
                }
            } else if (command == "copy") {
                // Perform operations on the correct tree type
                // if (activeTreeType == "INT") {
                //     myIntBST = myIntBSTCopy;
                // } else if (activeTreeType == "STRING") { 
                //     myStringBST = myStringBSTCopy;
                // }

                out << " OK" << endl;
            } else if (command == "printcopy") {
                // Perform operations on the correct tree type
                // if (activeTreeType == "INT") {
                //     out << myIntBSTCopy << endl;
                // } else if (activeTreeType == "STRING") { 
                //     out << myStringBSTCopy << endl;
                // }
            } else if (command == "tree") {
                // Process
                // Extra Credit
            } else {
                out << endl;
            }
 
        } catch (string e) {
            out << " Error" << endl;
        }
    }

}