#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
    int data;
    Node *pPre;
    Node *pNext;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pPre = NULL;
    p->pNext = NULL;
    return p;
}

struct List
{
    Node *pHead;
    Node *pTail;
};

void initList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

void addNodeToHead(List &l, Node *n)
{
    if (l.pTail == NULL)
    {
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else {
        n->pNext = l.pHead;
        l.pHead->pPre = n;
        l.pHead = n;
    }
}

void addNodeToTail(List &l, Node *n)
{
if (l.pHead == NULL)
    {
        l.pHead = NULL;
        l.pTail = NULL;
    }
    else {
        l.pTail->pNext = n;
        n->pPre = l.pTail;
        l.pTail = n;
    }
}

void printOneNode(Node *n)
{
    cout << n->data << endl;
}

void printDownLinkedList(List &l, Node *n)
{
    for (Node *n = l.pHead; n != NULL; n = n->pNext)
    {
        cout << n->data << endl;
    }
}

void printReverseLinkedList(List &l, Node *n) {
    for (Node *n = l.pTail; n != NULL; n = n->pPre)
    {
        cout << n->data << endl;
    }
}

int main(int argc, char const *argv[])
{
    // Init list
    List l;
    initList(l);

    // Init Node
    Node *p1 = initNode(10);
    Node *p2 = initNode(20);
    Node *p3 = initNode(30);
    Node *p4 = initNode(40);
    Node *p5 = initNode(50);

    // Add node to list


    return 0;
}
