/**
 * Name: Hieu Bui Van
 * StudentId: 23410014
 * Class: LT.2023.01
 * Des: Exam 3
 */

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *pNext;
};

struct Bucket
{
    Node *pHead;
    Node *pTail;
};

#define SIZE 9
struct HashTable
{
    Bucket buckets[SIZE];
};

Node *initNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->pNext = NULL;
    return newNode;
}

void initBucket(Bucket &bucket)
{
    bucket.pHead = NULL;
    bucket.pTail = NULL;
}

/**
 * Cau 1: Viet ham bam theo phuong phap chia
 *  + Input:
 *      - int data: du lieu can tinh toan chi so index
 *  + Output:
 *      - int:  so index cua bucket can tim
 */
int hashFunc(int data)
{
    return data % SIZE;
}

void initHashTable(HashTable &hashTable)
{
    for (int i = 0; i < SIZE; i++)
    {
        initBucket(hashTable.buckets[i]);
    }
}

void addToBucket(Bucket &bk, Node *newNode)
{
    if (bk.pHead == NULL)
    {
        bk.pHead = bk.pTail = newNode;
    }
    else
    {
        bk.pTail->pNext = newNode;
        bk.pTail = newNode;
    }
}

void add(HashTable &h, int data)
{
    Node *newNode = initNode(data);
    int index = hashFunc(data);
    addToBucket(h.buckets[index], newNode);
}

/**
 * Cau 2: Viet ham khoi tao hashtable tu dong, gia tri ngau nhien tron [856; 988]
 *      + Input:
 *      + Output:
 */
void initHashTableWithRandomValue(HashTable &h, int min, int max, int qtyFrom, int qtyTo)
{
    int quantityRd = qtyFrom + (rand() % (qtyTo - qtyFrom + 1));
    for (int i = 0; i < quantityRd; i++)
    {
        int valueRd = min + (rand() % (max - min + 1));
        add(h, valueRd);
    }
}

/**
 * Cau 3: Viet ham nhap gia tri cho bang bam tu tu 1 mang co n phan tu
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *          - arr[]: cac gai tri se them vao hashtable
 *          - size: kich thuoc cua array
 *      + Output: void
 */
void initHashTableWithArray(HashTable &h, int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        add(h, arr[i]);
    }
}

/**
 * Cau 4: Viet ham nhap gia tri bang bam tu ban phimm ket thuc khi nhap -1
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *      + Output: void
 */
void nhapGiaTriChoBangBam(HashTable &h)
{
    int value;
    cout << "Nhap gia tri cho hash table, ket thuc khi nhap -1: ";
    do
    {
        cin >> value;
        if (value == -1)
        {
            return;
        }
        add(h, value);
    } while (value);
}

/**
 * Cau 5: Viet ham kiem tra hashtable co rong hay khong?
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *      + Output:
 *          - bool: true neu hashtable rong, nguoc lai thi khong rong
 */
bool hashTableIsNull(HashTable h)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (Node *n = h.buckets[i].pHead; n != NULL; n = n->pNext)
        {
            return false;
        }
    }
    return true;
}

/**
 * Cau 6: Dem cac gia tri co trong hashtable
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *      + Output:
 *          - int: so phan tu co trong hashtable
 */
int demPhanTuTrongHashTable(HashTable h)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (Node *n = h.buckets[i].pHead; n != NULL; n = n->pNext)
        {
            if (n->data)
            {
                count += 1;
            }
        }
    }
    return count;
}

/**
 * Cau 7: Tim x trong hashtable
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *      + Output:
 *          - int key: so can tim
 */
bool timX(HashTable h, int key)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (Node *n = h.buckets[i].pHead; n != NULL; n = n->pNext)
        {
            if (n->data == key)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * Cau 8: Viet ham tim min max trong hashtable
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *      + Output:
 *          - bool isMin, true neu muon tim so nho nhat, false neu tim so lon nhat
 */
int timMinMax(HashTable h, bool isMin)
{
    int needFind = h.buckets[0].pHead->data;
    for (int i = 0; i < SIZE; i++)
    {
        for (Node *n = h.buckets[i].pHead; n != NULL; n = n->pNext)
        {
            if (isMin)
            {
                if (n->data < needFind)
                {
                    needFind = n->data;
                }
            }
            else
            {
                if (n->data > needFind)
                {
                    needFind = n->data;
                }
            }
        }
    }
    return needFind;
}

/**
 * Cau 9: Ham dem gia tri chan le va chan trong hashtable
 *      + Input:
 *          - HashTable &h: hash table luu tru cac gia tri so nguyen
 *      + Output:
 *          - int &soChan: tong so chan
 *          - int &soLe: tong so le
 */
void demGiaTriChanLe(HashTable h, int &soChan, int &soLe)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (Node *n = h.buckets[i].pHead; n != NULL; n = n->pNext)
        {
            if (n->data % 2 == 0)
            {
                soChan += 1;
            }
            else
            {
                soLe += 1;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    HashTable h;
    initHashTable(h);

    cout << "\n******************* Cau 2 *******************\n";
    initHashTableWithRandomValue(h, 856, 988, 45, 95);

    cout << "\n******************* Cau 3 *******************\n";
    int size = 11;
    int arr[size] = {50, 75, 30, 10, 90, 70, 60, 30, 70, 90};
    HashTable h1;
    initHashTable(h1);
    // initHashTableWithArray(h1, arr, size);

    cout << "\n******************* Cau 4 *******************\n";
    nhapGiaTriChoBangBam(h);

    cout << "\n******************* Cau 5 *******************\n";
    bool resultCheck = hashTableIsNull(h);
    if (resultCheck)
    {
        cout << "HashTable rong!" << endl;
    }
    else
    {
        cout << "HashTable khong rong!" << endl;
    }

    cout << "\n******************* Cau 6 *******************\n";
    int count = demPhanTuTrongHashTable(h);
    cout << "So luong phan tu = " << count << endl;

    cout << "\n******************* Cau 7 *******************\n";
    int key = 100;
    bool findResult = timX(h, key);
    if (findResult)
    {
        cout << "Tim thay " << key << endl;
    }
    else
    {
        cout << "Khong tim thay " << key << endl;
    }

    cout << "\n******************* Cau 8 *******************\n";
    int min = timMinMax(h, true);
    int max = timMinMax(h, false);
    cout << "Min = " << min << endl;
    cout << "Max = " << max;
    cout << endl;

    cout << "\n******************* Cau 9 *******************\n";
    int countSoLe = 0;
    int countSoChan = 0;
    demGiaTriChanLe(h, countSoChan, countSoLe);
    cout << "So Le = " << countSoLe << endl;
    cout << "So Chan = " << countSoChan;

    return 0;
}
