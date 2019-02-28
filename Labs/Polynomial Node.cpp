#include<iostream.h>
#include<conio.h>

using namespace std;

class Node
{
      private:
              int coeff,exp;
              Node *next;
      public:
             Node()
             {
                   coeff=0;
                   exp=0;
                   next=NULL;
             }
             Node(int c, int e)
             {
                   coeff=c;
                   exp=e;
                   next=NULL;
             }
             int getCof()
             {
                 return coeff;
             }
             int getExp()
             {
                 return exp;
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
                  cout<<coeff<<"x^"<<exp<<endl;
             }
};

class Polynomial
{
      private:
              Node *head;
      public:
             Polynomial()
             {
                  head=NULL;
             }
             void insert(int c, int e)
             {
                  Node *n = new Node(c,e);
                  if(head==NULL)
                  {
                       head=n;
                  }
                  else
                  {
                      Node * temp = head;
                      while(temp->getNext()!=NULL)
                      {
                           temp=temp->getNext();
                      }
                      temp->setNext(n);
                  }
             }
             void display()
             {
                  Node * temp=head;
                  while(temp!=NULL)
                  {
                      cout<<temp->getCof()<<"x^"<<temp->getExp()<<" + ";
                      temp = temp->getNext();
                  }
                  cout<<" 0 ";
             }
};

int main()
{
    Node a(2,4);
    a.display();
    Polynomial p;
    p.insert(3,7);
    p.insert(5,5);
    p.insert(6,3);
    p.display();
    getch();
    return 0;
}
