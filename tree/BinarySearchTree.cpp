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

    // recursive code
    int getHeightHelper(node *temp){
        if(temp == nullptr){
            return -1;
        }
        else{
            int leftSubTree = getHeightHelper(temp->left);
            int rightSubTree = getHeightHelper(temp->right);
            return 1 + max(leftSubTree , rightSubTree);
        }
    }

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

    int getMax()
    {
        node *temp = root;
        while (temp->right != nullptr)
        {
            temp = temp->right;
        }
        return temp->data;
    };

    int getMin()
    {
        node *temp = root;
        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        return temp->data;
    };

    int getHeight(){
        if(root == nullptr){
            return -1;
        }
        else{
            return getHeightHelper(root);
        }
    }
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

    cout << "max " << obj.getMax() << endl;
    cout << "min " << obj.getMin() << endl;

    cout<< "Height: " << obj.getHeight() << endl;

    return 0;
}