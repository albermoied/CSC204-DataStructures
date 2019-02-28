
#include<iostream>
#include<conio.h>

using namespace std;
class Node
{
private:
    int coef;
    int exp;
    Node * next;
public:
    Node()
    {
        coef = 0;
        exp = 0;
        next = NULL;
    }
    Node(int c,int e)
    {
        coef = c;
        exp =  e;
        next = NULL;
    }
    void display()
    {
        if(exp != 0)
        {
            cout<<coef<<"X ^ "<<exp<<" + ";
        }
        else
        {
            cout<<coef<<"  ";
            cout<<endl;
        }

    }
    int getCoef()
    {
        return coef;
    }
    void setCoef(int c)
    {
        coef = c;
    }
    int getExp()
    {
        return exp;
    }
    void setExp(int e)
    {
        exp = e;
    }
    Node* getNext()
    {
        return next;
    }
    void setNext(Node* d)
    {
        next = d;
    }
};
class Polynomial
{
private:
    Node *head;

public:
    Polynomial()
    {
        head = NULL;
    }
    Node* getHead()
    {
        return head;
    }
    void insert(int x,int y)
    {
        Node * n = new Node(x,y);
        if(head == NULL)
        {
            head = n;
        }
        else
        {
           Node * temp = head;
            while(temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
            temp->setNext(n);
        }
    }

    Polynomial add(Polynomial p)
    {
        Polynomial result;
        Node * temp1 = getHead();
        Node * temp2 = p.getHead();
        while(temp1!= NULL && temp2 != NULL)
        {
            if(temp1->getExp() == temp2->getExp())
            {
                result.insert(temp1->getCoef()+temp2->getCoef(),temp1->getExp());
                 temp1 = temp1->getNext();
                 temp2 = temp2->getNext();
            }
            else{
                  if(temp1->getExp() > temp2->getExp())
                  {
                     result.insert(temp1->getCoef(),temp1->getExp());
                     temp1 = temp1->getNext();
                  }
                 else
                  {
                     result.insert(temp2->getCoef(),temp2->getExp());
                     temp2 = temp2->getNext();
                  }
            }


        }
        return result;
    }


    void display()
    {
        Node * temp = head;
        while(temp != NULL)
        {
           temp->display();
           temp = temp->getNext();
        }
    }

};
int main()
{
  Polynomial p1;
  p1.insert(2,2);
  p1.insert(5,1);
  p1.insert(7,0);
  p1.display();
  Polynomial p2;
  p2.insert(4,2);
  p2.insert(9,1);
  p2.insert(6,0);
  p2.display();
  Polynomial p3 = p1.add(p2);
  p3.display();
  cout<<endl<<endl;
  Polynomial p4;
  p4.insert(3,3);
  p4.insert(5,2);
  p4.insert(9,1);
  p4.insert(6,0);
  p4.display();
  Polynomial p5;
  p5.insert(4,3);
  p5.insert(7,1);
  p5.insert(3,0);
  p5.display();
  Polynomial p6 = p4.add(p5);
  p6.display();
  getch();
  return 0;
}
