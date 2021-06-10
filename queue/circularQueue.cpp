// circular queue array implementation;

#include <iostream>
using namespace std;

#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

bool isEmpty();
bool isFull();

void enqueue(int value);
void dequeue();
int peek();
void display();

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    display(); // 1 2 3 4 5

    enqueue(6); // full

    dequeue();

    display(); // 2 3 4 5

    enqueue(6);

    display(); // 2 3 4 5 6

    return 0;
}

bool isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool isFull()
{
    if (front == 0 && rear == SIZE - 1)
    {
        return true;
    }
    else if (rear == front - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void enqueue(int value)
{
    if (isFull())
    {
        cout << "queue is full \n";
    }
    else
    {
        if (isEmpty())
        {
            front = rear = 0;
            queue[rear] = value;
        }
        else if (rear == SIZE - 1)
        {
            rear = 0;
            queue[rear] = value;
        }
        else
        {
            rear++;
            queue[rear] = value;
        }
    }
};

void dequeue()
{
    if (isEmpty())
    {
        cout << "queue is empty. \n";
    }
    else
    {
        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == SIZE - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
};

int peek()
{
    if (isEmpty())
    {
        cout << "queue is empty. \n";
        return -1;
    }
    else
    {
        return queue[front];
    }
};

void display()
{
    if (isEmpty())
    {
        cout << "queue is empty. \n";
    }
    else
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << "\t";
            }
            cout << endl;
        }
        else
        {
            for (int i = front; i < SIZE; i++)
            {
                cout << queue[i] << "\t";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << "\t";
            }
            cout << endl;
        }
    }
};
