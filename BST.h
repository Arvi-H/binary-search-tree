#include "BSTInterface.h"

using namespace std;

template <typename T>

class BST : public BSTInterface <T> {
private:
    struct Node {
        // Current node data
        T data;

        // Data less than current node
        T* left;

        // Data greater than current node
        T* right;

        // Node constructor
        Node(T d) : data(d), left(NULL), right(NULL) {}
    };

};
 