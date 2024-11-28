#include<iostream>
#include<string>
using namespace std;
class Teacher{ 
	double slary;
	public:
	string name;
	string dept;
	string subject;
	// defult constructor or non parametrized
//	Teacher()
//	{  
//		cout<<"this is default contructor\n";
//	}
	// parametrized constructor 
     Teacher (string n,string s,string d,double  sal)
     {
          name=n;
          subject=s;
	   dept=d;
          slary=sal;
     }	  
	/*void chandept(string newdept)
	{
		dept =newdept;
	
	}
	void setSlary(double s)
	{
		slary=s;
	}
	double getSlary()
	{
		return slary;
	}
};
*/
void getInfo()
{ 
	cout<<"name:" <<name<<endl;
	cout<<"subject:" <<subject<<endl;
}
};
int main()
{
	Teacher t1("sridhar", "cpp", "ECE", 24000);
//	t1.getInfo();
	Teacher t2(t1);
	t2.getInfo();
//	t1.name="sridhar";
//	t1.dept="ECE";
  //      t1.subject="CPP";
    //    t1.setSlary(24000);
      //cout<<t1.name<<endl<<t1.getSlary()<<endl;
}
