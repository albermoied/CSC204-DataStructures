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
            cout<<coef<<"X ^ "<<exp;
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
    int Size;

public:
    Polynomial()
    {
        head = NULL;
        Size = 0;
    }
    void setSize(int d)
    {
        Size = d;
    }
    int getSize()
    {
        return Size;
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
        Size++;
    }

    Polynomial add(Polynomial p)
    {
        Polynomial result;
        Node * temp1 = getHead();
        Node * temp2 = p.getHead();
        while(temp1 != NULL || temp2 != NULL)
        {
        	if(temp1 != NULL && temp2 != NULL)
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
	        else
	        {
	        	if(temp1 != NULL)
	        	{
	        		result.insert(temp1->getCoef(),temp1->getExp());
	        		temp1 = temp1->getNext();
	        	}
	        	else if(temp2 != NULL)
	        	{
	        		result.insert(temp2->getCoef(),temp2->getExp());
	        		temp2 = temp2->getNext();
	        	}
	        }
	}
        return result;
    }
Polynomial sub(Polynomial p)
    {
        Polynomial result;
        Node * temp1 = getHead();
        Node * temp2 = p.getHead();
        while(temp1!= NULL || temp2 != NULL)
        {
            if(temp1->getExp() == temp2->getExp())
            {
                result.insert(temp1->getCoef()-temp2->getCoef(),temp1->getExp());
                 temp1 = temp1->getNext();
                 temp2 = temp2->getNext();
            }
            else{
                  if(temp1->getExp() > temp2->getExp())
                  {
                     result.insert(temp1->getCoef(),temp1->getExp());
                     temp1 = temp1->getNext();
                  }
                 if(temp1->getExp() < temp2->getExp())
                  {
                     result.insert(temp2->getCoef(),temp2->getExp());
                     temp2 = temp2->getNext();
                  }
            }


        }
        return result;
    }
	void setHead(Node * h)
	{
		head = h;
	}
    Polynomial mul(Polynomial p)
    {
        //Polynomial result[2];
        int s = p.getSize();
        Polynomial result[s];
        Node * temp1 = getHead();
        Node * temp2 = NULL;
        Polynomial m;
		int i = 0;
        while(temp1 != NULL)
        {
            temp2 = p.getHead();
            result[i].setHead(NULL);
            while(temp2 != NULL)
            {
                result[i].insert(temp1->getCoef() * temp2->getCoef(), temp1->getExp() + temp2->getExp());
                //cout<<endl<<temp1->getCoef() * temp2->getCoef()<<" X ^ "<< temp1->getExp() + temp2->getExp()<<endl;
                temp2 = temp2->getNext();
            }
            temp1=temp1->getNext();
            i++;
        }

        while(i < s)
        {
            result[0] = result[0].add(result[i]);
            i++;
        }
        m = result[0].add(result[1]);
        return result;
    }

    void display()
    {
        Node * temp = getHead();
        while(temp != NULL)
        {
           temp->display();
           if(temp->getNext() != NULL)
           {
           	  cout<<" + ";
           }
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
   p2.insert(8,0);
  p2.display();
  //Polynomial p3 = p1.add(p2);
  //Polynomial p7 = p1.sub(p2);
  Polynomial p8 = p1.mul(p2);
  cout<<endl;
  //p3.display();
  cout<<endl;
  //p7.display();
  cout<<endl<<endl<<endl;
  p8.display();
  cout<<endl<<endl;
  /*Polynomial p4;
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
  p6.display();*/
  getch();
  return 0;
}

