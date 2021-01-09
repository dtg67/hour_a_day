#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <omp.h>

int cubic(){
    return rand() % 6 + 1;
}

int pyramidal(){
    return rand() % 4 + 1;
}

int main(int argc,char **argv){
    srand (67);
    unsigned long long int N = 100000000;
    int id;
    unsigned long long int count = 0;
    unsigned long long int sum = 0;
#pragma omp parallel private(id) reduction(+:sum) reduction(+:count)
    {
    for(auto i = 0; i < N; i++){
        count++;
        if (cubic() > pyramidal()) {
            sum += 1;
            
        }
        }
    }
    std::cout << 1.0*sum/count << std::endl;
    return 0;
}

