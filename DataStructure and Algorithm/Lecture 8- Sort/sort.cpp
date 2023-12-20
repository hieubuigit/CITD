/**
 * Created by: Hieu Bui Van
 * Student ID: 23410014
 * Class: LT.2023.1
 * Description: Sort
 */

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

void selectionSort(int arr[], int size) {
    int firstSorted = arr[0];
}

void insertionSort(int arr[], int size) {

}

void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int size = 10;
    int testArr[size] = {12, 43, 89, 18, 9, 12, 900, 100, 76, 5};



    printArr(testArr, size);

    return 0;
}
