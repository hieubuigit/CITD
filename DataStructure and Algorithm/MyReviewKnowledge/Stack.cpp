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

struct Stack
{
    Node *pTop;
};

Node *initNode(double data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}

void initStack(Stack &newStack)
{
    newStack.pTop = NULL;
}

bool pushNode(Node *newNode, Stack &stack)
{
    if (stack.pTop == NULL)
    {
        stack.pTop = newNode;
    }
    else
    {
        newNode->pNext = stack.pTop;
        stack.pTop = newNode;
    }
    return true;
}

void popNode(Stack &stack, double &value)
{
    if (stack.pTop == NULL)
    {
        return;
    }
    Node *lastNode = stack.pTop;
    stack.pTop = stack.pTop->pNext;
    value = lastNode->data;
    delete lastNode;
}

void printStack(Stack stack)
{
    cout << "Stack \n";
    Node *node = stack.pTop;
    while (node != NULL)
    {
        cout << "| \t " << node->data << " \t | \n";
        node = node->pNext
}

int main(int argc, char const *argv[])
{
    Stack stack;
    initStack(stack);

    pushNode(initNode(9), stack);
    pushNode(initNode(10), stack);
    pushNode(initNode(11), stack);
    pushNode(initNode(12), stack);
    pushNode(initNode(13), stack);

    printStack(stack);

    double lastNode = 0;
    popNode(stack, lastNode);
    cout << "Last node: " << lastNode << "\n\n";
    printStack(stack);

    popNode(stack, lastNode);
    cout << "Last node: " << lastNode << "\n\n";
    printStack(stack);

    return 0;
}
