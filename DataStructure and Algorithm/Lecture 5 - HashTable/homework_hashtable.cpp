/**
 * Create by: Hieu Bui Van
 * Student ID: 23410014
 * Description: Homework of HashTable
 */
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>
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

void addTail(Bucket &bk, Node *p)
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
    addTail(h.bucket[i], p);
}

void print(HashTable h)
{
    if (h.bucket[0].pHead != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            Bucket bk = h.bucket[i];
            cout << "Bucket[" << i << "] = \t";
            for (Node *p = bk.pHead; p != NULL; p = p->pNext)
            {
                cout << p->data << "\t";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Khoi tao HashTable truoc khi in\n";
    }
}

void initHashTableWithRandomValue(HashTable &h, int min, int max, int qtyFrom, int qtyTo)
{
    if (min < max && qtyFrom < qtyTo)
    {
        for (int i = qtyFrom; i < qtyTo; i++)
        {
            int rdNum = min + (rand() % (max - min + 1));
            add(h, initNode(rdNum));
        }
    }
}

void addManualValueToHashTable(HashTable &h)
{
    cout << "Nhap gia tri can them vao HashTable = ";
    int value = 0;
    cin >> value;
    add(h, initNode(value));
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

bool findElement(HashTable h, int key)
{
    bool findResult = false;
    for (int i = 0; i < SIZE; i++)
    {
        Bucket bk = h.bucket[i];
        for (Node *p = bk.pHead; p != NULL; p = p->pNext)
        {
            if (p->data == key)
            {
                return true;
            }
        }
    }
    return findResult;
}

int sumAllWithCondition(HashTable h, bool isSumOddNum)
{
    int cal = 0;
    if (h.bucket[0].pHead != NULL)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
            {
                if (isSumOddNum)
                {
                    if ((p->data % 2) != 0)
                    {
                        cal += p->data;
                    }
                }
                else
                {
                    if ((p->data % 2) == 0)
                    {
                        cal += p->data;
                    }
                }
            }
        }
    }
    else
    {
        cout << "HashTable dang rong!\n";
    }
    return cal;
}

bool checkHashTableIsEmpty(HashTable h)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (h.bucket[i].pHead != NULL)
        {
            return false;
        }
    }
    return true;
}

void removeElementInHashTable(HashTable &h, int removeValue)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (Node *p = h.bucket[i].pHead; p != NULL; p = p->pNext)
        {
            if (removeValue == p->data)
            {
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    HashTable h;
    int option = -1;
    bool flag = true;
    do
    {
        // Cau 10. Create menu choose features
        cout << "=========== Chuong trinh cai dat HashTable ===========\n";
        cout << "\t1. Tao du lieu tu dong cho HashTable." << endl;
        cout << "\t2. Tao du lieu cho HashTable tu mang mot chieu." << endl;
        cout << "\t3. Tao du lieu thu cong nhap tu ban phim." << endl;
        cout << "\t4. In gia tri trong HashTable." << endl;
        cout << "\t5. Xoa mot gia tri trong HashTable." << endl;
        cout << "\t6. Tim mot gia tri trong HashTable." << endl;
        cout << "\t7. Tong cac gia tri le trong HashTable." << endl;
        cout << "\t8. Kiem tra Hashtable co rong hay khong?" << endl;
        cout << "\t9. Tong cac gia tri chan trong HashTable." << endl;
        cout << "\t0. Thoat chuong trinh." << endl;
        cout << "\t Nhap lua chon cua ban: ";
        cin >> option;

        if (isdigit(option))
        {
            break;
        }

        if (!flag)
        {
            break;
        }

        if (option == 0)
        {
            break;
        }

        if (option >= 0 && option <= 9)
        {
            initHashTable(h);
            switch (option)
            {
            case 1:
                initHashTableWithRandomValue(h, 856, 988, 45, 95);
                cout << "Da tao thanh cong!\n";
                print(h);
                checkPressEnter(option);
                break;
            case 2:
                initHashTable(h);
                cout << "Da tao thanh cong!\n";
                checkPressEnter(option);
                break;
            case 3:
                addManualValueToHashTable(h);
                checkPressEnter(option);
                break;
            case 4: // In cac phan tu trong HashTable
                cout << "========= Cac phan tu trong HashTable =========" << endl;
                print(h);
                checkPressEnter(option);
                break;
            case 5: // Xoa gia tri trong HashTable
                cout << "Chua hoan thanh chon chuc nang khac" << endl;
                checkPressEnter(option);
                break;
            case 6: // Tim mot gia tri trong 1 HashTable
            {
                cout << "Nhap so can tim = ";
                int key = 0;
                cin >> key;
                bool result = findElement(h, key);
                string resultStr = result ? "Co " + to_string(key) + " trong HashTable\n" : "Khong tim thay " + to_string(key) + "trong HashTable\n";
                cout << resultStr << endl;
                checkPressEnter(option);
                break;
            }
            case 7: // Tinh tong cac gia tri le trong HashTable
            {
                int sumAllOdd = sumAllWithCondition(h, true);
                cout << "Tong cac gia tri le trong HashTable = " << sumAllOdd << endl;
                checkPressEnter(option);
                break;
            }
            case 8: // Kiem tra HashTable co rong hay khong?
            {
                bool resultCheck = checkHashTableIsEmpty(h);
                if (resultCheck)
                {
                    cout << "HashTable is empty!\n";
                }
                else
                {
                    cout << "HasTable isn't empty!\n";
                }
                checkPressEnter(option);
                break;
            }
            case 9:
            {
                int sumAllEven = sumAllWithCondition(h, false);
                cout << "Tong cac gia tri chan trong HashTable = " << sumAllEven << endl;
                checkPressEnter(option);
                break;
            }
            default:
                flag = false;
                option = -1;
                break;
            }
        }
    } while (option <= 0 || option > 9);

    return 0;
}
