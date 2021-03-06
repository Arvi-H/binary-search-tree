#include "BSTInterface.h"

using namespace std;

template <typename T>

class BST : public BSTInterface <T> {
private:
    struct Node {
        T data; // Current node data
        Node* left; // Data less than current node
        Node* right; // Data greater than current node

        // Node constructors
        Node() : data(NULL), left(NULL), right(NULL) {}
        Node(T d) : data(d), left(NULL), right(NULL) {}
    };  

    // Root node of our tree. Pointers are initialized to NULL
    Node *root;
    bool duplicate = false;
    size_t treeSize = 0;

    // Return true if able to add node else return false
    Node* insertNode(Node *curr, const T& value) {
        
        // If tree doesn't have a root
        if (curr == NULL) {
            curr = new Node(value);
        
        // If value is gretaer than the current node
        } else if (value > curr->data) {
            curr->right = insertNode(curr->right, value);
        
        // If value is less than the current node
        } else if (value < curr->data) {
            curr->left = insertNode(curr->left, value);
        
        // If value is already in the tree
        } else if (value == curr->data) {
            duplicate = true;
        }

        return curr;
    }

    bool removeNode2(Node *&curr, const T& value) {
        // If current node is NULL
        if (curr == NULL) {
            return false;
        }

        // If value is greater than the current node
        if (value > curr->data) {
            return removeNode2(curr->right, value);
        }
        
        // If value is less than the current node
        if (value < curr->data) {
            return removeNode2(curr->left, value);
        }

        // If node doesn't have any children
        if (curr->left == NULL && curr->right == NULL) {
            delete curr;
            curr = NULL;

        // If node doesn't have a right child  
        } else if (curr->right == NULL) {
            Node *temp = curr;
            curr = curr->left;

            delete temp;
            temp = NULL;

        // If node doesn't have a left child  
        } else if (curr->left == NULL) {
            Node *temp = curr;
            curr = curr->right;

            delete temp;
            temp = NULL;

        // If node has left and right children  
        } else {
            Node *temp = curr->left;

            while (temp->right != NULL) {
                temp = temp->right;
            }    

            curr->data = temp->data;
            return removeNode2(curr->left, curr->data);
        }

        // Decrement size
        treeSize--;

        // If value is equal to the current node
        return true;
    }

    // Remove all nodes
    Node* clearAll(Node* curr) {
        if (curr == NULL) {
            return NULL;
        } else {
            clearAll(curr->left);
            clearAll(curr->right);
            delete curr;
        }

        return NULL;
    } 

    
public:
    BST() {
        root = NULL;
    }

    ~BST() { 
        clearAll(root);
        treeSize = 0;
    }
    
    // Return true if able to add node else return false
    bool addNode(const T& value) {
        duplicate = false;
        root = insertNode(root, value);
        treeSize++;
        return !duplicate;
    }
    
    // Return true when node is removed else return false
    bool removeNode(const T& value) {
       return removeNode2(root, value);
    }
    
    // Return true if tree is empty else return false
    bool clearTree() {
        clearAll(root);
        root = NULL;
        treeSize = 0;
        return true;
    }
    
    /** Output nodes at a given level */
    bool outLevel(Node *curr, int level, stringstream& out) const {
        if (curr == NULL) {
            return false;
        }

        if (level == 1) {
            out << " " << curr->data;
            if ((curr->left != NULL) || (curr->right != NULL)) return true;
            return false;
        }

        if ((level == 2) && !curr->left && curr->right) {
            out << " _";
        }

        bool left = outLevel(curr->left, level - 1, out);
        bool right = outLevel(curr->right, level - 1, out);
        
        if ((level == 2) && curr->left && !curr->right) {
            out << " _";
        }
        
        return left || right;
    }  

    // Return a level order traversal of a BST as a string
    string toString() const {
        stringstream out;

        if (root == NULL) {
            out << " empty";
        } else {
            int level = 0;
            do {
                out << endl << "  " << ++level << ":";
            } while (outLevel(root, level, out));
        }

        return out.str();
    }
    
    // Return the number of nodes in the BST
    size_t size(void) {
        return treeSize;
    }

    // Return true if able to find node in BST else return false
    bool find(const T& value) {}

    // Overload insertion operator "<<" to print tree using toString function
    friend std::ostream& operator<< (std::ostream& os, const BST &bst) {
        os << bst.toString();         
        return os;
    }

    // Overload assignment operator
    // BST& operator= (const BST &oldBST) {}
};
 