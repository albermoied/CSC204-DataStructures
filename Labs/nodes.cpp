#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
private:
    int data;
    Node * next;
public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int d)
    {
        data = d;
        next = NULL;
    }
void display()
    {
        cout<<data<<" , "<<next<<endl;
    }
int getData()
{
    return data;
}
void setData(int d)
{
    data = d;
}
Node * getNext()
{
    return next;
}
void setNext(Node * d)
{
    next = d;
}
};
class List
{
private:
    Node * head;
public:
    List()
    {
        head = NULL;
    }
    void insert(int x)
    {
        Node * n = new Node(x);
        if(head == NULL)
        {
            head = n;
        }
        else
        {
            Node * temp = head;
            while(temp -> getNext()!=NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(n);
        }
    }
    void display()
    {
        Node * temp = head;
            while(temp!=NULL)
            {
                cout<<temp->getData()<<" ";
                temp = temp->getNext();
            }
    }
};

int main()
{
    List l;
    l.insert(8);
    l.insert(15);
    l.insert(19);
    l.insert(28);
    l.display();
    getch();
    return 0;
}
