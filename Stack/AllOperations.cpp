#include <iostream>
#include <stdio.h>
using namespace std;

class Stack
{

    int top, MAX;
    int s[100];

  public:
    Stack(int size)
    {
        top = -1;
        MAX = size;
    }

    void Push(int data)
    {
        if (top >= MAX)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {

            s[++top] = data;
        }
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "Stack  Underflow" << endl;
        }
        else
        {
            return s[top];
        }
    }

    int Pop()
    {

        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {

            int x = s[top];
            top--;
            return x;
        }
    }

    bool isStackEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    bool isStackFull()
    {
        if (top == MAX)
            return true;
        else
            return false;
    }

    void display()
    {

        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
        }
        for (int i = 0; i < MAX; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    Stack s(5);
    cout << s.isStackEmpty() << endl;
    cout << s.Pop() << endl;
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Push(5);
    s.Push(6);
    cout << s.isStackFull() << endl;
    cout << s.Pop() << endl;
    cout << s.isStackEmpty() << endl;
    cout << s.Top() << endl;

    s.display();
    return 0;
}