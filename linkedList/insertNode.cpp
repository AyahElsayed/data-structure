#include <iostream>
using namespace std;

struct node
{
  int data;
  node* next;
};

node* head = NULL;

void inserNode(int value);

int main()
{
    
    
    return 0;
}

void inserNode(int value){
  node* new_node , *last;
  new_node = new node ; // create pointer in one line
  new_node-> data = value;

  // in case one node in the list 
  if(head == NULL){
    head = new_node;
    new_node->next = NULL;
  }
  else{
    last = head;
    while (last->next != NULL)
    {
      last = last->next;
    }
    last->next = new_node;
    new_node->next = NULL;
    
  }
};