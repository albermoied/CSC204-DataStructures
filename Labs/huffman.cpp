#include<iostream>
#include<conio.h>

using namespace std;

class HuffmanNode
{
private:

    HuffmanNode *left;
    HuffmanNode *right;
    char ch;
    int weight;

public:
    HuffmanNode()
    {
        ch ='\0';
        setWeight(0);
        setRight(NULL);
        setLeft(NULL);
    }
    HuffmanNode(char c,int w)
    {
        setChar(c);
        setWeight(w);
        setRight(NULL);
        setLeft(NULL);
    }
    void setChar(char c)
    {
        ch = c;
    }
    void setWeight(int w)
    {
        weight = w;
    }
    void setRight(HuffmanNode * r)
    {
        right = r;
    }
    void setLeft(HuffmanNode * lft)
    {
        left = lft;
    }
    char getChar()
    {
        return ch;
    }
    int getWeight()
    {
        return weight;
    }
    HuffmanNode *& getLeft()
    {
       return left;
    }
    HuffmanNode *& getRight()
    {
       return right;
    }
    void display()
    {
        cout<<ch<<" : "<<weight<<endl;
    }

};

void sortHuffman(HuffmanNode hfMain [], int s){

    int i = 0;
    while(i < s)
    {
        int j = i;
        while(j < s)
        {
            HuffmanNode temp;
            if(hfMain[i].getWeight() > hfMain[j].getWeight())
            {
                temp = hfMain[i];
                hfMain[i] = hfMain[j];
                hfMain[j] = temp;
            }
            j++;
        }
        i++;
    }
}
int main()
{
    HuffmanNode hf1('A',2);
    HuffmanNode hf2('B',1);
    HuffmanNode hf3('C',1);
    HuffmanNode hf4('D',3);
    HuffmanNode hf5('E',4);
    HuffmanNode hfMain [] = {hf1,hf2,hf3,hf4,hf5};

    for(int i=0; i<5; i++)
    {
        hfMain[i].display();
    }

    cout<<endl<<endl;

    sortHuffman(hfMain,5);

    for(int i=0; i<5; i++)
    {
        hfMain[i].display();
    }

    getch();
    return 0;
}
