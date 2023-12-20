/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Stack
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

struct Stack
{
    Node *pTop;
};

void initStack(Stack &stack)
{
    stack.pTop = NULL;
}

void pushNode(Stack &stack, Node *node)
{
    if (stack.pTop == NULL)
    {
        stack.pTop = node;
    }
    else
    {
        node->pNext = stack.pTop;
        stack.pTop = node;
    }
}

void popNode(Stack &stack, int &value) {
    if (stack.pTop == NULL)
        return;
    Node *p = stack.pTop;
    stack.pTop = stack.pTop->pNext;
    value = p->data;
    delete p;
}

void printStack(Stack &stack) {
    cout << "Stack <  ";
    for (Node *p = stack.pTop; p != NULL; p = p->pNext)
    {
        cout << p->data << "  ";
    }
    cout << "> \n";
}

bool stackIsNull(Stack s) {
    return s.pTop == NULL;
}

bool stackIsFull(Stack s, int sizeOfStack) {
    return false;
}

int main(int argc, char const *argv[])
{
    // Init stack
    Stack s;
    initStack(s);

    // Init node and add to stack
    Node *p1 = initNode(1);
    Node *p2 = initNode(2);
    Node *p3 = initNode(3);
    Node *p4 = initNode(4);
    Node *p5 = initNode(5);
    Node *p6 = initNode(6);
    Node *p7 = initNode(7);
    Node *p8 = initNode(8);

    pushNode(s, p1);
    pushNode(s, p2);
    pushNode(s, p3);
    pushNode(s, p4);
    pushNode(s, p5);
    pushNode(s, p6);
    pushNode(s, p7);
    pushNode(s, p8);

    // Print stack
    printStack(s);

    // Pop node from stack
    int popVal = 0;
    popNode(s, popVal);
    cout << "Top value = " << popVal << endl;
    cout << "After pop: ";
    printStack(s);

    return 0;
}
