#include <iostream>

using namespace std;

int main()
{
    int x = 20;
    int* ptr = &x;

    cout << *ptr <<"\n"; // 20
    cout << ptr <<"\n"; // address

    *ptr = 25;
    cout << *ptr <<"\n" ; // 25

    // create pointer in one line 
    // ======================
    
    int* ptr2 = new int(50) ;
    
    cout << *ptr2 <<"\n" ; // 50

    
    return 0;
}