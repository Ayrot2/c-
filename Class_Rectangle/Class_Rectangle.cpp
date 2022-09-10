
using namespace std;
#include <iostream>
#include <cmath>

class Rectangle {
    double x1, y1, x3, y3; //coordinates
public:
    Rectangle() : x1(0), y1(0), x3(0), y3(0) {}
    Rectangle(double x1, double y1, double x3, double y3) : x1(x1), y1(y1), x3(x3), y3(y3) {}

    void movement(double x, double y) 
    {
        x1 = x1 + x;
        y1 = y1 + y;
        x3 = x3 + x;
        y3 = y3 + y;
    }

    void output_parameters() 
    {
        cout << "lower left: " << x1 << " " << y1 << "\n" <<
            "upper left: " << x1 << " " << y3 << "\n" <<
            "upper right: " << x3 << " "<< y3 << "\n" <<
            "lover right: " << x3 << " "<< y1 << "\n";

    }

    void changing_size(double dx, double dy)
    {
        x3 *= dx;
        y3 *= dy;
    }

    Rectangle intersection(Rectangle a);
    Rectangle min_rectangle(Rectangle a);

};

Rectangle Rectangle::intersection(Rectangle a)
{
    if (y1>=a.y3 || a.y1>=y3 || a.x1>=x3 || x1 >= a.x3)
    {
        cout << "No intersection \n";
        Rectangle rect;
        return rect;
    }
    else 
    {
        double i_x1, i_y1, i_x3, i_y3;
        
        i_x1 = max(x1, a.x1);
        i_x3 = min(a.x3, x3);
        i_y1 = max(a.y1, y1);
        i_y3 = min(a.y3, y3);

        Rectangle rect(i_x1, i_y1, i_x3, i_y3);
        return rect;
    }
}

Rectangle Rectangle::min_rectangle(Rectangle a)
{
    double m_x1, m_y1, m_x3, m_y3;
    m_x1 = min(a.x1, x1);
    m_y1 = min(a.y1, y1);
    m_x3 = max(a.x3, x3);
    m_y3 = max(a.y3, y3);

    Rectangle rect(m_x1, m_y1, m_x3, m_y3);
    return rect;
}

int main()
{
    
    double x1, y1, x3, y3;
    cin >> x1 >> y1 >> x3 >> y3;

    Rectangle rectangle(x1, y1, x3, y3);
    rectangle.output_parameters();

    double const x = 2;
    double const y = 5;
    rectangle.movement(x, y);
    cout << "after moving on a const vector: \n";
    rectangle.output_parameters();

    cout << "input multiplier on x, on y (new x = x*dx, new y=y*dy): \n";
    double dx,dy;
    cin >> dx>>dy;
    rectangle.changing_size(dx, dy);
    rectangle.output_parameters();
    

    double x11, y11, x13, y13;
    double x21, y21, x23, y23;

    cout << "object 1 :\n";
    cin >> x11 >> y11 >> x13 >> y13;
    cout << "object 2 :\n";
    cin >> x21 >> y21 >> x23 >> y23;

    Rectangle ob1(x11, y11, x13, y13);
    Rectangle ob2(x21, y21, x23, y23);

    Rectangle result = ob1.min_rectangle(ob2);
    result.output_parameters();
}

