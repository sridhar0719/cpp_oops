#include<iostream>
#include<string>
using namespace std;
class person
{  public:
	int age;
	string name;
};
class student : public person
{
	public:
		int roll;
};
class ug : public student
{
	public:
		int poy;
		string subject;
		void getinfo()
		{
			cout<<"name:"<<name<<endl;
			cout<<"age:"<<age<<endl;
			cout<<"roll:"<<roll<<endl;
			cout<<"passed out year:"<<poy<<endl;
			cout<<"subject:"<<subject<<endl;
		}
};
int main()
{
	ug u1;
	u1.name="sridhar";
	u1.age=24;
	u1.roll=19;
	u1.poy=2021;
	u1.subject="ECE";
	u1.getinfo();
}
