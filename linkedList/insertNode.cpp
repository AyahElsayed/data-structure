#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *head = NULL;

void inserNode(int value);
void display();
void deleteNode(int value);
void insert_beg(int value);
void delete_beg();

int main()
{
    // display();
    inserNode(5);
    inserNode(10);
    display();
    delete_beg();
    display();

    return 0;
}

void inserNode(int value)
{
    node *new_node, *last;
    new_node = new node; // create pointer in one line
    new_node->data = value;

    // in case one node in the list
    if (head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
    }
    else
    {
        last = head;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }
};

void display()
{
    node *current_node;
    if (head == NULL)
    {
        cout << "Linked list is empty";
    }
    else
    {
        current_node = head;
        while (current_node != NULL)
        {
            cout << current_node->data << "\t";
            current_node = current_node->next;
        }
    }
    cout << endl;
};

void deleteNode(int value)
{
    node *current, *previous;

    current = head;
    previous = head; // initialization

    // in general and
    // in case the node i want to delete is first node
    if (current->data == value)
    {
        head = current->next;
        free(current); // delete from memory
        return;        // to stop
    }

    while (current->data != value)
    {
        previous = current;
        current = current->next;
    }
    previous->next = current->next;
    free(current);
};

void insert_beg(int value)
{
    node *new_node = new node;
    new_node->data = value;
    new_node->next = head;
    head = new_node;
};

void delete_beg()
{
    if (head == NULL)
    {
        cout << "Linked lidt is empty \n";
    }
    else
    {
        node *first_node = head;
        head = first_node->next;
        delete (first_node);
    }
};
