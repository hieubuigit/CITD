#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int randomData(int min, int max)
{
    return min + (rand() % (max - min + 1));
}

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

int main(int argc, char const *argv[])
{
    srand(time(0));

    for (int i = 0; i < 100; i++)
    {
        cout << randomData(1, 100) << " ";
    }

    return 0;
}
