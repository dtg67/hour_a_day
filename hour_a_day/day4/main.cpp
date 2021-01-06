//Peter has nine four-sided (pyramidal) dice, each with faces numbered 1, 2, 3, 4.
//Colin has six six-sided (cubic) dice, each with faces numbered 1, 2, 3, 4, 5, 6.
//
//Peter and Colin roll their dice and compare totals: the highest total wins. The result is a draw if the totals are equal.
//
//What is the probability that Pyramidal Pete beats Cubic Colin? Give your answer rounded to seven decimal places in the form 0.abcdefg
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
    int id;
    srand (time(NULL));
    unsigned long int N = 10000000000;
    unsigned long int count = 0;
#pragma omp parallel private(id) reduction(+:count)
{
    for(unsigned long int i = 0; i < N/4; i++){
        if(cubic() > pyramidal()){count++;}
    }
}
    std::cout << 1.0*count/N << std::endl;
    std::setprecision(7);
    return 0;
}
