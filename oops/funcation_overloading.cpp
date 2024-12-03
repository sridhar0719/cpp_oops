#include<iostream>
using namespace std;
class print
{
	public:
		void show(int a)
		{
			cout<<"integer funcation:int valuse is 4"<<a<<endl;
		}
		void show(char c)
		{
			cout<<"character funcation "<<c<<endl;
		}
};
int main()
{     print p1;
	p1.show(101);
	p1.show('A');
}

