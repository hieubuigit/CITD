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

struct Queue
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

void initQueue(Queue &newQueue)
{
    newQueue.pFront = NULL;
    newQueue.pRear = NULL;
}

void enQueue(Node *newNode, Queue &queue)
{
    if (queue.pFront == NULL)
    {
        queue.pFront = newNode;
        queue.pRear = newNode;
    }
    else
    {
        queue.pRear->pNext = newNode;
        queue.pRear = newNode;
    }
}

void deQueue(Queue &queue, double &value)
{
    if (queue.pFront == NULL)
    {
        return;
    } else {
        Node *firstNode = queue.pFront;
        queue.pFront = queue.pFront->pNext;
        value = firstNode->data;
        delete firstNode;
    }
}

void printQueue(Queue queue) {
    cout << "Queue [ ";
    for (Node *node = queue.pFront; node != NULL; node = node->pNext)
    {
        cout << node->data << ", ";
    }
    cout << " ]\n";
}

int main(int argc, char const *argv[])
{
    Queue queue;
    initQueue(queue);

    // Enqueue
    enQueue(initNode(9), queue);
    enQueue(initNode(10), queue);
    enQueue(initNode(12), queue);
    enQueue(initNode(13), queue);
    enQueue(initNode(14), queue);
    enQueue(initNode(15), queue);
    printQueue(queue);

    // De queue
    double firstNode = 0;
    deQueue(queue, firstNode);
    cout << "After queue = ";
    printQueue(queue);

    return 0;
}