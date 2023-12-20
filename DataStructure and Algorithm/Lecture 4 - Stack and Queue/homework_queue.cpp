/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Homework of Queue
 */
#include <iostream>
#include <string>
#include <cctype>
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

/**
 * Cau 1. Init Queue
 */
void initQueue(Queue &q)
{
    q.pFront = NULL;
    q.pRear = NULL;
}

/**
 * Cau 3. Add an element to queue
 */
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

/**
 * Cau 4. Remove an element to queue
 */
int deQueue(Queue &q)
{
    if (q.pFront == NULL)
        return 0;

    Node *node = q.pFront;
    q.pFront = q.pFront->pNext;
    int value = node->data;
    delete node;

    return value;
}

/**
 * Cau 5. Print Queue
 */
void printQueue(Queue &q)
{
    cout << "Queue Front<  ";
    for (Node *p = q.pFront; p != NULL; p = p->pNext)
    {
        cout << p->data << "  ";
    }
    cout << ">Rear \n";
}

/**
 * Cau 2. Check queue is empty
 */
bool queueIsEmpty(Queue q)
{
    return q.pFront == NULL;
}

void checkPressEnter(int &key)
{
    cin.ignore();
    cout << "Enter de tiep tuc...";
    if (cin.get() == '\n')
    {
        key = -1;
    }
    cout << "\n\n\n";
}

int main(int argc, char const *argv[])
{
    Queue q;
    int key = -1;
    bool flag = true;
    bool isValid = true;
    do
    {
        if (!flag)
        {
            break;
        }

        if (!isValid)
        {
            cout << "\n!!! Key khong hop le vui long chon lai \n";
            key = -1;
        }
        else
        {
            cout << "---------- Chuong trinh cai dat queue luu tru so nguyen ----------" << endl;
        }
        cout << "\t(Key 1) Cau 1. Khoi tao queue.\n";
        cout << "\t(Key 2) Cau 2. Kiem tra queue co rong hay khong?.\n";
        cout << "\t(Key 3) Cau 3. Dua mot phan tu vao queue.\n";
        cout << "\t(Key 4) Cau 4. Dua mot phan tu ra khoi queue\n";
        cout << "\t(Key 5) Cau 5. In ra phan tu trong queue.\n";
        cout << "\t(Key 0) Thoat\n";
        cout << "==============================================\n";
        cout << "\t\tChon thao tac, nhap key:";
        cin >> key;

        if (!isdigit(key))
        {
            break;
        }

        if (key > 0 && key <= 5)
        {
            switch (key)
            {
            case 1:
                initQueue(q);
                cout << "Da khoi queue tao xong!\n";
                checkPressEnter(key);
                break;

            case 2:
            {
                bool isNull = queueIsEmpty(q);
                if (isNull)
                {
                    cout << "Queue is null!\n";
                }
                else
                {
                    cout << "Queue is not null!";
                }
                checkPressEnter(key);
                break;
            }
            case 3:
            {
                cout << "Nhap gia tri cho queue = ";
                int data;
                cin >> data;
                Node *node = initNode(data);
                enQueue(q, node);
                checkPressEnter(key);
                break;
            }
            case 4:
            {
                if (!queueIsEmpty(q))
                {
                    cout << "Remove element at front = " << deQueue(q) << endl;
                    cout << "After dequeue: ";
                    printQueue(q);

                    cout << "Xoa thanh cong, Enter de tiep tuc";
                    checkPressEnter(key);
                }
                else
                {
                    cout << "Queue rong, khong the bo mot phan tu! Enter de tiep tuc!";
                    checkPressEnter(key);
                }
                break;
            }
            case 5:
                printQueue(q);
                checkPressEnter(key);
                break;
            default:
                flag = false;
                break;
            }
            isValid = true;
        }
        else
        {
            isValid = false;
        }
    } while (key <= 0 || key > 5);

    return 0;
}
