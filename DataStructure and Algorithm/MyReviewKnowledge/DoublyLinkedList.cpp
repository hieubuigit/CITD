#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

struct Node
{
    double data;
    Node *pPrev;
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
    newNode->pPrev = NULL;
    newNode->pNext = NULL;
    return newNode;
}

void initDoublyLinkedList(List &newList)
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
    } else {
        newNode->pNext = list.pHead;
        list.pHead->pPrev = newNode;
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
    } else {
        newNode->pPrev = list.pTail;
        list.pTail->pNext = newNode;
        list.pTail = newNode;
    }
    return newNode->data == list.pTail->data;
}

void addAtPos(Node *newNode, List list) {

}

void printList(List list)
{
    cout << "Doubly List: [ ";
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
    initDoublyLinkedList(list);

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
