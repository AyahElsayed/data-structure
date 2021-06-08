#include <iostream>

using namespace std;

struct book
{
    string name;
    string author;
    int pages;
    double price;
};

int main()
{
    // book b1 = {"book1", "author1", 255, 29.99};
    // anothor way =>
    // book b1;
    // b1.name = "book1";
    // b1.author = "author1";
    // b1.pages = 255;
    // b1.price = 29.99;

    // user enter data
    book b1;
    cout << "Enter the book name: ";
    cin >> b1.name;

    cout << b1.name;

    // array of data
    book books[10];
    books[0].name = "book1";
    cout << books[0].name;
    return 0;
}