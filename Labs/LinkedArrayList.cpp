#include<iostream>
#include<conio.h>
using namespace std;

class Node{

  private:
          int data;
          int next;
  public:
         Node(){
            data = 0;
            next = -2;
         }
         Node(int d){
            data = d;
            next = -2;
         }
         void setData(int d){
              data = d;
         }
         void setNext(int n){
              next = n;
         }
         int getData(){
             return data;
         }
         int getNext(){
             return next;
         }
         void display(){
              cout<<data<<"  ";
         }

};
class AList{
      private:
            Node * mem;
            int size,space;
            int head;
            int free;
      public:
             AList(){
             }
             AList(int s){
               size = s;
               space = s;
               head = -1;
               free = 0;
               mem = new Node[size];
              // for(int i=0; i<size; i++)
               //        mem[i] = new Node();
             }
             void insert(int x){
                  if(head == -1){
                     head = free++;
                     mem[head].setData(x);
                     mem[head].setNext(-1);
                  }
                  else{
                       int curr = head;
                       int prev = -1;
                       while(mem[curr].getData()<x
                           && curr != -1){
                            prev = curr;
                            curr = mem[curr].getNext();
                       }
                       if(prev == -1){
                            mem[free].setData(x);
                            mem[free].setNext(head);
                            head = free++;
                       }
                       else{
                            mem[prev].setNext(free);
                            mem[free].setData(x);
                            mem[free++].setNext(curr);
                       }
                  }
                space--;
             }
             void display(){
                  int temp = head;
                  while(temp != -1 ){
                      mem[temp].display();
                      temp = mem[temp].getNext();
                  }

             }
             void displayMem(){
                  int temp = 0;
                  cout<<"\n\nData "<<"   "<<"Next "<<endl;
                  while(temp < size ){
                    cout<<mem[temp].getData()<<"       "<<mem[temp].getNext()<<endl;
                    temp++;
                  }

             }
             void deleteElement(int x){
               int curr = head;
               int prev = -1;
               while(mem[curr].getData() != x
                      && curr != -1){
                   prev = curr;
                   curr = mem[curr].getNext();
               }
               if(prev == -1){
                   mem[head].setData(0);
                   int temp = head;
                   head = mem[head].getNext();
                   mem[temp].setNext(-2);
               }
               else{
                   mem[prev].setNext(mem[curr].getNext());
                   mem[curr].setData(0);
                   mem[curr].setNext(-2);
               }

                space++;
             }
};

int main(){
    AList list(10);
    list.insert(9);
    list.insert(25);
    list.insert(16);
    list.insert(76);
    list.insert(3);
    list.insert(21);
    list.display();
    list.displayMem();
    cout<<endl<<endl;
    list.deleteElement(21);
    list.display();
    list.displayMem();
    cout<<endl<<endl;
    list.deleteElement(3);
    list.display();
    list.displayMem();
    cout<<endl<<endl;
    list.deleteElement(76);
    list.display();
    list.displayMem();
getch();
return 0;
}
