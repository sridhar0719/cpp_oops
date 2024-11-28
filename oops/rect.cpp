#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;  
    double width;  

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double area() {
        return length * width;
    }

    
    double perimeter() {
        return 2 * (length + width);
    }

    /*void setLength(double l) {
        length = l;
    }

    void setWidth(double w) {
        width = w;
    }

    double getLength() {
        return length;
    }

    double getWidth() {
        return width;
    } */
};

int main() {
    double length, width;

    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    Rectangle rect(length, width);

    cout << "Area of the rectangle: " << rect.area() << endl;
    cout << "Perimeter of the rectangle: " << rect.perimeter() << endl;

    return 0;
}

