#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;
class Node
{
    public:
        Node(int d)
        {
            data = d;
            next = NULL;
        }
        void display()
        {
            cout<<data<<"  ";
        }
        int getData()
        {
            return data;
        }
        Node * getNext()
        {
            return next;
        }
        void setData(Node *n)
        {
            next = n;
        }
        void setNext(Node * n)
        {

            next = n;
        }

    private:
        int data;
        Node * next;
};
class Stack
{
    public:
        Stack()
        {
            top = NULL;
        }
        void push(int x)
        {
            Node * n = new Node(x);
            if(top == NULL)
            {
                top = n;
            }
            else
            {
                n->setNext(top);
                top = n;
            }
        }
        void pop()
        {
            if(top != NULL)
            {
                Node * temp = top;
                top = top->getNext();
                temp->setNext(NULL);
                delete temp;
                temp = NULL;
            }
            else
                cout<<"Stack Already Empty ";
        }
        Node * getTop()
        {
            return top;
        }
        int getTopElement()
        {
            return top->getData();
        }
        void display()
        {
            Node * temp = getTop();
            while(temp != NULL)
            {
                temp->display();
                temp = temp->getNext();
            }
        }

    private:
        Node * top;
};
void RPN(Stack st, string expr)
{
    int i=0;
    while(expr[i]!='\0'){
        //cout<<"  "<<str[i]<<endl;
        if(expr[i] >= 48 && expr[i] <= 57)
        {
            cout<<expr[i]<<"Push in Stack "<<endl;
            int x = expr[i] - 48;
            st.push(x);
        }
        else
        {
            cout<<expr[i]<<" Operations should be applied "<<endl;
        }

        i++;
    }
    cout<<endl<<endl;
    st.display();
}
int main()
{
    Stack st;
    string str="234+*";
    RPN(st,str);

    getch();
    return 0;
}
