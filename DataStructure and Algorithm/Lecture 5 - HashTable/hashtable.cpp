/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Homework of HashTable
 */
#include <iostream>
#include <string>
using namespace std;

#define SIZE 5
struct Node
{
    int data;
    Node *pNext;
};

Node *initNode(int value)
{
    Node *p = new Node;
    p->data = value;
    p->pNext = NULL;
    return p;
}

struct Bucket
{
    Node *pHead;
    Node *pTail;
};

void initBucket(Bucket &bk)
{
    bk.pHead = NULL;
    bk.pTail = NULL;
}

int hashFunc(int value)
{
    return value % SIZE;
}

struct HashTable
{
    Bucket bucket[SIZE];
};

void initHashTable(HashTable &h)
{
    for (int i = 0; i < SIZE; i++)
    {
        initBucket(h.bucket[i]);
    }
}

void addHead(Bucket &bk, Node *p)
{
    if (bk.pHead == NULL)
    {
        bk.pHead = bk.pTail = p;
    }
    else
    {
        bk.pTail->pNext = p;
        bk.pTail = p;
    }
}

void add(HashTable &h, Node *p)
{
    int i = hashFunc(p->data);
    addHead(h.bucket[i], p);
}

void print(HashTable h)
{
    for (int i = 0; i < SIZE; i++)
    {
        Bucket bk = h.bucket[i];
        cout << "Bucket[" << i << "] = ";
        for (Node *p = bk.pHead; p != NULL; p = p->pNext)
        {
            cout << p->data << "\t";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    HashTable h;
    initHashTable(h);

    add(h, initNode(70));
    add(h, initNode(12));
    add(h, initNode(11));
    add(h, initNode(7));
    add(h, initNode(101));
    add(h, initNode(86));
    add(h, initNode(90));
    add(h, initNode(17));
    add(h, initNode(34));
    add(h, initNode(77));
    add(h, initNode(13));

    print(h);

    return 0;
}
