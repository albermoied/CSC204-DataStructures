#include<iostream>
#include<conio.h>

using namespace std;

class Node
{
    private:
            int data;
            Node* prev;
            Node* next;
    public:
            Node()
            {
                data = 0;
                next = NULL;
                prev=NULL;
            }
            Node(int d)
            {
                data = d;
                next = NULL;
                prev=NULL;
            }
            void display()
            {
                cout<<prev<<" , "<<data<<" , "<<next<<endl;
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
            Node * getPrev()
            {
                return prev;
            }
            void setPrev(Node* d)
            {
                prev=d;
            }
};

class Dlist
{
    private:
            Node* head;
            Node* tail;
    public:
            Dlist()
            {
                head=NULL;
                tail=NULL;
            }
            void setHead(Node* n)
            {
                head=n;
            }
            Node* getHead()
            {
                return head;
            }
            void setTail(Node* n)
            {
                tail=n;
            }
            Node* getTail()
            {
                return tail;
            }
            void insertInt(int d)
            {
                Node* n = new Node(d);
                if(head==NULL && tail==NULL)
                {
                    head=tail=n;
                }
                else if(d < head->getData())
                {
                    n->setNext(head);
                    head->setPrev(n);
                    head=n;
                }
                else if(d > tail->getData())
                {
                    n->setPrev(tail);
                    tail->setNext(n);
                    tail=n;
                }
                else
                {
                    Node * curr=head->getNext();
                    Node * prev=head;
                    while(curr->getData() < d)
                    {
                        curr=curr->getNext();
                        prev=prev->getNext();
                    }
                    n->setNext(curr);
                    n->setPrev(prev);
                    curr->setPrev(n);
                    prev->setNext(n);
                }
            }
            void displayFor()
            {
                Node* temp=head;
                cout<<"Head = "<<head->getData()<<" and Tail = "<<tail->getData();
                cout<<endl;
                cout<<"Forward: "<<endl;
                while(temp!=NULL)
                {
                    cout<<temp->getData()<<"   ";
                    temp=temp->getNext();
                }
                cout<<endl<<endl;
            }
            void displayRev()
            {
                Node* temp=tail;
                cout<<"Head = "<<head->getData()<<" and Tail = "<<tail->getData();
                cout<<endl;
                cout<<"Reverse: "<<endl;
                while(temp!=NULL)
                {
                    cout<<temp->getData()<<"   ";
                    temp=temp->getPrev();
                }
                cout<<endl<<endl;
            }
            void deleteInt(int d)
            {
                if(head==NULL && tail==NULL)
                {
                    cout<<"List is already empty."<<endl;
                }
                else if(head->getData()==d)
                {
                    Node* temp=head;
                    temp->setNext(NULL);
                    head=head->getNext();
                    head->setPrev(NULL);
                    delete temp;
                    temp=NULL;
                }
                else if(tail->getData()==d)
                {
                    Node* temp=tail;
                    temp->setPrev(NULL);
                    tail=tail->getPrev();
                    tail->setNext(NULL);
                    delete temp;
                    temp=NULL;
                }
                else
                {
                    Node* curr=head->getNext();
                    Node* prev=head;
                    while(curr->getData()!=d && curr!=NULL)
                    {
                        curr=curr->getNext();
                        prev=prev->getNext();
                    }
                    if(curr==NULL)
                    {
                        cout<<"Data not found."<<endl;
                    }
                    else
                    {
                        Node* temp = curr->getNext();
                        prev->setNext(temp);
                        temp->setPrev(prev);
                        curr->setNext(NULL);
                        curr->setPrev(NULL);
                        delete curr;
                        curr=NULL;
                    }
                }
            }
};

int main()
{
    Dlist d;
    Dlist k;
    d.insertInt(60);
    d.insertInt(488);
    d.insertInt(5);
    d.insertInt(89);
    d.insertInt(47);
    d.displayFor();
    d.deleteInt(60);
    d.displayFor();
    k.deleteInt(9);
    d.deleteInt(47);
    d.deleteInt(89);
    d.displayFor();
    //d.deleteInt(66);
    //d.displayRev();
    getch();
    return 0;
}
