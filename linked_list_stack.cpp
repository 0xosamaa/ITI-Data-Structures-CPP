#include <iostream>

class stack
{
    struct node
    {
        int item;
        node *next;
    };

    node *top;
    node *current;

public:
    stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int newItem)
    {
        node *newItemPtr = new node;
        if (newItemPtr == NULL)
        {
            std::cout << "Stack push cannot allocate memory\n";
        }
        else
        {

            newItemPtr->item = newItem;
            newItemPtr->next = top;
            top = newItemPtr;
        }
    }

    void pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack is emppty on pop\n";
        }
        else
        {
            node *temp = top;
            top = top->next;
            temp = temp->next = NULL;
            delete temp;
        }
    }

    void getTop(int &stackTop)
    {
        if (isEmpty())
        {
            std::cout << "Stack is emppty on getTop\n";
        }
        else
        {
            stackTop = top->item;
        }
    }

    void display()
    {
        current = top;
        while (current != NULL)
        {
            std::cout << current->item << std::endl;
            current = current->next;
        }
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(2);
    s.pop();
    s.push(3);

    s.display();
    return 0;
}