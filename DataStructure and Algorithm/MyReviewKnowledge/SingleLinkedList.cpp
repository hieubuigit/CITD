#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

struct Node
{
    double data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

Node *initNode(double data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}

void initSinglyLinkedList(List &newList)
{
    newList.pHead = NULL;
    newList.pTail = NULL;
}

bool addHead(Node *newNode, List &list)
{
    if (list.pTail == NULL)
    {
        list.pHead = newNode;
        list.pTail = newNode;
    }
    else
    {
        newNode->pNext = list.pHead;
        list.pHead = newNode;
    }
    return newNode->data == list.pHead->data;
}

bool addTail(Node *newNode, List &list)
{
    if (list.pHead == NULL)
    {
        list.pHead = newNode;
        list.pTail = newNode;
    }
    else
    {
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
    return newNode->data == list.pTail->data;
}

// bool addAtPosition(Node node, List *list, int pos)
// {

// }

// bool removeHead() {

// }

// bool removeTail() {

// }

// bool removeAtPosition() {

// }

void printList(List list)
{
    cout << "Singly List: [ ";
    Node *node = list.pHead;
    while (node != NULL)
    {
        cout << node->data << ", ";
        node = node->pNext;
    }
    cout << " ] \n";
}

int main(int argc, char const *argv[])
{
    List list;
    initSinglyLinkedList(list);

    addHead(initNode(9), list);
    addHead(initNode(10), list);
    addHead(initNode(11), list);
    printList(list);

    addTail(initNode(12), list);
    addTail(initNode(13), list);
    addTail(initNode(14), list);
    printList(list);

    return 0;
}
