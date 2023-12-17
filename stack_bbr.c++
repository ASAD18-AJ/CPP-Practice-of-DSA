#include <iostream>
using namespace std;
class Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int element)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack overflow " << endl;
        }
    }
    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack underoverflow " << endl;
        }
    }
    int peek()
    {
        if (top >= 0)
            return arr[top];
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        int i;
        if (top == -1)
            cout << "stack is empty" << endl;
        else
        {
            for (i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }
    }
};
int main()
{
    Stack st(5);
    st.push(22);
    st.push(12);
    st.push(34);
    // cout << st.peek() << endl;
    st.display();
    st.pop();
    cout << "delete" << endl;
    st.display();
    if (st.isEmpty())
    {
        cout << "Stack is Empty mere dost " << endl;
    }
    else
    {
        cout << "Stack is not Empty mere dost " << endl;
    }
}