#include<iostream>
#include<string>
using namespace std;
class person
{
	public:
		string name="sai";
		int age=23;
		 person()
		 {
		 }
		 void getinfo()
		 {
			 cout<<"name of person:"<<name<<endl;
			 cout<<"age of person:"<<age<<endl;
		 }
};
class student : public person
{
	public:
		int rool;
		void getinfo()
		{
			cout<<"name:"<<name<<endl;
			cout<<"age:"<<age<<endl;
			cout<<"rool no:"<<rool<<endl;
		}
};
int main()
{      person p1;
	p1.getinfo();
	student s1;
	s1.name="sridhar";
		s1.age=23;
		s1.rool=95;
        s1.getinfo();
}
