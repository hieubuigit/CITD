#include <iostream>
using namespace std;

int main()
{
    // int a[] = {1,3,5,7,9,2,4,6,8};
    // cout << *(a + 3) << endl;
    // cout << *(a + 7) << endl;
    // cout << *(a + 3) + *(a + 7);

    // cout << "--------------------\n";

    // int a = 102, b, *p;
    // p = &a;
    // b = (*p)++;
    // cout << *p << endl;
    // cout << a << " _ " << b;


    // cout << "cout: " << NULL << endl;

    // double *a = new double[10];
    // a[0] = 9.3; a[1] = 6.1;
    // cout << *a << endl;


    int value = 2023;
    int *p = &value;
    cout << *p << endl;


    return 0;
}
