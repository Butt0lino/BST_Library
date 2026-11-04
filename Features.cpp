#include <iostream>
#include <algorithm>
using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;

public:
    Node (int key) {
        data = key;
        left = right = nullptr;
    }

    int getData() const {
        return data;
    }

    Node* getLeft() const {
        return left;
    }

    Node* getRight() const {
        return right;
    }

    void setData(int key) {
        data = key;
    }

    void setLeft(Node* n) {
        left = n;
    }
    
    void setRight(Node* n) {
        right = n;
    }

    bool isLeaf() const {
        if(left == nullptr && right == nullptr) {
            return true;
        }
        return false;
    }

    void inOrder() const {
        if(left != nullptr) {
            left->inOrder();
        }
        cout << data << " ";
        if(right != nullptr) {
            right->inOrder();
        }
    }

    int height() const {
        int leftHeight = (left != nullptr) ? left->height() : 0;
        int rightHeight = (right != nullptr) ? right->height() : 0;
        return 1 + max(leftHeight, rightHeight);
    }

    int contaFoglieHelper() const {
        if(isLeaf()) {
            return 1;
        }
        int count = 0;
        if(left != nullptr) {
            count += left->contaFoglieHelper();
        }
        if(right != nullptr) {
            count += right->contaFoglieHelper();
        }
        return count;
    }

    int contaIntervalloHelper(int low, int high) const {
        if(data < low) {
            return right != nullptr ? right->contaIntervalloHelper(low, high) : 0;
        } else if(data > high) {
            return left != nullptr ? left->contaIntervalloHelper(low, high) : 0;
        } else {
            int count = 1;
            if(left != nullptr) {
                count += left->contaIntervalloHelper(low, high);
            }
            if(right != nullptr) {
                count += right->contaIntervalloHelper(low, high);
            }
            return count;
        }
    }
};

class BST {
private:
    Node* root;         //tree root
    int numNodi;        //node count

public:
    BST() {
        root = nullptr;
        numNodi = 0;
    }

    bool isEmpty() const {
        if(root == nullptr) {
            return true;
        }
        return false;
    }

    int size() const {
        return numNodi;
    }

    bool insert(int key) {
        if(root == nullptr) {
            root = new Node(key);
            numNodi++;
            return true;
        }

        Node* dad = nullptr;
        Node* current = root;

        while(current != nullptr) {
            dad = current;
            if(key < current->getData())
                current = current->getLeft();
            else if(key > current->getData())
                current = current->getRight();
            else
                return false;
        }

        if(key < dad->getData())
            dad->setLeft(new Node(key));
        else
            dad->setRight(new Node(key));
        numNodi++;
        return true;
    }

    bool search(int key) const {
        if(root == nullptr) {
            return false;
        }
        Node* current = root;
        while(current != nullptr) {
            if(key == current->getData()) 
                return true;
            if(key < current->getData())
                current = current->getLeft();
            else
                current = current->getRight();
        }
        return false;
    }

    void inOrder() {
        if(root == nullptr)
            return;
        root->inOrder();
    }

    int height() const {
        if(root == nullptr)
            return 0;
        return root->height();
    }

    int minimo() const {
        if(root == nullptr)
            return -1;
        Node* current = root;
        while(current->getLeft() != nullptr) {
            current = current->getLeft();
        }
        return current->getData();
    }

    int massimo() const {
        if(root == nullptr)
            return -1;
        Node* current = root;
        while(current->getRight() != nullptr) {
            current = current->getRight();
        }
        return current->getData();
    }

    bool remove(int key) {
        Node* parent = nullptr;
        Node* current = root;

        while(current != nullptr && current->getData() != key) {
            parent = current;
            if(key < current->getData())
                current = current->getLeft();
            else
                current = current->getRight();
        }

        if(current == nullptr)
            return false; // Key not found

        // Case 1: Node with only one child or no child
        if(current->getLeft() == nullptr || current->getRight() == nullptr) {
            Node* newCurr;

            if(current->getLeft() == nullptr)
                newCurr = current->getRight();
            else
                newCurr = current->getLeft();

            if(parent == nullptr) {
                root = newCurr; // Node to be deleted is root
            } else {
                if(parent->getLeft() == current)
                    parent->setLeft(newCurr);
                else
                    parent->setRight(newCurr);
            }
            delete current;
        } else {
            // Case 2: Node with two children
            Node* successorParent = current;
            Node* successor = current->getRight();

            while(successor->getLeft() != nullptr) {
                successorParent = successor;
                successor = successor->getLeft();
            }

            current->setData(successor->getData());

            if(successorParent != current)
                successorParent->setLeft(successor->getRight());
            else
                successorParent->setRight(successor->getRight());

            delete successor;
        }
        numNodi--;
        return true;
    }

    void svuota() {
        while(root != nullptr) {
            remove(root->getData());
        }
    }
    
    int contaFoglie() const {
        if(root == nullptr)
            return 0;
        return 1 + root->contaFoglieHelper();
    }

    int contaIntervallo(int low, int high) const {
        return root->contaIntervalloHelper(low, high);
    }
};
