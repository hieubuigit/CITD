#include <iostream>
using namespace std;

void pointerWithVariable() {
    int a = 100;
    cout << "Location of a = " << &a << endl;
    cout << "Value at location of a = " << a << endl;
}

int main(int argc, char const *argv[])
{
    // 1. Pointer with variable
    pointerWithVariable();

    // 2. Pointer with array
    // 3. Pointer with function
    // 4. Pointer with object

    return 0;
}
