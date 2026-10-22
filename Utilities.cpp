#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* rchild;
    Node* lchild;
    Node(int val)
    {
        data = val;
        rchild = nullptr;
        lchild = nullptr;
    }
};

Node* insert(Node* r, int val)
{
    if(r == nullptr)
    {
        return new Node(val);
    }

    Node* dad{nullptr};
    Node* current{r};

    while(current != nullptr)
    {
        dad = current;
        if(val < current->data)
            current = current->lchild;
        else if(val > current->data)
            current = current->rchild;
        else
            return r;
    }

    if(val < dad->data)
    {
        dad->lchild = new Node(val);
        current = dad->lchild;
    }
    else
    {
        dad->rchild = new Node(val);
        current = dad->rchild;
    }
    return current;
}

Node* insertR(Node* r, int val)
{
    if(r == nullptr)
    {
        return new Node(val);
    }

    if(r->data == val)
    {
        return r;
    }

    if(val < r->data)
    {
        r->lchild = insertR(r->lchild, val);
    }
    else
    {
        r->rchild = insertR(r->rchild, val);
    }

    return r;
}

Node* search(Node* root, int key)
{
    Node* current = root;
    while (current != nullptr)
    {
        if (key == current->data)
            return current;
        else if (key < current->data)
            current = current->lchild;
        else
            current = current->rchild;
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

Node* findMin(Node* root)
{
    Node* current = root;
    if(root == nullptr)
        return nullptr;
    while(current->lchild != nullptr)
    {
        current = current->lchild;
    }
    return current;
}

Node* findMax(Node* root)
{
    Node* current = root;
    if(root == nullptr)
        return nullptr;
    while(current->rchild != nullptr)
    {
        current = current->rchild;
    }
    return current;
}

int countNodes(const Node* root)
{
    if(root == nullptr)
        return 0;
    return 1 + countNodes(root->lchild) + countNodes(root->rchild);
}

int countLeaves(const Node* root)
{
    if(root == nullptr)
        return 0;
    if(root->lchild == nullptr && root->rchild == nullptr)
        return 1;
    return countLeaves(root->lchild) + countLeaves(root->rchild);
}

int countInRange(const Node* root, int low, int high)
{
    if(root == nullptr)
        return 0;
    if(root->data >= low && root->data <= high)
        return 1 + countInRange(root->lchild, low, high) + countInRange(root->rchild, low, high);
    else if(root->data < low)
        return countInRange(root->rchild, low, high);
    else
        return countInRange(root->lchild, low, high);
}

int main()
{
    return 0;
}