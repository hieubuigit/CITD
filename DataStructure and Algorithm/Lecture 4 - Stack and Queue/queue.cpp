/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Queue
 */
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

Node *initNode(int data)
{
    Node *p = new Node;
    p->data = data;
    p->pNext = NULL;
    return p;
}

struct Queue
{
    Node *pFront;
    Node *pRear;
};

void initQueue(Queue &q)
{
    q.pFront = NULL;
    q.pRear = NULL;
}

void enQueue(Queue &q, Node *node)
{
    if (q.pFront == NULL)
    {
        q.pFront = node;
        q.pRear = node;
    }
    else
    {
        q.pRear->pNext = node;
        q.pRear = node;
    }
}

int deQueue(Queue &q) {
    if (q.pFront == NULL)
        return 0;

    Node *node = q.pFront;
    q.pFront = q.pFront->pNext;
    int value = node->data;
    delete node;

    return value;
}

void printQueue(Queue &q) {
    cout << "Queue <  ";
    for (Node *p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << p->data << "  ";
    }
    cout << "> \n";
}

int main(int argc, char const *argv[])
{
    // Init queue
    Queue q;
    initQueue(q);

    // Init node and add to queue
    Node *p1 = initNode(1);
    Node *p2 = initNode(2);
    Node *p3 = initNode(3);
    Node *p4 = initNode(4);
    Node *p5 = initNode(5);
    Node *p6 = initNode(6);
    Node *p7 = initNode(7);
    Node *p8 = initNode(8);

    enQueue(q, p1);
    enQueue(q, p2);
    enQueue(q, p3);
    enQueue(q, p4);
    enQueue(q, p5);
    enQueue(q, p6);
    enQueue(q, p7);
    enQueue(q, p8);

    // Print queue
    printQueue(q);

    // Dequeue
    cout << "deQueue = " << deQueue(q) << endl;
    cout << "After dequeue: ";
    printQueue(q);

    return 0;
}
