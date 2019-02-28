#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

template <class ElementType>
class Node
{
    public:
        Node()
        {
            data=0;
            next=NULL;
        }
        Node(ElementType d)
        {
            data = d;
            next = NULL;
        }
        void display()
        {
            cout<<data<<"  ";
        }
        ElementType getData()
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
        void setNext(Node *n)
        {

            next = n;
        }
    private:
        ElementType data;
        Node * next;
};

template <class Type>
class Stack
{
    private:
        Node<Type> * top;
    public:
        Stack()
        {
            top = NULL;
        }
        void push(Type x)
        {
            Node<Type> * n = new Node<Type>(x);
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
                Node<Type> * temp = top;
                top = top->getNext();
                temp->setNext(NULL);
                delete temp;
                temp = NULL;
            }
            else
                cout<<"Stack Already Empty ";
        }
        Node<Type> * getTop()
        {
            return top;
        }
        Type getTopElement()
        {
            return top->getData();
        }
        void display()
        {
            Node<Type> * temp = getTop();
            while(temp != NULL)
            {
                temp->display();
                temp = temp->getNext();
            }
            cout<<endl;
        }
};

class Student
{
    private:
            int id;
            string name;
    public:
            Student()
            {
                id=0;
                name="";
            }
            Student(int i, string s)
            {
                id=i;
                name=s;
            }
            void display()
            {
                cout<<id<<"  "<<name<<"    ";
            }
};

int main()
{
    Node<int> n(7);
    n.display();
    Node<float> m(8.8);
    m.display();
    cout<<endl;
    Stack<int> s;
    s.push(66);
    s.push(89);
    s.push(55);
    s.display();
    Stack<float> f;
    f.push(9.9);
    f.push(6.3);
    f.push(3.6);
    f.display();
    Student x(345,"Bob"), y(001,"Mike"), z(880,"Ehhhhh");
    Stack<Student> a;
    a.push(x);
    a.push(y);
    a.push(z);
    //a.display();
    getch();
    return 0;
}
