//
// Created by vikrambhatt on 19/12/2019.
//

#include <cstddef>
#include <cmath>
float f(const int* part, const int* xadj, const int* adjncy, const int* adjwgt, const int nvtxs, const float alpha, size_t size_part){
    long cost=0;
    for (int i = 0; i < nvtxs ; ++i) {
        int part_id = part[i];
        for (int j = xadj[i]; j < xadj[i+1] ; ++j) {
            if(part[adjncy[j]] != part_id){
                cost += (long) adjwgt[j];
            }
        }
    }
    float penalty = cost + alpha*std::pow(2*size_part-nvtxs, 2.0);
    return penalty;
}
