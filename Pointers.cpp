#include <iostream>
using namespace std;

int main() {
    int num = 10; 
    int* ptr = &num; 

    cout << "Initial value of num: " << num << endl;
    cout << "Pointer pointing the value: " << *ptr << endl;

    *ptr = 20; 

    cout << "Final value of num: " << num << endl;
    cout << "Pointer now points to value: " << *ptr << endl;

    return 0;
}
