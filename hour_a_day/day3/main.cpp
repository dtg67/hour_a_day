//Use Euler’s method to estimate the value at x = 1.5 of the solution of
//dy/dx = y' = F(x,y) = y**2 - x**2 for which y(0) = -1. h = 0.5.

#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

double F(double x, double y){
    return (y*y - x*x);
}

int main(int argc, char **argv){
    double yn = -1;
    double xn = 0;
    double h = 0.5;
    double a = 0;
    double b = 1.5;
    double mn = F(xn,yn);
    
    std::ofstream fout;
    fout.open("euler.txt");
    fout << "n" << std::setw(10) <<
    "xn" << std::setw(10) <<
    "yn" << std::setw(10) <<
    "mn" << std::setw(10) <<
    "mn*h" << std::endl;
    fout << std::setprecision(4);
    
    fout << 0 << std::setw(10) <<
    xn << std::setw(10) <<
    yn << std::setw(10) <<
    mn << std::setw(10) <<
    mn * h << std::endl;
    const double iter = (b-a)/h;
    for(int i = 0; i < iter; i++){
        mn = F(xn,yn);
        yn = yn + mn*h;
        xn = xn + h;
        fout << i + 1 << std::setw(10) <<
        xn << std::setw(10) <<
        yn << std::setw(10) <<
        mn << std::setw(10) <<
        mn * h << std::endl;
    }
    fout.close();
    return 0;
}
