#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

#define MAX_BUCKET 5
struct Node
{
    double data;
    Node *pNext;
};

struct Bucket
{
    Node *pHead;
    Node *pTail;
};

struct HashTable
{
    Bucket buckets[MAX_BUCKET];
};

Node *initNode(double value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->pNext = NULL;
    return newNode;
}

void initBucket(Bucket &newBucket)
{
    newBucket.pHead = NULL;
    newBucket.pTail = NULL;
}

void initHashTable(HashTable &hashTable)
{
    for (int i = 0; i < MAX_BUCKET; i++)
    {
        initBucket(hashTable.buckets[i]);
    }
}

int hashFunction(double value)
{
    return (int)value % MAX_BUCKET;
}

void addTail(Bucket &bucket, Node *newNode)
{
    if (bucket.pHead == NULL)
    {
        bucket.pHead = bucket.pTail = newNode;
    }
    else
    {
        bucket.pTail->pNext = newNode;
        bucket.pTail = newNode;
    }
}

void add(HashTable &hashTable, Node *newNode) {
    int index = hashFunction(newNode->data);
    addTail(hashTable.buckets[index], newNode);
}

void printHashTable(HashTable hashTable) {
    cout << "--- Hash Table --- \n";
    for (int i = 0; i < MAX_BUCKET; i++)
    {
        cout << "Bucket [" << i << "] = [ ";
        for (Node *p = hashTable.buckets[i].pHead; p != NULL; p = p->pNext)
        {
            cout << p->data << "   ";
        }
        cout << " ]\n";
    }
}

int main(int argc, char const *argv[])
{
    HashTable hashTable;
    initHashTable(hashTable);

    add(hashTable, initNode(50));
    add(hashTable, initNode(35));
    add(hashTable, initNode(90));
    add(hashTable, initNode(36));
    add(hashTable, initNode(21));
    add(hashTable, initNode(73));
    add(hashTable, initNode(28));
    add(hashTable, initNode(53));
    add(hashTable, initNode(13));
    add(hashTable, initNode(64));
    add(hashTable, initNode(37));

    printHashTable(hashTable);

    return 0;
}
