#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

struct Node
{
    double data;
    Node *pLeft;
    Node *pRight;
};

struct Tree
{
    Node *pRoot;
};

Node *initNode(double data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;
    return newNode;
}

void initTree(Tree &tree)
{
    tree.pRoot = NULL;
}

void addNode(Tree &tree, Node *newNode)
{
    if (tree.pRoot == NULL)
    {
        tree.pRoot = newNode;
        return;
    }
    Node *pGoTo = tree.pRoot;
    Node *pLocation = NULL;
    while (pGoTo != NULL)
    {
        pLocation = pGoTo;
        if (newNode->data < pGoTo->data)
        {
            pGoTo = pGoTo->pLeft;
        }
        if (newNode->data > pGoTo->data)
        {
            pGoTo = pGoTo->pRight;
        }
    }
    if (newNode->data < pLocation->data)
    {
        pLocation->pLeft = newNode;
    }
    else if (newNode->data > pLocation->data)
    {
        pLocation->pRight = newNode;
    }
}

void printBinaryTree(Tree tree)
{

}

bool find(Tree tree, double keyword)
{
    return false;
}


int main(int argc, char const *argv[])
{
    return 0;
}
