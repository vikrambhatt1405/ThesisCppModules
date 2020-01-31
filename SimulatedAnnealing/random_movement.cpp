//
// Created by vikrambhatt on 19/12/2019.
//
#include <cstdlib>

void random_movement(int *new_part, const int nvtxs, size_t *size_newpart) {
    int mv_vtx = rand() % nvtxs;
    if (new_part[mv_vtx] == 0) {
        new_part[mv_vtx] = 1;
        *size_newpart = *size_newpart - 1;
    }
    else {
        new_part[mv_vtx] = 0;
        *size_newpart = *size_newpart + 1;
    }
}
