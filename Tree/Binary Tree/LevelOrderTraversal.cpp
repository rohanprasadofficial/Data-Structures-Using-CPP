#include <stdio.h>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *leftSubTree;
    BinaryTreeNode *rightSubTree;
};

void LevelOrderTraversal(BinaryTreeNode *t)
{

    queue<BinaryTreeNode *> q;

    q.push(t);
    while (!q.empty())
    {

        BinaryTreeNode *temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->leftSubTree)
            q.push(temp->leftSubTree);
        if (temp->rightSubTree)
            q.push(temp->rightSubTree);
    }
}

int main()
{

    queue<BinaryTreeNode *> q;

    BinaryTreeNode *root = new BinaryTreeNode();
    int d;
    cout << "Enter the data too  insert in the root Node" << endl;
    cin >> d;
    root->data = d;
    root->leftSubTree = NULL;
    root->rightSubTree = NULL;

    q.push(root);
    BinaryTreeNode *temp = NULL;

    while (!q.empty())
    {

        temp = q.front();
        q.pop();

        cout << "--------------------" << endl;
        cout << "Current Node = " << temp->data << endl;
        cout << "--------------------" << endl;

        cout << "Left Tree Creation" << endl;

        cout << "Enter value of left Subtree Node (-1 to Not insert)" << endl;
        int data;
        cin >> data;

        if (data != -1)
        {
            BinaryTreeNode *newNode = new BinaryTreeNode();
            newNode->data = data;
            newNode->leftSubTree = NULL;
            newNode->rightSubTree = NULL;
            temp->leftSubTree = newNode;
            cout << "Left Subtree Created" << endl;
            q.push(newNode);
        }

        cout << "Right Tree Creation" << endl;

        cout << "Enter value of Right Subtree Node (-1 to Not insert)" << endl;
        cin >> data;
        if (data != -1)
        {
            BinaryTreeNode *newNode = new BinaryTreeNode();
            newNode->data = data;
            newNode->leftSubTree = NULL;
            newNode->rightSubTree = NULL;
            temp->rightSubTree = newNode;
            cout << "Right Subtree Created" << endl;
            q.push(newNode);
        }
    }

    cout << "The Level Traversal is" << endl;

    LevelOrderTraversal(root);

    return 0;
}