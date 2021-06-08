#include <iostream>

using namespace std;

union box
{
    double weight;
    double height;
};

int main()
{
    box b1;
    b1.weight = 20;
    b1.height = 30;

    cout<< b1.weight << endl; // 30
    cout<< b1.height ;        // 30
    // union save only one value in the memory (the last one)  
    
    return 0;
}