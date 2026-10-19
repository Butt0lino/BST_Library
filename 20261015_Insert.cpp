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
        {
            current = current->lchild;
        }
        else if(val > current->data)
        {
            current = current->rchild;
        }
        else
        {
            return r;
        }
    }

    if(val < dad->data)
    {
        dad->lchild = new Node(val);
    }
    else
    {
        dad->rchild = new Node(val);
    }
    return r;
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

int main()
{
    return 0;
}