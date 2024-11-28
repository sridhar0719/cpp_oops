#include<iostream>
using namespace std;
int main()
{
	int a[]={2,4,5,3,7,9};
	int i,j;
	int t=9;
	bool found=false;
	int n=sizeof(a)/sizeof(a[0]);
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(a[i]+a[j]==t)
			{
				cout<<"the pair is found: ["<<i<<","<<j<<"]"<<endl;
				found=true;
			}
		}
	}
	if(!found)
	{
		cout<<"no pair is found"<<endl;
	}
}
