#include<iostream>
#include<conio.h>
using namespace std;

template <class ElementType>
class BSTNode
{
public:
    BSTNode()
    {
        setData(0);
        setDef(0);
        setRight(NULL);
        setLeft(NULL);
    }
    BSTNode(ElementType d, ElementType e)
    {
        setData(d);
        setDef(e);
        setRight(NULL);
        setLeft(NULL);
    }
    void setData(ElementType d)
    {
        data = d;
    }
    void setDef(ElementType d)
    {
        def = d;
    }
    void setRight(BSTNode * r)
    {
        right = r;
    }
    void setLeft(BSTNode * lft)
    {
        left = lft;
    }
    ElementType getData()
    {
        return data;
    }
    ElementType getDef()
    {
        return def;
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
        cout<<data<<" : "<<def;
    }
private:

    BSTNode *left;
    BSTNode *right;
    ElementType data,def;
};

template<class Type>
class BST
{
public:
    BST()
    {
        root = NULL;
    }
    void insert(BSTNode<Type> *&r,Type d,Type e)
    {
        if(r == NULL)
        {
            BSTNode<Type> * n = new BSTNode<Type>(d,e);
            r = n;
        }
        else if(r->getData() < d)
        {
            insert(r->getRight(),d,e);
        }
        else
        {
            insert(r->getLeft(),d,e);
        }
    }
    BSTNode<Type> *& parentNode(BSTNode<Type> *&r,BSTNode<Type> *&p,Type d,Type e)
    {
        if(r->getData() == d)
        {
            return p;
        }
        else if(r->getData() < d)
        {
            return parentNode(r->getRight(),r,d,e);
        }
        else
        {
            return parentNode(r->getLeft(),r,d,e);
        }
    }
    int getNodeStatus(BSTNode<Type> *&r)
    {
        int status =0;
        if(r->getLeft()==NULL && r->getRight()==NULL)
        {
             BSTNode<Type> * n = parentNode(getRoot(),getRoot(),r->getData());
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
    BSTNode<Type> *& getNode(BSTNode<Type> *&r,Type d,Type e)
    {
        if(r->getData() == d)
        {
            return r;
        }
        else if(r->getData() < d)
        {
            return getNode(r->getRight(),d,e);
        }
        else
        {
            return getNode(r->getLeft(),d,e);
        }
    }
    void displayInOrder(BSTNode<Type> *&r)
    {
        if(r != NULL)
        {
            displayInOrder(r->getLeft());
            r->display();
            cout<<endl;
            displayInOrder(r->getRight());
        }
    }
    BSTNode<Type> *& getRoot()
    {
        return root;
    }
private:
    BSTNode<Type> * root;
};

int main()
{
   BST<string> bst;
   bst.insert(bst.getRoot(),"LOL","Laugh out loud.");
   bst.insert(bst.getRoot(),"WHY","Questioning the reasoning behind something.");
   bst.insert(bst.getRoot(),"RAGE","An emotion that usually ends with bloody knuckles.");
   bst.insert(bst.getRoot(),"HOME","A place where I belong~");
   bst.insert(bst.getRoot(),"FORCES","Powers at work around us.");
   bst.insert(bst.getRoot(),"SUPERCALIFRAGILISTICEXPIALODOCIOUS","... HAHAHAHAHA No.");
   bst.insert(bst.getRoot(),"JoJo","A MANLY BADASS.");
   bst.displayInOrder(bst.getRoot());
   getch();
   return 0;
}
