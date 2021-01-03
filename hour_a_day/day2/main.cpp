//Using the Eigen library to simulate the trajectory of a projectile.

//TODO Parallize

#include <iostream>
#include <fstream>
#include <iomanip>
#include <Eigen/Core>
#include <cmath>

int main(int argc, char **argv){
    const double g = -9.8; //m/s**2
    const double drag = 1; //N
    const double weight = 1; //N
    const double dt = 0.01;
    double theta, v_init;
    
    std::cout << "Enter theta in degrees: ";
    std::cin >> theta;
    std::cout << "\nEnter initial velocity in m/s: ";
    std::cin >> v_init;
    double vx_init = cos(M_PI*theta/180)*v_init;
    double vy_init = sin(M_PI*theta/180)*v_init;
    
    Eigen::Vector2d position;
    position.setZero();
    Eigen::Vector2d acceleration;
    acceleration << 0.0, g;
    Eigen::Vector2d velocity;
    velocity << vx_init, vy_init;
    
    std::ofstream fout;
    fout.open("trajectory.txt");
    double time = 0.0;
    fout << "Time (s)" << std::setw(25) << "x position (m)" << std::setw(25) << "y position (m)" << std::setw(25) << "x velocity (m/s)" << std::setw(25) << "y velocity (m/s)" << std::setw(25) << "x acceleration (m/s^2)" << std::setw(25) << "y acceleration (m/s^2)\n\n" << std::endl;
    fout << std::setprecision(4);
    while(position[1] >= 0.0){
        fout << time << std::setw(12) << position[0] << std::setw(12) << position[1] << std::setw(12) << velocity[0] << std::setw(12) << velocity[1] << std::setw(12) << acceleration[0] << std::setw(12) << acceleration[1] << std::endl;
        position += velocity*dt;
        velocity += acceleration*dt;
        acceleration[0] = -drag*(velocity.norm())*velocity[0]/weight;
        acceleration[1] = g - drag*(velocity.norm())*velocity[1]/weight;
        time += dt;
        
    }
    fout.close();
    return 0;
}
