// simple queue array implementation;

#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int value);
void dequeue();
int peek();
void display();


int main()
{
    enqueue(5);
    enqueue(10);
    enqueue(15);

    display();

    dequeue();

    display();

    cout << "peek = " <<peek();


    return 0;
}

void enqueue(int value)
{
    if (rear != SIZE - 1)
    {
        if (front == -1 && rear == -1)
        {
            front++;
            queue[++rear] = value;
        }
        else
        {
            queue[++rear] = value;
        }
    }
    else
    {
        cout << "queue is full \n";
    }
};

void dequeue()
{
    if (front != -1 && rear != -1 && front <= rear)
    {
        front++;
    }
    else
    {
        cout << "queue is empty. \n";
    }
};


int peek(){
    if (front != -1 && rear != -1 && front <= rear)
    {
        return queue[front];
    }
    else
    {
        cout << "queue is empty. \n";
    }
};

void display(){
    if (front != -1 && rear != -1 && front <= rear)
    {
        for(int i = front ; i <= rear; i++){
            cout << queue[i] << "\t";
        }
        cout << endl;
    }
    else
    {
        cout << "queue is empty. \n";
    }
};


