#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
    private:
            int data;
            Node* next;
    public:
            Node()
            {
                data=0;
                next=NULL;
            }
            Node(int d)
            {
                data=d;
                next=NULL;
            }
            void setData(int d)
            {
                data=d;
            }
            int getData()
            {
                return data;
            }
            void setNext(Node* n)
            {
                next=n;
            }
            Node* getNext()
            {
                return next;
            }
};

class Queue
{
    private:
            Node *head;
            Node *last;
    public:
            Queue()
            {
                head=last=NULL;
            }
            void insertAtEnd(int d)
            {
                Node *n = new Node(d);
                if(head==NULL&&last==NULL)
                {
                    head=last=n;
                }
                else
                {
                    last->setNext(n);
                    last=n;
                }
            }
            void deleteAtBeg()
            {
                if(head!=NULL)
                {
                    Node * temp=head;
                    head=head->getNext();
                    temp->setNext(NULL);
                    delete temp;
                    temp=NULL;
                }
                else
                {
                    cout<<"Already empty."<<endl;
                }
            }
            void display()
            {
                Node * temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->getData()<<"  ";
                    temp=temp->getNext();
                }
                cout<<endl;
            }
};

int main()
{
    Queue a;
    a.insertAtEnd(33);
    a.insertAtEnd(77);
    a.insertAtEnd(55);
    a.display();
    a.deleteAtBeg();
    a.display();
    getch();
    return 0;
}
