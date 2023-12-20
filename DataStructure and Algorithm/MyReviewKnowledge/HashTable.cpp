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

struct HashTable
{
    Node *pFront;
    Node *pRear;
};

Node *initNode(double data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}

void initHashTable(HashTable &newHashTable)
{
    newHashTable.pFront = NULL;
    newHashTable.pRear = NULL;
}




int main(int argc, char const *argv[])
{


    return 0;
}
