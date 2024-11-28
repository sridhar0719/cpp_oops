#include<iostream>
using namespace std;
int main()
{
	int a[]={-1,0,1,2,-1,-4};
	int n=sizeof(a)/sizeof(a[0]);
	bool found=false;
	int i,j,k;
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]==0)
				{
					cout<<a[i]<<a[j]<<a[k]<<endl;
					found=true;
				}
			}
		}
	}
	if(!found)
	{
		cout<<"not found"<<endl;
	}
}
