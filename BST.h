#include "BSTInterface.h"

using namespace std;

template <typename T>

class BST : public BSTInterface <T> {
private:
    struct Node {
        T data; // Current node data
        T* left; // Data less than current node
        T* right; // Data greater than current node

        // Node constructor
        Node(T d) : data(d), left(NULL), right(NULL) {}
    };

public:
    BST() {}
    ~BST() {}
    
    // Return true if able to add node else return false
    bool addNode(const T&) {}
    
    // Return true when node is removed else return false
    bool removeNode(const T&) {}
    
    // Return true if tree is empty else return false
    bool clearTree() {}
    
    // Return a level order traversal of a BST as a string
    string toString() const {}

    // Delete all nodes from BST
    void clear(void) {}
 
    // Return the number of nodes in the BST
    size_t size(void) {}

    // Return "Found" if able to find not in BST else return "Not Found"
    string find(void) {}

};
 