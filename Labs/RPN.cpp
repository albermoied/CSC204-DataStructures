#include<iostream>
#include<conio.h>
using namespace std;

int main()
{
    float store;
    float a=0,sum=0,no,small=0,big=0,avg=0;
    
	cout<<"enter postive float value(-1 to exit)";
	cin>>no;
	while(no<=0)
	{
		a++;
		store=no;
		sum=sum+no;
		cout<<"enter postive float value(-1 to exit)";
		cin>>no;
		if(store<no)
			small=store;
		else
			small=no;
		if(store>no)
			big=store;
		else
			big=no;            
    }
	avg=sum/a;
	cout<<"avg is :"<<avg;
	cout<<endl<<"the min value is :"<<small;
	cout<<endl<<"the max value is:"<<big;

	return 0;
}
