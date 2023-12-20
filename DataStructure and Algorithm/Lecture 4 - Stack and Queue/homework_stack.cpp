/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Stack.
 * Homework: convert an decimal number to binary number.
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

void pushMultipleNode(Stack &s, int data)
{
    while (data >= 0)
    {
        int divideByTwo = data / 2;
        int remainder = data % 2;

        Node *node = initNode(remainder);
        pushNode(s, node);
        data = divideByTwo;

        if (remainder == 0 && divideByTwo == 0)
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    // Init stack
    Stack s;
    initStack(s);

    // Convert integer number to binary number
    int numberToConvert = 13;
    pushMultipleNode(s, numberToConvert);

    // Print stack
    cout << "Number to convert = " << numberToConvert << endl;
    cout << "Result after convert = ";
    printStack(s);

    // Pop node from stack
    int popVal = 0;
    popNode(s, popVal);
    cout << "\nTop value = " << popVal << endl;
    cout << "After pop: ";
    printStack(s);

    return 0;
}
