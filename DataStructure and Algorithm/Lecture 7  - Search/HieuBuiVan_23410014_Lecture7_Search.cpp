/**
 * Created by: Hieu Bui Van
 * Student ID: 23410014
 * Class: LT.2023.1
 * Description: homework about Search algorithm: binary search, linear search, interpolation search.
 */
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/**
 * Function: Them tu dong cac phan tu vao trong mang
 *      int arr: Mang so nguyen can them phan tu vao
 *      int size: Kich thuoc mang
 *      int valueFrom: Gia tri them phai lon hon gia tri nay
 *      int valueTo: Gia tri them phai nho hon gia tri nay
 *      int quantityFrom: So luong phan tu can tao nho nhat
 *      int quantityTo:  So luong phan tu can tao lon nhat
 * Return: void
*/
void autoInsertElementToArray(int arr[], int &size, int valueFrom, int valueTo, int quantityFrom, int quantityTo)
{
    int quantityRd = quantityFrom + (rand() % (quantityTo - quantityFrom + 1));
    size = quantityRd;
    for (int i = 0; i < quantityRd; i++)
    {
        int valueRd = valueFrom + (rand() % (valueTo - valueFrom + 1));
        arr[i] = valueRd;
    }
}

/**
 * Function: Them tu dong cac phan tu tang dan vao mang
 *      int arr: Mang so nguyen can them phan tu vao
 *      int size: Kich thuoc mang
 *      int valueStart: Gia tri dau tien trong mang.
 *      int valueFrom: Gia tri them phai lon hon gia tri nay
 *      int valueTo: Gia tri them phai nho hon gia tri nay
 *      int quantityFrom: So luong phan tu can tao nho nhat
 *      int quantityTo:  So luong phan tu can tao lon nhat
 * Return: void
*/
void autoInsertToArrayArrayAndSorted(int arr[], int &size, int valueStart, int valueFrom, int valueTo, int quantityFrom, int quantityTo)
{
    int quantityRd = quantityFrom + (rand() % (quantityTo - quantityFrom + 1));
    size = quantityRd;
    for (int i = 0; i < quantityRd; i++)
    {
        if (i == 0)
        {
            int valueRd = 0;
            do
            {
                valueRd = valueFrom + (rand() % (valueTo - valueFrom + 1));
                if (valueRd <= 130)
                {
                    arr[i] = valueRd;
                    break;
                }
            } while (valueRd > 130);
        }
        else
        {
            arr[i] = 0;
            while (arr[i] < arr[i - 1])
            {
                int nextValue = valueFrom + (rand() % (valueTo - valueFrom + 1));
                int greaterThan = nextValue - arr[i - 1];
                if (nextValue > arr[i - 1] && greaterThan <= 15)
                {
                    arr[i] = nextValue;
                    break;
                }
            }
        }
    }
}

/**
 * Function: In danh sach ca phan tu co trong mang
 *      int arr: Mang so nguyen can them phan tu vao
 *      int size: Kich thuoc cua mang
 * Return: void
*/
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << " ] \n";
}


/**
 * Function: Tim phan tu voi thuat toan tim kiem tuyen tinh
 *      int arr: Mang so nguyen can them phan tu vao
 *      int size: Kich thuoc cua mang
 *      int key: So can tim trong mang
 * Return: boolean - Neu tim thay return true, nguoc lai return false.
*/
bool findElementWithLinearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return true;
        }
    }
    return false;
}


/**
 * Function: Tim phan tu voi thuat toan tim kiem nhi phan
 *      int arr: Mang so nguyen can them phan tu vao
 *      int size: Kich thuoc cua mang
 *      int key: So can tim trong mang
 * Return: boolean - Neu tim thay return true, nguoc lai return false.
*/
bool findElementWithBinarySearch(int arr[], int size, int key)
{
    int leftIndex = 0;
    int rightIndex = size;
    while (leftIndex <= rightIndex)
    {
        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (key == arr[midIndex])
            return true;

        if (key > arr[midIndex])
            leftIndex = midIndex + 1;
        else
            rightIndex = midIndex - 1;
    }
    return false;
}

/**
 * Function: Tim phan tu voi thuat toan tim kiem noi suy
 *      int arr: Mang so nguyen can them phan tu vao
 *      int startIndex: index dau tien cua mang
 *      int endIndex: index cuoi cung cua mang
 *      int key: So can tim trong mang
 * Return: boolean - Neu tim thay return true, nguoc lai return false.
*/
bool findElementWithInterpolationSearch(int arr[], int startIndex, int endIndex, int key)
{
    if (startIndex <= endIndex && key >= arr[startIndex] && key <= arr[endIndex]) {
        int pos = startIndex + (((double)(endIndex - startIndex) / (arr[endIndex] - arr[startIndex])) * (key - arr[startIndex]));

        if (arr[pos] == key)
            return true;

        if (arr[pos] < key)
            return findElementWithInterpolationSearch(arr, pos + 1, endIndex, key);

        if (arr[pos] > key)
            return findElementWithInterpolationSearch(arr, startIndex, pos - 1, key);
    }
    return false;
}

#define MAX 1000;
int main(int argc, char const *argv[])
{
    srand(time(0));

    int size1 = MAX;
    int arr1[size1];
    int size2 = MAX;
    int arr2[size2];

    // Cau 1: Add tu dong phan tu vao mang
    autoInsertElementToArray(arr1, size1, 100, 999, 30, 50);



    // Cau 2. Tao mang tang tu dong sap xep tang dan
    autoInsertToArrayArrayAndSorted(arr2, size2, 130, 100, 999, 30, 50);



    // Cau 3: Xuat mang
    cout << "Cau 1. Gia tri tu dong cua mang: " << endl;
    cout << "Array1 [" << size1 << "] = ";
    printArray(arr1, size1);
    cout << "\n\n";

    cout << "Cau 2. Tao mang tang tu dong: " << endl;
    cout << "Array2 [" << size2 << "] = ";
    printArray(arr2, size2);
    cout << "\n\n";



    // Cau 4: Tim kiem gia tri su dung tim kiem tuyen tinh
    int key1 = 0;
    cout << "Cau 4. Nhap phan tu muon tim bang tuyen tinh (Dung array 1): ";
    cin >> key1;
    bool resultFind = findElementWithLinearSearch(arr1, size1, key1);
    if (resultFind)
        cout << "=> Co " << key1 << " trong mang." << endl;
    else
        cout << "=> Khong tim thay " << key1 << " trong mang." << endl;
    cout << "\n\n";



    // Cau 5: Tim kiem gia tri su dung tim kiem nhi phan
    int key2 = 0;
    cout << "Cau 5. Nhap phan tu muon tim bang nhi phan (Dung array 2): ";
    cin >> key2;
    bool resultFind2 = findElementWithBinarySearch(arr2, size2, key2);
    if (resultFind2)
        cout << "=> Co " << key2 << " trong mang." << endl;
    else
        cout << "=> Khong tim thay " << key2 << " trong mang." << endl;
    cout << "\n\n";



    // Cau 6: Tim kiem su dung thuat toan tim kiem noi suy
    int key3 = 0;
    cout << "Cau 6. Nhap phan tu muon tim bang noi suy (Dung array 2): ";
    cin >> key3;
    bool resultFind3 = findElementWithInterpolationSearch(arr2, 0, size2 - 1, key3);
    if (resultFind3)
        cout << "=> Co " << key3 << " trong mang." << endl;
    else
        cout << "=> Khong tim thay " << key3 << " trong mang." << endl;

    return 0;
}
