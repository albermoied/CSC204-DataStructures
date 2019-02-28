#include<iostream>
#include<conio.h>
using namespace std;
class Stack
{
    public:
        Stack(){
            size = 0;
            top = -1;
        }
        Stack(int s){
            size= s;
            top = -1;
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
        void push(int z){
            if(top < size){

                if(top == -1){
                    mem[++top] = z;
                }
                else
                    mem[++top] = z;
            }
        }

        void pop(){
            if(top != -1 ){
                mem[top--]=0;
            }
            else{
                cout<<"stack is already empty";
            }
        }
        int getTop(){
            return top;
        }
        int getTopElement(){
            return mem[top];
        }
        void display(){
            if(top!= -1 && top < size){
                int i = top;
                while(i >= 0){
                    cout<<mem[i]<<endl;
                    i--;
                }
            }
            cout<<endl<<endl;
        }
        void displayMem(){
           cout<<"Memory ...... "<<endl;
           cout<<"Top = "<<top<<endl;
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
        int top;
};
int main(){
    Stack st(8);
    st.displayMem();
    st.push(8);
    st.push(12);
    st.push(23);
    st.push(5);
    st.displayMem();
    st.push(13);
    st.push(28);
    st.display();
    st.pop();
    cout<<"After Pop Top Element "<<endl;
    st.display();
    st.displayMem();
    st.pop();
    cout<<"After Pop Top Element "<<endl;
    st.display();
    st.displayMem();
   getch();
   return 0;
}

