#include <iostream>
#include <stdio.h>
#include "NodeStructure.h"
using namespace std;

void deleteAtBegining(Node **head)
{

    Node *temp = *head;
    if (head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {

        if (temp->next == NULL)
        {
            free(temp);
            *head = NULL;
        }
        else
        {
            *head = temp->next;
            free(temp);
        }

        cout << "Node Deleted" << endl;
    }
}

void deleteAtEnd(Node **head)
{

    Node *temp, *temp1 = *head;
    if (*head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp1 = temp;
            temp = temp->next;
        }
        temp1->next = NULL;
        free(temp);
    }
}

void deleteGivenNode(Node **head, int data)
{

    if (*head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        Node *temp, *temp1 = *head;
        if (temp->data == data)
        {
            *head = temp->next;
            free(temp);
        }

        else
        {
            while (temp->data != data && temp->next == NULL)
            {
                temp1 = temp;
                temp = temp->next;
            }

            if (temp->next == NULL)
                return;

            temp1->next = temp->next;
            free(temp);
            cout << "Deleted" << endl;
        }
    }
}

void insertAtBeginning(Node **head, int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->next = NULL;

    if (*head == NULL)
    {
        *head = temp;
        cout << "Inserted at the beginning" << endl;
    }
    else
    {
        temp->next = *head;
        *head = temp;
        cout << "Inserted at the beginning" << endl;
    }
}

void insertAtEnd(Node **head, int data)
{
    Node *temp = new Node();
    temp->next = NULL;
    temp->data = data;

    Node *trav = *head;

    if (*head == NULL)
    {
        *head = temp;
        cout << "Inserted at the end" << endl;
    }
    else
    {
        while (trav->next != NULL)
        {
            trav = trav->next;
        }
        trav->next = temp;
        cout << "Inserted at the end" << endl;
    }
}

void displayList(Node **head)
{
    if (*head == NULL)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        cout << "The List is" << endl;
        Node *temp = *head;
        while (temp != NULL)
        {
            cout << temp->data << "-->";
            temp = temp->next;
        }
        cout << endl;
    }
}

void insertAfteraNode(Node **head, int presentNodeData, int data)
{

    Node *temp = *head;
    while (temp->data != presentNodeData)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            cout << "Given Node data not present in the list" << endl;
            return;
        }
    }

    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    Node *head = NULL;

    insertAtEnd(&head, 23);
    displayList(&head);

    insertAtBeginning(&head, 9);
    displayList(&head);

    insertAfteraNode(&head, 23, 2332);
    displayList(&head);

    insertAtEnd(&head, 4345);
    displayList(&head);
    deleteAtBegining(&head);
    displayList(&head);
    deleteAtEnd(&head);
    displayList(&head);

    insertAtEnd(&head, 111);
    displayList(&head);

    insertAtEnd(&head, 222);
    displayList(&head);

    insertAtEnd(&head, 333);
    displayList(&head);
    deleteGivenNode(&head, 111);
    displayList(&head);

    /*
    Node *n = new Node();
    n->data = 5;
    cout << n->data << endl;*/

    return 0;
}