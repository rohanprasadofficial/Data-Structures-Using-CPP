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

void PreorderIterative(BinaryTreeNode *t)
{

    stack<BinaryTreeNode *> s;

    while (!s.empty() || (t != NULL))
    {

        if (t != NULL)
        {

            cout << t->data;
            s.push(t);
            t = t->leftSubTree;
        }
        else
        {

            t = s.top();
            s.pop();
            t = t->rightSubTree;
        }
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

    cout << "The Preorder Traversal is" << endl;
    PreorderIterative(root);
    cout << endl;

    return 0;
}