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

int leftMost(Node *root)
{
    while (root->leftSubTree->leftSubTree != NULL)
    {
        root = root->leftSubTree;
    }
    int r = root->data;
    root->leftSubTree = NULL;
    return r;
}

void deleteNode(Node *root, int data)
{
    if (root == NULL)
        return;

    if (root->data == data)
    {

        if (root->leftSubTree == NULL && root->rightSubTree == NULL)
        {
            free(root);
        }
        else if (root->leftSubTree == NULL && root->rightSubTree != NULL)
        {
            root = root->rightSubTree;
        }
        else if (root->rightSubTree == NULL && root->leftSubTree != NULL)
        {
            root = root->leftSubTree;
        }
        else
        {

            int p = leftMost(root);
            root->data = p;

            //Delete it and bring the rightmost left node out there
        }
    }
    else if (root->data < data)
    {
        deleteNode(root->rightSubTree, data);
    }
    else
    {
        deleteNode(root->leftSubTree, data);
    }
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
    cout << endl;
    deleteNode(root, 30);
    DisplayPreOrder(root);

    return 0;
}