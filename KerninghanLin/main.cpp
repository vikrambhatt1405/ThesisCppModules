#include "routines.h"
#include <iostream>
#include <algorithm>
#include <vector>
bool comp(vertex_with_gains x, vertex_with_gains y){
    return x.gain > y.gain;
}
int main(int argc, char** argv) {
    int* xadj;
    int* adjncy;
    int* adjwgt;
    int nvtxs;
    int nedges;
    int* part;
    vertex_with_gains* D1;
    vertex_with_gains* D2;
    size_t size_D1;
    size_t size_D2;
    long edgecut;
    long cost_reduction;
    int pass=0;
    adjtocsr(&xadj, &adjncy, &adjwgt, &nvtxs, &nedges, argv[1]);
    random_bisection(&part, nvtxs);
    assert_bisection_valid(part, nvtxs);
    edgecut = partition_cost(part, xadj, adjncy, adjwgt, nvtxs);
    std::cout<<pass<<" "<<edgecut<<std::endl;
    do{
    compute_gains(&D1, &D2, &size_D1, &size_D2, xadj, adjncy, adjwgt, part, nvtxs);
    std::vector<int> X;
    std::vector<int> Y;
    std::vector<long> G;
    //std::cout<<"Entering main loop"<<std::endl;
        for (int i = 0; i < nvtxs/2; ++i) {
            std::sort(D1, D1+size_D1, comp);
            std::sort(D2, D2+size_D2, comp);
//            std::cout<<D1[0].gain<< " "<<D1[size_D1-1].gain <<std::endl;
//            std::cout<<D2[0].gain<<" "<<D2[size_D2-1].gain<<std::endl;
//            getchar();
            for (int j = 0; j < size_D1; ++j) {
                long max_gain = D1[0].gain + D2[0].gain - 2*weight(D1[0].vtx, D2[0].vtx ,  xadj, adjncy, adjwgt);
                bool max_gain_found = false;
                for (int k = 0; k < size_D2; ++k) {
                    long current_gain =
                            D1[j].gain + D2[k].gain - 2 * weight(D1[j].vtx, D2[k].vtx, xadj, adjncy, adjwgt);
                    if (D1[j].gain + D2[k].gain <= max_gain) {
                        X.push_back(D1[j].vtx);
                        Y.push_back(D2[k].vtx);
                        G.push_back(max_gain);
                        max_gain_found = true;
                        std::swap(D1[j], D1[size_D1 - 1]);
                        std::swap(D2[k], D2[size_D2 - 1]);
                        break;
                    } else if (max_gain <= current_gain) {
                        max_gain = current_gain;
                    }
                }
                    if (max_gain_found) break;
                }
                update_gains(D1, D2, size_D1, size_D2, xadj, adjncy, adjwgt);
                size_D1--;
                size_D2--;
                //std::cout<<"D1: "<<size_D1<<" "<<"D2: "<<size_D2<<std::endl;
                if (size_D1 == 0 || size_D2 == 0) break;
            }
        //std::cout<<"Main loop finished"<<std::endl;
        //validate_gains(G);
        int k = maximum_gain_swaps(G);
//        cost_reduction = 0;
//        for (int l = 0; l <= k ; ++l) {
//            cost_reduction += G[l];
//        }
        pass++;
//        std::cout<<pass<<" "<<edgecut<<std::endl;
        for (int m = 0; m < k ; ++m) {
            part[X[m]] = 1;
            part[Y[m]] = 0;
        }
        cost_reduction = edgecut - partition_cost(part, xadj, adjncy, adjwgt, nvtxs);
        edgecut = partition_cost(part, xadj, adjncy, adjwgt, nvtxs);
        std::cout<< pass <<" "<< partition_cost(part, xadj, adjncy, adjwgt, nvtxs) << std::endl;
    }while(cost_reduction>0);
    return 0;
}
