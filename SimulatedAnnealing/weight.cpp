#include <cstdlib>
#include "routines.h"

//
// Created by vikrambhatt on 17/12/2019.
//
long weight(const int vtx_x, const int vtx_y, const int* xadj, const int* adjncy, const int* adjwgt){
    for (int i = xadj[vtx_x]; i < xadj[vtx_x+1] ; ++i) {
        if(vtx_y ==  adjncy[i]){
            return (long)adjwgt[i];
        }
    }
    return 0;
}

