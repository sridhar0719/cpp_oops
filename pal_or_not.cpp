#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"enter the number:"<<endl;
	cin>>n;
	int temp=n;
	int r=0;
	while(n!=0)
	{
		r=r*10+n%10;
		n=n/10;
	}
	if(temp==r)
	{
		cout<<"same"<<endl;
	}
	else
	{
		cout<<"not"<<endl;
	}
}
