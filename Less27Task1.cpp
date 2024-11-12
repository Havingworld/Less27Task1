#include <iostream>
#include <cassert>
#include <string>
#include <cmath>
#include <vector>

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
    void getCircumReactangleFig(bool bIsCircle, std::vector<double> params) {
        std::cout << "Area of a circumscribed rectangle: ";
        if (bIsCircle) {
            std::cout << params[0] * params[0] * 4;
        }
        else {
            double dArea{1};
            if (params.size() > 1) for (auto& i : params) dArea *= i;
            else dArea = params[0] * params[0];
            std::cout << dArea;
        }
        std::cout << std::endl;
    }

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
    void getCircumReactangle() {
        std::vector<double> param;
        param.push_back(dRadius);
        getCircumReactangleFig(true, param);
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
    void getCircumReactangle() {
        std::vector<double> param;
        param.push_back(dEdge);
        getCircumReactangleFig(false, param);
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
    void getCircumReactangle() {
        std::vector<double> param;
        param.push_back(dEdge);
        getCircumReactangleFig(false, param);
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
    void getCircumReactangle() {
        std::vector<double> param;
        param.push_back(dHeight);
        param.push_back(dWeight);
        getCircumReactangleFig(false, param);
    }
};

int main()
{
    std::string cCommand{""};
    
    while (cCommand != "quit") {

        std::cout << "Input command (circle, square, triangle, rectangle or quit): ";
        std::cin >> cCommand;

        if (cCommand == "circle") {
            Circle* figure = new Circle;

            figure->setPar();
            figure->getArea();
            figure->getCircumReactangle();

            delete figure;
            figure = { nullptr };
        }
        else if (cCommand == "square") {
            Square* figure = new Square;

            figure->setPar();
            figure->getArea();
            figure->getCircumReactangle();

            delete figure;
            figure = { nullptr };
        }
        else if (cCommand == "triangle") {
            Triangle* figure = new Triangle;

            figure->setPar();
            figure->getArea();
            figure->getCircumReactangle();

            delete figure;
            figure = { nullptr };
        }
        else if (cCommand == "rectangle") {
            Rectangle* figure = new Rectangle;

            figure->setPar();
            figure->getArea();
            figure->getCircumReactangle();

            delete figure;
            figure = { nullptr };
        }
        else if (cCommand == "quit") {
            break;
        }
        else {
            std::cout << "Unknow commad, try again.\n";
        }
    }
    return 0;
}

