#include <iostream>
using namespace std;

class BST
{
private:
    struct node
    {
        int data;
        node *left;
        node *right;
    };
    node *root = nullptr;

public:
    void add(int value)
    {
        node *newNode = new node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;

        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        node *temp = root;
        node *parent = nullptr;

        while (temp != nullptr)
        {
            parent = temp;
            if (value <= temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }

        if (value <= parent->data)
        {
            parent->left = newNode;
        }
        else
        {
            parent->right = newNode;
        }
    };

    
};

int main()
{
    BST obj;
    obj.add(8);
    obj.add(5);
    obj.add(13);
    obj.add(3);
    obj.add(7);
    obj.add(10);
    obj.add(15);

   
    return 0;
}