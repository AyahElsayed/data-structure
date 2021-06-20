#include <iostream>
#include <queue>
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
    int getHeightHelper(node *temp)
    {
        if (temp == nullptr)
        {
            return -1;
        }
        else
        {
            int leftSubTree = getHeightHelper(temp->left);
            int rightSubTree = getHeightHelper(temp->right);
            return 1 + max(leftSubTree, rightSubTree);
        }
    };

    void preOrder(node *temp)
    {
        if (temp == nullptr)
            return;

        cout << temp->data << " ";
        preOrder(temp->left);
        preOrder(temp->right);
    };

    node *removeHelper(node *root , int data){
        if(root == nullptr) return root;
        else if (data < root->data){
            root->left = removeHelper(root->left , data);
        }
        else if (data > root->data){
            root->right = removeHelper(root->right , data);
        }
        else{
            if(root->left == nullptr){
                node * temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == nullptr){
                node * temp = root->left;
                delete root;
                return temp;
            }
            else{
                int maxValue = this->getMax();
                root ->data = maxValue;
                root->left = removeHelper(root->left , maxValue);
            }
        }
        return root;
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

    int getHeight()
    {
        if (root == nullptr)
        {
            return -1;
        }
        else
        {
            return getHeightHelper(root);
        }
    };

    void display_levelOrder()
    {
        if (root == nullptr)
            return;
        queue<node *> q;
        q.push(root);

        while (!q.empty())
        {
            node *current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        cout << endl;
    };

    void display_preOrder()
    {
        if (root != nullptr)
            preOrder(root);
    };

    void remove(int data){
        root = removeHelper(root , data);
    }
};

int main()
{
    BST obj;
    obj.add(15);
    obj.add(6);
    obj.add(20);
    obj.add(3);
    obj.add(9);
    obj.add(8);
    obj.add(25);

    // cout << "max " << obj.getMax() << endl;
    // cout << "min " << obj.getMin() << endl;

    // cout<< "Height: " << obj.getHeight() << endl;

    // cout << "level order" << obj.display_levelOrder() << endl;
    obj.display_preOrder();
    obj.remove(3);
    obj.display_preOrder();

    return 0;
}

/*
preorder => root , left , right
inorder => left , root , right
postorder => left , right , root
*/