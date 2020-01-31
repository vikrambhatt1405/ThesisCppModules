#include "routines.h"
#include <vector>
#include <cassert>
//
// Created by vikrambhatt on 16/12/2019.
//
void compute_gains(vertex_with_gains** D1, vertex_with_gains** D2, size_t* size_D1, size_t* size_D2,  const int* xadj, const int* adjncy, const int* adjwgt, const int* part, int nvtxs) {
    std::vector<vertex_with_gains> _D1;
    std::vector<vertex_with_gains> _D2;
    for (int i = 0; i < nvtxs; ++i) {
        int part_id = part[i];
        long external_cost = 0;
        long internal_cost = 0;
        for (int j = xadj[i]; j < xadj[i + 1]; ++j) {
            if (part[adjncy[j]] == part_id) {
                internal_cost += adjwgt[j];
            } else {
                external_cost += adjwgt[j];
            }
        }
        if(part_id==0){
        _D1.push_back({i, external_cost-internal_cost});
        } else {
            _D2.push_back({i, external_cost-internal_cost});
        }
    }
    *size_D1 = _D1.size();
    *D1 = new vertex_with_gains[*size_D1];
    std::copy(_D1.begin(), _D1.end(), *D1);
    *size_D2 = _D2.size();
    *D2 = new vertex_with_gains[*size_D2];
    std::copy(_D2.begin(), _D2.end(), *D2);
    assert(*size_D1+*size_D2==nvtxs);
}



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































