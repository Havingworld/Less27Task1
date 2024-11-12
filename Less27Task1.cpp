#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

enum  Colors
{
    None,
    Read,
    Orange,
    Yelow,
    Green,
    Blue,
    Purple
};

class Figure {
    double dCenterPointX{ 0.0f },
           dCenterPointY{ 0.0f };
    Colors color{ Colors::None };
public:
    void setParFig() {
        std::cout << "Set parameters the figure.\n Set center point (X Y): ";
        std::cin >> dCenterPointX >> dCenterPointY;
        std::cout << "Set color num (0=None, 1=Read, 2=Orange, 3=Yelow, 4=Green, 5=Blue, 6=Purple): ";
        int nNumColor{ 0 };
        std::cin >> nNumColor;
        assert(nNumColor >= 0 && nNumColor <= 6);
        color = static_cast<Colors>(nNumColor);
    }
    // metod for searsch around reactangle

};
class Circle : Figure {
    double dRadius{ 0.0f };
public:
    void setPar() {
        setParFig();
        std::cout << "Set radius: ";
        std::cin >> dRadius;
    }
    void getArea() {
        std::cout << "Area of a circle: " << atan(1) * 4 * dRadius << std::endl;
    }
};

class Square : Figure {
    double dEdge{ 0.0f };
public:
    void setPar() {
        setParFig();
        std::cout << "Set edge lenght: ";
        std::cin >> dEdge;
    }
    void getArea() {
        std::cout << "Area of a square: " << dEdge * dEdge << std::endl;
    }
};

class Triangle : Figure {
    double dEdge{ 0.0f };
public:
    void setPar() {
        setParFig();
        std::cout << "Set edge lenght: ";
        std::cin >> dEdge;
    }
    void getArea() {
        std::cout << "Area of a triangle: " << dEdge * dEdge * sqrt(3)/4 << std::endl;
    }
};

class Rectangle : Figure {
    double  dHeight{ 0.0f },
            dWeight{ 0.0f };
public:
    void setPar() {
        setParFig();
        std::cout << "Set edge lenghts (height weight): ";
        std::cin >> dHeight >> dWeight;
    }
    void getArea() {
        std::cout << "Area of a rectangle: " << dHeight * dWeight << std::endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

