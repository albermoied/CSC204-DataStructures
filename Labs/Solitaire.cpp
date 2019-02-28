#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>

using namespace std;
string type[] = {"spade","club","heart","diamond"};
string color[] = {"black","red"};
class Card
{
      private:
              int num;
              int clr, tp;
              string suit, color;
              Card* next;
      public:
             Card()
             {
                   num=0;
                   suit="";
                   color="";
                   next=NULL;
             }
             Card(int i, int c)
             {
                  num=i;
                  if(c==1)
                  {
                     clr = 0;
                      tp = c;    
                    suit="Spades";
                   color="Black";}
                  else if(c==2)
                  {
                      clr = 0;
                      tp = c; 
                       suit="Clubs";
                   color="Black";}
                  else if(c==3)
                  {
                       clr = 1;
                       tp = c;
                       suit="Hearts";
                   color="Red";}
                  else if(c==4)
                  {
                       clr=1;
                       tp=c;
                       suit="Diamonds";
                   color="Red";}
                  next=NULL;
             }
             void setNext(Card* c)
             {
                  next=c;
             }
             Card* getNext()
             {
                  return next;
             }
             void display()
             {
                  cout<<num<<"  "<<color[clr]<<"  "<<type[tp-1]<<endl;
                  /*if(num==1)
                  {cout<<"Ace of ";}
                  else if(num>1 && num<11)
                  {cout<<num<<" of ";}
                  else if(num==11)
                  {cout<<"Jack of ";}
                  else if(num==12)
                  {cout<<"Queen of ";}
                  else if(num==13)
                  {cout<<"King of ";}
                  cout<<suit<<endl;*/
                  cout<<"*****************"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*               *"<<endl;
                  cout<<"*****************"<<endl;
             }
};

class Deck
{
      private:
              int d[52];
              Card* top;
      public:
             Deck()
             {
                  int i=0;
                  while(i<52)
                  {
                       d[i]=1;
                       i++;
                  }
             }
             Card* getCard()
             {
                  srand(time(NULL));
                  int i= rand() % 52;
                  int j=1;
                  while(j==1)
                  {
                       if(i>=0 && i<=12 && d[i]==1)
                       {
                            Card* c = new Card(i+1,1);
                            d[i]=0;
                            j=0;
                            return c;
                       }
                       else if(i>=13 && i<=25 && d[i]==1)
                       {
                            Card* c = new Card(i-12,2);
                            d[i]=0;
                            j=0;
                            return c;
                       }
                       else if(i>=26 && i<=38 && d[i]==1)
                       {
                            Card* c = new Card(i-25,3);
                            d[i]=0;
                            j=0;
                            return c;
                       }
                       else if(i>=39 && i<=51 && d[i]==1)
                       {
                            Card* c = new Card(i-38,4);
                            d[i]=0;
                            j=0;
                            return c;
                       }
                       i=rand() % 52;
                  }
             }
};

class Stack
{
    public:
        Stack()
        {
            top = NULL;
        }
        void push(Card* n)
        {
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
        
        Card * getTop()
        {
            return top;
        }
        void display()
        {
            Card * temp = getTop();
            int n=1;
            while(temp != NULL)
            {
                cout<<n<<". ";
                temp->display();
                temp = temp->getNext();
                n++;
            }
            cout<<endl<<endl;
        }

    private:
        Card * top;
};

class Queue
{
    private:
            Card *head;
            Card *last;
    public:
            Queue()
            {
                head=last=NULL;
            }
            void insertAtEnd(Card* n)
            {
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
            
            void display()
            {
                Card * temp=head;
                int i=1;
                while(temp!=NULL)
                {
                    cout<<i<<". ";
                    temp->display();
                    temp=temp->getNext();
                    i++;
                }
                cout<<endl<<endl;
            }
};

int main()
{
    Deck d;
    int i=0;
    Stack a1,a2,a3,a4,a5,a6,a7;
    Queue a8;
    a1.push(d.getCard());
    while(i<2)
    {a2.push(d.getCard());
     i++;}
     i=0;
     while(i<3)
    {a3.push(d.getCard());
     i++;}
     i=0;
     while(i<4)
    {a4.push(d.getCard());
     i++;}
     i=0;
     while(i<5)
    {a5.push(d.getCard());
     i++;}
     i=0;
     while(i<6)
    {a6.push(d.getCard());
     i++;}
     i=0;
     while(i<7)
    {a7.push(d.getCard());
     i++;}
    a1.display();
    a2.display();
    a3.display();
    a4.display();
    a5.display();
    a6.display();
    a7.display();
    i=0;
    while(i<24)
    {
     a8.insertAtEnd(d.getCard());
     i++;
    }
    a8.display();
    getch();
    return 0;
}
