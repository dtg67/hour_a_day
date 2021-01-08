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
    srand (67);
    unsigned long long int N = 1000000;
    unsigned long long int a[N];
    unsigned long long int sum = 0;
#pragma omp parallel for
    for(unsigned long long int i = 0; i < N; i++){
        if (cubic() > pyramidal()) {
            a[i] = 1;
        }
        else {
            a[i] = 0;
        }
    }
#pragma omp parallel for reduction(+:sum)
        for(unsigned long long int i = 0; i < N; i++){
            sum += a[i];
        }

    std::cout << 1.0*sum/N << std::endl;
    return 0;
}
