#include<iostream>
#include<string>
using namespace std;

class person {
    private:
        string name = "sridhar";
        int age = 24;
        string counter = "india";

    public:
        void setPerson(string n, int a, string c) {
            name = n;
            age = a;
            counter = c;
        }
        void getPerson() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Country: " << counter << endl;
        }
};

int main() {
    person p1;
    p1.getPerson(); 
}

