#include<iostream>
#include<conio.h>
using namespace std;
class BSTNode
{
public:
    BSTNode()
    {
        setData(0);
        setRight(NULL);
        setLeft(NULL);
    }
    BSTNode(int d)
    {
        setData(d);
        setRight(NULL);
        setLeft(NULL);
    }
    void setData(int d)
    {
        data = d;
    }
    void setRight(BSTNode * r)
    {
        right = r;
    }
    void setLeft(BSTNode * lft)
    {
        left = lft;
    }
    int getData()
    {
        return data;
    }
    BSTNode *& getLeft()
    {
       return left;
    }
    BSTNode *& getRight()
    {
       return right;
    }
    void display()
    {
        cout<<data<<" ";
    }
private:

    BSTNode *left;
    BSTNode *right;
    int data;
};
class BST
{
public:
    BST()
    {
        root = NULL;
    }
    void insert(BSTNode *&r,int d)
    {
        if(r == NULL)
        {
            BSTNode * n = new BSTNode(d);
            r = n;
        }
        else if(r->getData() < d)
        {
            insert(r->getRight(),d);
        }
        else
        {
            insert(r->getLeft(),d);
        }
    }
    BSTNode *& parentNode(BSTNode *&r,BSTNode *&p,int d)
    {
        if(r->getData() == d)
        {
            return p;
        }
        else if(r->getData() < d)
        {
            return parentNode(r->getRight(),r,d);
        }
        else
        {
            return parentNode(r->getLeft(),r,d);
        }
    }
    int getNodeStatus(BSTNode *&r)
    {
        int status =0;
        if(r->getLeft()==NULL && r->getRight()==NULL)
        {
             BSTNode * n = parentNode(getRoot(),getRoot(),r->getData());
             if(n->getLeft()==r)
             {
                               n->setLeft(NULL);
                               delete r;
             }
             else if(n->getRight()==r)
             {
                 n->setRight(NULL);
                 delete r;
             }
        }
        else if((r->getLeft()!=NULL && r->getRight()==NULL)||(r->getLeft()==NULL && r->getRight()!=NULL))
        {
             status =1;
        }
        else if(r->getLeft()!=NULL && r->getRight()!=NULL)
        {
             status =2;
        }
        return status;
    }
    BSTNode *& getNode(BSTNode *&r,int d)
    {
        if(r->getData() == d)
        {
            return r;
        }
        else if(r->getData() < d)
        {
            return getNode(r->getRight(),d);
        }
        else
        {
            return getNode(r->getLeft(),d);
        }
    }

    void displayInOrder(BSTNode *&r)
    {
        if(r != NULL)
        {
            displayInOrder(r->getLeft());
            r->display();
            displayInOrder(r->getRight());
        }
    }
    BSTNode *& getRoot()
    {
        return root;
    }
private:
    BSTNode * root;
};
int main()
{
   BST bst;
   bst.insert(bst.getRoot(),29);
   bst.insert(bst.getRoot(),19);
   bst.insert(bst.getRoot(),39);
   bst.insert(bst.getRoot(),49);
   bst.insert(bst.getRoot(),20);
   bst.displayInOrder(bst.getRoot());
   cout<<endl<<endl<<"Parent of 9 is";
   BSTNode *p = bst.parentNode(bst.getRoot(),bst.getRoot(),20);
   cout<<p->getData();
   BSTNode *n = bst.getNode(bst.getRoot(),20);
   int status = bst.getNodeStatus(n);
   cout<<endl<<endl<<" Data "<<n->getData()<<endl;
   cout<<"Status "<<status<<endl;
   bst.displayInOrder(bst.getRoot());


   getch();
   return 0;
}
