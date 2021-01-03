// Reduction //
// This is a basic a simple example of reduction in C++ using OpenMP
// 'reduction' clause gathers a private variable at the end of a parrellel part and does a simple operation, arthimetic, bitwise, logical, max, min


#include <iostream>
#include <omp.h>

int main(int argc, char *argv[]){
    int id;
    std::cout << "Start\n";
    
    int a = 0;
    
//parrallelized section, id (threads) are private from one another and will reduce a, using summation, at the end
#pragma omp parallel private(id) reduction (+:a)
    {
        id = omp_get_thread_num();
        a = id + 1;
        std::cout << "Thread #" << id << " has a = " << std::endl;
    }
    std::cout << "Final sum is a = " << a << std::endl;
    return 0;
}
