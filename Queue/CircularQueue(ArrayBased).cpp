#include <stdio.h>
#include <iostream>
#define SIZE 10
using namespace std;

class CircularQueue
{

    int a[SIZE];
    int MAX, rear, front;

  public:
    CircularQueue(int size)
    {
        MAX = size;
        rear = -1;
        front = -1;
    }

    void EnQueue(int data)
    {
        if (((rear + 1) % MAX) == front)
        {
            cout << "Queue full exception" << endl;
        }

        else if (rear == -1 && front == -1)
        {
            front = 0;
            rear = 0;
            a[rear] = data;
        }
        else
        {
            rear = (rear + 1) % MAX;
            a[rear] = data;
        }
    }

    void DeQueue()
    {

        if ((rear == -1 && front == -1))
        {

            cout << "Queue empty exception" << endl;
        }
        else if (rear == front)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
};

int main()
{

    CircularQueue q(5);
    q.DeQueue();
    q.EnQueue(5);
    q.EnQueue(6);
    q.EnQueue(7);
    q.EnQueue(7);
    q.EnQueue(7);
    q.EnQueue(7);
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.DeQueue();
    q.EnQueue(4);
    q.DeQueue();
    return 0;
}