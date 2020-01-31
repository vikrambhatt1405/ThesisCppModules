//
// Created by vikrambhatt on 16/12/2019.
//
#ifndef HEURISTICALGORITHMV2_ROUTINES_H
#define HEURISTICALGORITHMV2_ROUTINES_H

#include <cstddef>
#include <vector>
void adjtocsr(int** xadj,
              int** adjncy,
              int** adjwgt,
              int* nvtxs,
              int* nedges,
              const char* file_path);

void random_bisection(int** part,
                      int nvtxs,
                      size_t*  size_part);

void assert_bisection_valid(int* part,
                        int nvtxs);

long partition_cost(const int* part,
        const int* xadj,
        const int* adjncy,
        const int* adjwgt,
        const int nvtxs);


float f(const int* part, const int* xadj, const int* adjncy, const int* adjwgt, const int nvtxs, const float alpha, size_t size_part1);
long weight(const int vtx_x,
        const int vtx_y,
        const int* xadj,
        const int* adjncy,
        const int* adjwgt);

int maximum_gain_swaps(std::vector<long>& G);

void validate_gains(std::vector<long>& G);

void random_movement(int *new_part,
        const int nvtxs,
        size_t *size_newpart);
#endif //HEURISTICALGORITHMV2_ROUTINES_H
