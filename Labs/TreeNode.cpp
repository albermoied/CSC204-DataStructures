#include<iostream>
#include<conio.h>

using namespace std;

class Node
{
    private:
            int data;
            Node* left;
            Node* right;
    public:
            Node()
            {
                data=0;
                left=NULL;
                right=NULL;
            }
            Node(int d)
            {
                data=d;
                left=NULL;
                right=NULL;
            }
            int getData()
            {
                return data;
            }
            void setData(int d)
            {
                data=d;
            }
            Node* getLeft()
            {
                return left;
            }
            void setLeft(Node* n)
            {
                left=n;
            }
            Node* getRight()
            {
                return right;
            }
            void setRight(Node* n)
            {
                right=n;
            }
            void display()
            {
                cout<<data<<" Left: "<<left<<" Right: "<<right;
            }
};

class BinaryST
{
    private:
            Node* root;
    public:
            BinaryST()
            {
                root=NULL;
            }
            Node* getRoot()
            {
                return root;
            }
            void insert(Node *&r, int d)
            {
                if(r==NULL)
                {
                    Node* n= new Node(d);
                    r=n;
                }
                else if(r->getData() < d)
                {
                    insert(r->getLeft(), d);
                }
                else
                {
                    insert(r->getRight(), d);
                }
            }

};

int main()
{
    getch();
    return 0;
}
