#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void EnQueue(Node **head, int data)
{
    Node *temp = *head;
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {

        while (temp->next != NULL)
        {

            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int DeQueue(Node **head)
{
    int data = -1;
    Node *temp = *head;
    if (*head == NULL)
    {
        cout << "Queue Empty Exception" << endl;
    }
    else if (temp->next == NULL)
    {
        data = temp->data;
        *head = NULL;
    }
    else
    {

        data = temp->data;
        Node *temp1 = *head;

        *head = temp->next;
        free(temp1);
    }
    return data;
}

int main()
{

    Node *head = NULL;
    DeQueue(&head);
    EnQueue(&head, 10);
    EnQueue(&head, 20);
    EnQueue(&head, 30);
    cout << DeQueue(&head) << endl;
    cout << DeQueue(&head) << endl;
    cout << DeQueue(&head) << endl;
    cout << DeQueue(&head) << endl;
    EnQueue(&head, 50);
    cout << DeQueue(&head) << endl;
    cout << DeQueue(&head) << endl;
    return 0;
}
