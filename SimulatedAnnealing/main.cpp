#include "routines.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <random>

int main(int argc, char** argv) {
    srand(123);
    int* xadj;
    int* adjncy;
    int* adjwgt;
    int nvtxs;
    int nedges;
    int* part;
    size_t size_part; // number of vertices whose component id=0
    int* new_part;
    size_t size_new_part; //number of vertices whose component id=0
    long edgecut;
    int stop_counter=0;
    int nb_movements=0;
    float temp=100.0;
    const float alpha = 0.05;
    const int sizefact = 16;
    const float tempfact = 0.95;
    const float minpercent = 0.02;
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    adjtocsr(&xadj, &adjncy, &adjwgt, &nvtxs, &nedges, argv[1]);
    random_bisection(&part, nvtxs, &size_part);
    assert_bisection_valid(part, nvtxs);
    edgecut = partition_cost(part, xadj, adjncy, adjwgt, nvtxs);
    std::cout<<edgecut<<std::endl;
    for (int n = 1; n < sizefact*nvtxs ; ++n) {
        new_part = new int [nvtxs];
        size_new_part = size_part;
        std::copy(part, part+nvtxs, new_part);
        random_movement(new_part, nvtxs, &size_new_part);
        float delta = f(new_part, xadj, adjncy, adjwgt, nvtxs, alpha, size_new_part) -
                f(part, xadj, adjncy, adjwgt, nvtxs, alpha, size_part);
        if (delta <= 0){
            delete [] part;
            part = new_part;
            size_part = size_new_part;
            stop_counter = 0;
            nb_movements++;
            std::cout<<partition_cost(part, xadj, adjncy, adjwgt, nvtxs)<<std::endl;
        } else if (std::exp(-delta/temp) >  dis(gen)){
            delete[] part;
            part = new_part;
            size_part = size_new_part;
            nb_movements = nb_movements + 1;
            std::cout<<partition_cost(part, xadj, adjncy, adjwgt, nvtxs)<<std::endl;
        }
    }
    temp = temp*tempfact;
    float percent_of_movements = (float)(sizefact*nvtxs - nb_movements)/(float)(sizefact*nvtxs);
    if (percent_of_movements < minpercent ) stop_counter = stop_counter+1;
}
