#include<iostream>
using namespace std;
class Circle {
	int radius=3;
	public:
	Circle(int r)
	{
		radius=r;
	}
	double area()
	{
		return 3.14*radius*radius;
	}
	double circufrance()
	{
		return 2*3.14*radius;
	}
	void setRadius(double r)
	{
		radius=r;
	}
	double getRadius()
	{
		return radius;
	}
};
int main()
{    Circle mycircle(3);
	cout<<"area of cricle"<<mycircle.area()<<endl;
	cout<<"circumfrance of cricle"<<mycircle.circufrance()<<endl;
}
