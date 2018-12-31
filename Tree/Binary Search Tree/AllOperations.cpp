#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *leftSubTree;
    Node *rightSubTree;
};

Node *newNode(int key)
{
    Node *newNode = new Node();
    newNode->data = key;
    newNode->leftSubTree = NULL;
    newNode->rightSubTree = NULL;
    return newNode;
}

void Insert(Node **root, int key)
{
    Node *temp = newNode(key);
    // cout << temp->data;
    if (*root == NULL)
    {
        *root = temp;
        return;
    }
    else if ((*root)->data == key)
    {
        cout << "Data already exist" << endl;
        return;
    }
    else if ((*root)->data > key)
        Insert(&(*root)->leftSubTree, key);
    else
        Insert(&(*root)->rightSubTree, key);
}

void DisplayPreOrder(Node *root)
{

    if (root == NULL)
        return;
    DisplayPreOrder(root->leftSubTree);
    cout << root->data << " ";
    DisplayPreOrder(root->rightSubTree);
}

int main()
{
    Node *root = NULL;

    /* We are gonna create a tree like this 

            20
           /  \
          10    30
         / \    /  \
        5   15  25 40
*/
    Insert(&root, 20);
    Insert(&root, 10);
    Insert(&root, 30);
    Insert(&root, 5);
    Insert(&root, 15);
    Insert(&root, 25);
    Insert(&root, 40);
    DisplayPreOrder(root);

    return 0;
}