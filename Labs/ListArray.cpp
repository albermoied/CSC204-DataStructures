#include<iostream>
#include<conio.h>
using namespace std;
class LinkedList
{
    public:
        LinkedList(){
            size = 0;
            head = -1;
            tail = -1;
        }
        LinkedList(int s){
            size= s;
            head = -1;
            tail = -1;
            mem =  new int[size];
            init();
        }
        void init(){
            int i=0;
            while(i<size){
                mem[i] = 0;
                i++;
            }
        }
        void insertAtStart(int z){
            if(head < size){

                if(head == -1){
                    mem[++head] = z;
                    tail = head;
                }
                else{
                     mem[++tail] = z;
                }
            }
        }

        void deleteAtStart(){
            if(head != -1 && head <= tail ){
                mem[head++]=0;
            }
            else{
                cout<<"stack is already empty";
            }
        }
        int getHead(){
            return head;
        }
        int getHeadElement(){
            return mem[head];
        }
        void display(){
            if(head!= -1 && head < size){
                int i = head;
                while(i >= 0){
                    cout<<mem[i]<<endl;
                    i--;
                }
            }
            cout<<endl<<endl;
        }
        void displayMem(){
           cout<<"Memory ...... "<<endl;
           cout<<"head = "<<head<<endl;
            cout<<"Tail = "<<tail<<endl;
           int i = size-1;
           while(i >= 0){
              cout<<i<<".  "<< mem[i]<<endl;
              i--;
           }
            cout<<endl<<endl;
        }

    private:
        int size;
        int * mem;
        int head;
        int tail;
};
int main(){
    LinkedList st(8);
    st.displayMem();
    st.insertAtStart(8);
    st.insertAtStart(12);
    st.insertAtStart(23);
    st.insertAtStart(5);
    st.displayMem();
    st.insertAtStart(13);
    st.insertAtStart(28);
    st.display();
    st.deleteAtStart();
    cout<<"After deleteAtStart head Element "<<endl;
    st.display();
    st.displayMem();
    st.deleteAtStart();
    cout<<"After deleteAtStart head Element "<<endl;
    st.display();
    st.displayMem();
   getch();
   return 0;
}

