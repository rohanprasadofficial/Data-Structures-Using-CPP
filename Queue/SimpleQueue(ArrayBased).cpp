#include <stdio.h>
#include <iostream>
#define SIZE 100
using namespace std;

class Queue
{

    int MAX, rear, front;
    int a[SIZE];

  public:
    Queue(int size)
    {
        front = -1, rear = -1;
        MAX = size;
    }

    void EnQueue(int data)
    {

        if (rear == MAX)
        {
            cout << " Full Queue Exception " << endl;
        }
        else
        {

            if (front == -1)
                front++;
            rear++;
            a[rear] = data;
            cout << data << " Inserted at position " << rear << endl;
        }
    }

    int DeQueue()
    {

        if (rear == -1 || front > rear)
        {
            cout << "Queue empty exception" << endl;
            return -1;
        }
        else
        {
            int item = a[front];
            front++;
            return item;
        }
    }

    int Front()
    {

        if (front == -1 || front > rear)
        {
            cout << "Queue empty exception " << endl;
            return -1;
        }
        else
        {
            return a[front];
        }
    }

    int QueueSize()
    {

        return (rear - front + 1);
    }

    bool isQueueEmpty()
    {

        if (front > rear || rear == -1)
        {
            return true;
        }
        return false;
    }
};

int main()
{

    Queue q(5);
    int t = q.DeQueue();
    q.EnQueue(5);
    cout << q.QueueSize() << endl;
    cout << q.isQueueEmpty() << endl;
    t = q.DeQueue();
    cout << t << endl;
    t = q.Front();
    cout << t << endl;
    cout << q.QueueSize() << endl;
    cout << q.isQueueEmpty() << endl;

    return 0;
}