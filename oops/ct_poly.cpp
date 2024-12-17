#include<iostream>
#include<string>
using namespace std;
class student
{
	public:
		string name;
		student()
		{
			cout<<"defult\n";
		}
		student(string n)

		{  name==n;
			cout<<"parameterized\n";
		}
};
int main()
{
	student();
}
