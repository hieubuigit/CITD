/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Buoi 2: Linked List
 */
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addHead(List &l, Node *p)
{
    if (l.pTail == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void addTail(List &l, Node *p)
{
    if (l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = p;
    }
    else
    {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void printLinkedListWh(List l)
{
    Node *n = l.pHead;
    while (n != NULL)
    {
        cout << n->data << "\t";
        n = n->pNext;
    }
}

void printLinkedList(List l)
{
    for (Node *n = l.pHead; n != NULL; n = n->pNext)
    {
        cout << n->data << "\t";
    }
}

bool removeHead(List l)
{
}

bool removeTail(List l)
{
}

bool removeAtPosition(List l, int nodeIndx)
{
}

int main(int argc, char const *argv[])
{
    // Init list
    List l;
    initList(l);

    // Init note
    Node *p1 = initNode(79);
    cout << p1->data << endl;
    cout << (*p1).data << endl;
    cout << p1->pNext << endl;


    // l.pHead = p1;
    // cout << l.pHead->data << endl;
    // cout << l.pTail << endl;

    // Node *p2 = initNode(22);
    // Node *p3 = initNode(333);

    // // Add node to list
    // addHead(l, p1);
    // addTail(l, p3);

    // Print list

    // Search

    // Sort

    // Find min max

    // Delete node

    // Test
    // int p01 = 100;
    // cout << &p01 << endl;


    return 0;
}
