/**
 * Name: Hieu Bui Van
 * StudentId: 23410014
 * Class: LT.2023.01
 * Des: Exam 1: Binary search tree
 */

#include <iostream>
#include <string>
#include <ctime>
#include <stack>
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

/**
 * Cau 1: Ham chen node chua gia tri vao cay.,
 *      + Input:
 *          - Tree &tree: Tree dung de chua cac node
 *          - Node *n: Node can them vao tree
 *      + Output:
 *          - void
 */
void addNodeToTree(Tree &tree, Node *n)
{
    if (tree.pRoot == NULL)
    {
        tree.pRoot = n;
        return;
    }

    Node *pGoto = tree.pRoot;
    Node *pLocation = NULL;
    while (pGoto != NULL)
    {
        pLocation = pGoto;
        if (n->data == pGoto->data)
        {
            return;
        }
        else if (n->data < pGoto->data)
        {
            pGoto = pGoto->pLeft;
        }
        else if (n->data > pGoto->data)
        {
            pGoto = pGoto->pRight;
        }
    }
    if (n->data < pLocation->data)
        pLocation->pLeft = n;
    else if (n->data > pLocation->data)
        pLocation->pRight = n;
}

/**
 * Cau 2: Ham tao cay tu dong ngau nhien
 *      + Input:
 *          - Tree &tree: Tree dung de chua cac node
 *          - int min: gia tri nho nhat cho node
 *          - int max: gia tri lon nhat cho node
 *          - int qtyFrom: so luong Node nho nhat
 *          - int qtyTo: so luong Node lon nhat
 *      + Output:
 *          - void
 */
void initRandomForTree(Tree &tree, int min, int max, int qtyFrom, int qtyTo)
{
    int quantityRd = qtyFrom + (rand() % (qtyTo - qtyFrom + 1));
    for (int i = 0; i < quantityRd; i++)
    {
        double valueRd = min + (rand() % (max - min + 1));
        addNodeToTree(tree, initNode(valueRd));
    }
}

/**
 * Cau 3: Ham tao tree tu mang ngau nhien
 *      + Input:
 *          - Tree &tree: Tree dung de chua cac Node.
 *          - double arr[]: mang so thuc can them vao tree
 *          - int size: kich thuoc mang
 *      + Output: void
 */
void initTreeWithArray(Tree &tree, double arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        addNodeToTree(tree, initNode(arr[i]));
    }
}

/**
 * Cau 4: Viet ham duyet tree theo NLR, LRN, LNR, Chu y in kem them 3 dia chi cua  Node, Left va Right
 *      + Input:
 *          - Tree tree: Tree dung de chua cac Node.
 *          - int option: 0 - NLR, 1 - LRN, 2 - LNR
 *      + Output:
 *          - void
 */
void inOrder(Tree tree)
{
    // LNR
    stack<Node *> s;
    Node *n = tree.pRoot;

    while (n != NULL || !s.empty())
    {
        while (n != NULL)
        {
            s.push(n);
            n = n->pLeft;
        }

        n = s.top();
        s.pop();
        cout << n->data << "  ";

        n = n->pRight;
    }
}

void preOrder(Tree tree)
{
    // NLR - Chua lam kip
}

void postOrder(Tree tree)
{
    // LRN - Chua lam kip
}

/**
 * Cau 5: Ham tim gia tri X, X do nguoi dung nhap
 *      + Input:
 *          - Tree &tree: Tree dung de chua cac Node.
 *          - double key: gia tri can tim tu nguoi dung
 *      + Output:
 *          - Node *: Dia chi node khi tim thay, neu khong tim thay return NULL
 */
double nhapGiaTri(Tree &tree)
{
    double val;
    cout << "Nhap gia tri can tim = ";
    cin >> val;
    return val;
}
Node *timGiaTriTrongTree(Tree &tree, double key)
{
    Node *currentNode = tree.pRoot;
    while (currentNode != NULL)
    {
        if (currentNode->data == key)
            return currentNode;

        if (key < currentNode->data)
            currentNode = currentNode->pLeft;
        else if (key > currentNode->data)
            currentNode = currentNode->pRight;
    }
    return NULL;
}


void countNode(Node *pRoot, int &numberNode)
{
    if (pRoot != NULL)
    {
        countNode(pRoot->pLeft, numberNode);
        numberNode++;
        countNode(pRoot->pRight, numberNode);
    }
}

/**
 * Cau 6: Dem toan bo so node trong tree
 *      + Input:
 *          - Tree tree: Tree dung de chua cac Node can dem
 *      + Output:
 *          - int: so luong Node co trong Tree
 */
int demToanBoSoNodeTrongTree(Tree tree)
{
    int numNode = 0;
    countNode(tree.pRoot, numNode);
    return numNode;
}

/**
 * Cau 7: Ham in ra cac node nhanh con lai tu mot code tu ban phim, cach duyet LNR
 *      + Input:
 *          -
 *      + Output:
 *          -
 */
void printNhanhConLaiTheoLNR(Tree tree)
{
}

/**
 * Cau 8: Ham dem so node co gia tri lon hon X va nho hon Y. X, Y do nguoi dung nhap vao
 *      + Input:
 *          -
 *      + Output:
 *          -
 */
void demNodeCoGiaTriTrongKhoang(Tree tree, double x, double y)
{
}

/**
 * Cau 9: Ham dem cac node co gia tri chan le.
 *      + Input:
 *          -
 *      + Output:
 *          -
 */
void demChanLeTrongTree(Tree tree, int &soChan, int &soLe)
{
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    Tree tree;
    initTree(tree);


    cout << "\n******************* Cau 1 *******************\n";
    cout << "Add node to tree \n";
    addNodeToTree(tree, initNode(10));
    cout << endl;


    cout << "\n******************* Cau 2 *******************\n";
    cout << "Khoi tao tree voi array \n";
    initRandomForTree(tree, 512, 723, 50, 60);


    cout << "\n******************* Cau 3 *******************\n";
    Tree tree1;
    initTree(tree1);

    cout << "Khoi tao tree tu dong voi array\n";
    int size = 11;
    double arr[size] = {50, 75, 25, 30, 10, 90, 70, 60, 30, 70, 90};
    initTreeWithArray(tree1, arr, size);


    cout << "\n******************* Cau 4 *******************\n";
    cout << "Print tree theo LNR: ";
    inOrder(tree1);
    cout << endl;


    cout << "\n******************* Cau 5 *******************\n";
    double key = 90;
    Node *resultNode = timGiaTriTrongTree(tree1, key);
    if (resultNode != NULL)
    {
        cout << "Tim thay " << key <<  " trong tree! \n";
    } else {
        cout << "Khong tim thay " << key << " trong tree! \n";
    }


    cout << "\n******************* Cau 6 *******************\n";
    int sumNode = demToanBoSoNodeTrongTree(tree);
    cout << "Tong so node trong tree = " << sumNode << endl;


    cout << "\n******************* Cau 7 *******************\n";

    cout << "\n******************* Cau 8 *******************\n";

    cout << "\n******************* Cau 9 *******************\n";

    return 0;
}
