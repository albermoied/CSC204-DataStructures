#include<iostream>
#include<conio.h>
using namespace std;

class Node
{
    private:
            int data;
            int next;
    public:
            Node()
            {
                data=0;
                next=-1;
            }
            Node(int d)
            {
                data=d;
                next=-1;
            }
            void setData(int d)
            {
                data=d;
            }
            int getData()
            {
                return data;
            }
            void setNext(int n)
            {
                next=n;
            }
            int getNext()
            {
                return next;
            }
};


class LinkedList
{
    private:
            int size;
            int head;
            Node* mem;
};
