#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

class Node{
private:
    string data1;
    int data2;
    Node * next1,*next2;

public:
    Node(){
        data1 = "";
        data2 = 0;
        next1 = NULL;
        next2 = NULL;
    }
    Node(string st,int d){
        data1 = st;
        data2 = d;
        next1 = NULL;
        next2 = NULL;
    }
    void setData1(string d1){
        data1 = d1;
    }
    void setData2(int d2){
        data2 = d2;
    }
    int getData2(){
        return data2;
    }
    string getData1(){
        return data1;
    }
    void setNext1(Node* n){
        next1 = n;
    }
    void setNext2(Node* n){
        next2 = n;
    }
    Node * getNext1(){
        return next1;
    }
    Node * getNext2(){
        return next2;
    }
    void display(){
        cout<<data1<<"   "<<data2<<endl;
    }
};
class MList{
private:
    Node * first1, *first2;
public:
    MList(){

    }
    void insert(string d1,int d2){
        Node * newNode = new Node(d1,d2);
        insertById(newNode);
        insertByString(newNode);
    }
    void insertById(Node *n){
        if(first2 == NULL){
            first2 = n;
        }
        else{
            Node * curr = first2;
            Node * prev = NULL;
            while(curr != NULL &&
                  curr->getData2()<n->getData2()){
                prev = curr;
                curr = curr->getNext2();
            }
            if(prev == NULL){
                n->setNext2(first2);
                first2 = n;
            }
            else{
                n->setNext2(curr);
                prev->setNext2(n);
            }
        }

    }
    void insertByString(Node *n){


    }
    void display(){
            Node * curr = first2;
            Node * prev = NULL;
            while(curr != NULL ){
                curr->display();
                curr = curr->getNext2();
            }
    }



};
int main(){
    MList ml;
    ml.insert("Adams",1537);
    ml.insert("John",1197);
    ml.insert("Doe",2057);
    ml.insert("Smith",1987);
    ml.display();
    getch();
    return 0;
}
