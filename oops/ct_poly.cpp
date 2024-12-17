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

		{  njame=n;
			cout<<"parameterized\n";
		}
};
int main()
{
	student();
}
