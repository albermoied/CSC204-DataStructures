#include <iostream>
#include <conio.h>
using namespace std;


class Node
{
      private:
              int data;
              Node *next;
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
             int getData()
             {
                 return data;
             }
             Node* getNext()
             {
                   return next;
             }
             void setNext(Node* n)
             {
                  next=n;
             }
             void display()
             {
                  cout<<data<<endl;
             }
};

class LinkedList
{
      private:
              Node *head;
      public:
             LinkedList()
             {
                  head=NULL;
             }

             Node * getHead()
             {
                 return head;
             }

             void insert(int x)
             {
                  Node * n = new Node(x);
                  if(head==NULL)
                  {
                      head=n;
                  }
                  else
                  {
                      Node * prev = NULL;
                      Node * curr = getHead();
                      while(curr!=NULL && curr->getData()<x)
                      {
                          prev=curr;
                          curr=curr->getNext();
                      }
                      if(prev==NULL)
                      {
                          n->setNext(head);
                          head=n;
                      }
                      else
                      {
                          n->setNext(curr);
                          prev->setNext(n);
                      }
                  }
             }

             void deleteFirst()
             {
                 if(head!=NULL)
                 {
                     Node* n=head;
                     head=head->getNext();
                     n->setNext(NULL);
                     delete n;
                 }
                 else
                 {
                     cout<<"List is already empty"<<endl;
                 }
             }

             void deleteLast()
             {
                 if(head!=NULL)
                 {
                     Node* prev=NULL;
                     Node* curr=head;
                     while(curr->getNext()!=NULL)
                     {
                         prev=curr;
                         curr=curr->getNext();
                     }
                     prev->setNext(NULL);
                     delete curr;
                 }
                 else
                 {
                     cout<<"List is empty."<<endl;
                 }
             }

             void deleteVal(int x)
             {
                 if(head!=NULL)
                 {
                     Node * curr=head;
                     Node * prev=NULL;
                     while(curr->getNext()!=NULL && curr->getData()!=x)
                     {
                         prev=curr;
                         curr=curr->getNext();
                     }
                     if(curr->getData()!=x&&curr->getNext()==NULL)
                     {
                         cout<<"List does not contain the given number"<<endl;
                     }
                     else
                     {
                      prev->setNext(curr->getNext());
                      curr->setNext(NULL);
                      delete curr;
                     }
                 }
                 else
                 {
                     cout<<"List is empty"<<endl;
                 }
             }

             void deleteValue(int x)
             {
                 Node* curr=head;
                 Node* prev=NULL;
                 if(head!=NULL)
                 {
                    searcher(x);
                    if(prev==NULL)
                    {
                        deleteFirst();
                    }
                    else
                    {
                        deleteVal(x);
                    }
                 }
                 else
                 {
                     cout<<"Empty list."<<endl;
                 }
             }

             void searcher(int x)
             {
                 Node* curr=head;
                 Node* prev=NULL;
                 while(curr->getNext()!=NULL && curr->getData()!=x)
                    {
                        prev=curr;
                        curr=curr->getNext();
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

class Stack
{
      private:
              Node* top;
      public:
             Stack()
             {
                    top=NULL;
             }
             void push(int x)
             {
                  Node* n = new Node(x);
                  if(top==NULL)
                  {
                       top=n;
                  }
                  else
                  {
                       n->setNext(top);
                       top=n;
                  }
             }
             void pop()
             {
                  if(top!=NULL)
                  {
                       Node* n=top;
                       top=top->getNext();
                       n->setNext(NULL);
                       delete n;
                       n=NULL;
                  }
                  else
                  {
                       cout<<"Already Empty.";
                  }
             }
             void display()
             {
                  Node *temp = getTop();
                  while(temp!=NULL)
                  {
                       temp->display();
                       temp=temp->getNext();
                  }
             }
             Node* getTop()
             {
                   return top;
             }
             int getTopElement()
             {
                 return top->getData();
             }
             Stack binaryCon(int x)
             {
                  Stack s;
                  while(x>0)
                  {
                       s.push(x%2);
                       x=x/2;
                  }
                  return s;
             }
};

int main()
{
    Stack s=s.binaryCon(12);
    s.display();
    getch();
    return 0;
}
