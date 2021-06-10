// queue linked list implementation

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *front = NULL;
node *rear = NULL;

void enqueue(int value);
void dequeue();
int peek();
void display();

int main()
{
    enqueue(1);;
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    display(); // 1 2 3 4 5
    dequeue();
    display(); // 2 3 4 5
    cout<< "peek = "<<peek();

    return 0;
}

void enqueue(int value)
{
    node *new_node = new node;
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL)
    {
        front = rear = new_node;
    }
    else
    {
        rear->next = new_node;
        rear = new_node;
    }
};

void dequeue()
{
    if (rear == NULL)
    {
        cout << "queue is empty. \n";
    }
    else if(front == rear){
        // only one node
        node * ptr = front;
        front = rear = NULL;
        delete(ptr);
    }
    else{
        node * ptr = front;
        front = front->next;
        delete(ptr);
    }
};

int peek(){
    if (rear == NULL)
    {
        cout << "queue is empty. \n";
        return -1;
    }
    else{   
        return front->data;
    }
};

void display(){
    if (front == NULL)
    {
        cout << "queue is empty. \n";
    }
    else{
        node * current = front;
        while (current != NULL){
            cout << current->data <<"\t";
            current = current->next;
        }
        cout << endl;
    }
};


