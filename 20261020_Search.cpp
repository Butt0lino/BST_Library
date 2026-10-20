#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
    Node(int val)
    {
        data = val;
        lchild = nullptr;
        rchild = nullptr;
    }
};

Node* search(Node* root, int key)
{
    while (root != nullptr)
    {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->lchild;
        else
            root = root->rchild;
    }
    return nullptr;
}

Node* searchR(Node* root, int key)
{
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchR(root->lchild, key);
    else
        return searchR(root->rchild, key);
}

int main()
{
    return 0;
}