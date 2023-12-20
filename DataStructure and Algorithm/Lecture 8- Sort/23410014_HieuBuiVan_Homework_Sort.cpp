/**
 * Created by: Hieu Bui Van
 * Student ID: 23410014
 * Class: LT.2023.1
 * Lecture 8
 * Description: Homework sort algorithms: selection sort, insert sort, and calculate time execuse sort algorithm.
 */

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

#define SORT_ASC 0
#define SORT_DESC 1
#define MAX 100000

#define SELECTION_SORT 0
#define INSERTION_SORT 1

/**
 * Function: Tao tu dong mang chua so thuc, gioi han 3 chu so sau dau cham
 *      double arr[]: Mang can sap xep
 *      int &size: Kich thuoc cua mang
 */
void autoGenerateElementToArray(double arr[], int &size)
{
    for (int i = 0; i < size; i++)
    {
        double value = 0.1 + ((double)rand() / RAND_MAX) * (99.9 - 0.1);
        double formatVal = round(value * 1000) / 1000; // get 3 number after point
        arr[i] = formatVal;
    }
}

/**
 * Function: Selection sort
 *      double arr[]: Mang can sap xep
 *      int &size: Kich thuoc cua mang
 *      int  sortOption: ASC = 0, DESC = 1. Default = 0
 */
void selectionSort(double arr[], int &size, int sortOption = SORT_ASC)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (sortOption == SORT_ASC)
            {
                if (arr[j] < arr[i])
                {
                    double temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
            else
            {
                if (arr[j] > arr[i])
                {
                    double temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

/**
 * Function: Insertion sort
 *      double arr[]: Mang can sap xep
 *      int &size: Kich thuoc cua mang
 *      int  sortOption: ASC = 0, DESC = 1. Default = 0
 */
void insertionSort(double arr[], int &size, int sortOption = SORT_ASC)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;

        if (sortOption == SORT_ASC)
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j -= 1;
            }
        }
        else
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j -= 1;
            }
        }
        arr[j + 1] = key;
    }
}

void printArray(double arr[], int &size)
{
    cout << "Array[" << size << "] = [ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << " ] \n\n";
}

/**
 * Function: Ham get thoi gian thuc hien cac thuat toan sap xep
 *      double arr[]: Mang can sort
 *      int &size: Kich thuoc cua mang
 *      int  sortAlgorithm: 0 for selection sort, 1 for intersion sort.
 *      int  sortOption: ASC = 0, DESC = 1
 */
float getTimeExecuse(double arr[], int &size, int sortAlgorithm, int sortOption = SORT_ASC)
{
    if (sortAlgorithm == SELECTION_SORT)
    {
        clock_t duration = clock();
        selectionSort(arr, size, sortOption);
        duration = clock() - duration;
        return (float)duration / CLOCKS_PER_SEC;
    }
    else
    {
        clock_t duration = clock();
        insertionSort(arr, size, sortOption);
        duration = clock() - duration;
        return (float)duration / CLOCKS_PER_SEC;
    }
}

int main(int argc, char const *argv[])
{
    srand(time(0));

    // Cau 1: Tao tu dong 100000 so thuc cho array, goi han 3 chu so sau dau cham
    int size = MAX;
    double arr1[size];
    autoGenerateElementToArray(arr1, size);


    // Cau 2: Xuat mang
    cout << "\n Array 1: ";
    printArray(arr1, size);


    // Cau 3: Dung selection sort de sap xep mang
    // ASC
    selectionSort(arr1, size, SORT_ASC);
    cout << "\n Selection Sort (ASC): ";
    printArray(arr1, size);

    // DESC
    selectionSort(arr1, size, SORT_DESC);
    cout << "\n Selection Sort (DESC): ";
    printArray(arr1, size);

    int size2 = MAX;
    double arr2[size2];
    autoGenerateElementToArray(arr2, size2);
    cout << "\n Array 2: ";
    printArray(arr2, size2);


    // Cau 4: Tinh thoi gian thuc hien sap xep mang tang/giam bang selection sort
    float durationOfSelectionSortASC = getTimeExecuse(arr1, size, SELECTION_SORT);
    cout << "Time for selection sort ASC = " << durationOfSelectionSortASC << " s \n";
    float durationSelectionSortDESC = getTimeExecuse(arr1, size, SELECTION_SORT, SORT_DESC);
    cout << "Time for selection sort DESC = " << durationSelectionSortDESC << " s \n";


    // Cau 5: Dung insertion sort de sap xep array
    // ASC
    insertionSort(arr2, size2, SORT_ASC);
    cout << "\n Insertion Sort (ASC): ";
    printArray(arr2, size2);

    // DESC
    insertionSort(arr2, size2, SORT_DESC);
    cout << "\n Insertion Sort (DESC): ";
    printArray(arr2, size2);


    // Cau 6: Tinh thoi gian thuc hien sap xep mang tang/giam bang insertion sort
    float durationOfInsertionSortASC = getTimeExecuse(arr2, size2, SELECTION_SORT);
    cout << "Time for selection sort ASC = " << durationOfInsertionSortASC << " s \n";
    float durationOfInsertionSortDESC = getTimeExecuse(arr2, size2, SELECTION_SORT, SORT_DESC);
    cout << "Time for selection sort DESC = " << durationOfInsertionSortDESC << " s \n";

    return 0;
}
