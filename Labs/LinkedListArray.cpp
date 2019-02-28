#include<iostream>
#include<conio.h>
using namespace std;

class LinkedList
{
    public:
            LinkedList()
            {
                size=0;
                head=0;
            }
            LinkedList(int s)
            {
                size=s;
                head=0;
                mem = new int[size];
                init();
            }
            void init()
            {
                int i=0;
                while(i<size)
                {
                    mem[i] = 0;
                    i++;
                }
            }
            void insertAtEnd(int d)
            {
                int i = 0;
                if(mem[0]==0)
                {
                    mem[0]=d;
                }
                else
                {
                    while(mem[i]!=0 && i<size)
                    {
                        i++;
                    }
                    mem[i]=d;
                }
            }
            /*void insertAtBeg(int d)
            {
                if(mem[0]==0)
                {
                    mem[0]=d;
                }

                while()
            }*/
            void display()
            {
                int i=0;
                while(i<size)
                {
                    cout<<mem[i]<<"  ";
                    i++;
                }
                cout<<endl;
            }
    private:
            int size;
            int head;
            int* mem;
};


int main()
{
    LinkedList a(5);
    a.insertAtEnd(4);
    a.insertAtEnd(8);
    a.insertAtEnd(88);
    a.insertAtEnd(76);
    a.insertAtEnd(20);
    a.display();
    getch();
    return 0;
}
