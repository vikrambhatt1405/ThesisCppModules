//
// Created by vikrambhatt on 17/12/2019.
//

#include <iostream>
#include "routines.h"

void update_gains(vertex_with_gains* D1,  vertex_with_gains* D2, const size_t size_D1, const size_t size_D2, const int* xadj, const int* adjncy, const int*adjwgt){
    for (int i = 0; i < size_D1; ++i) {
//        std::cout<<2*weight(D1[i].vtx, D1[size_D1].vtx, xadj, adjncy, adjwgt) <<std::endl;
        D1[i].gain = D1[i].gain + 2*weight(D1[i].vtx, D1[size_D1-1].vtx, xadj, adjncy, adjwgt) - 2*weight(D1[i].vtx, D2[size_D2-1].vtx , xadj, adjncy, adjwgt);
    }
    for (int j = 0; j < size_D2; ++j) {
        D2[j].gain = D2[j].gain + 2*weight(D2[j].vtx, D2[size_D2-1].vtx, xadj, adjncy, adjwgt) - 2*weight(D2[j].vtx, D1[size_D1-1].vtx, xadj, adjncy, adjwgt);
    }
}
