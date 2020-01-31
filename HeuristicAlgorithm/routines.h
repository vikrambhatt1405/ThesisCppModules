//
// Created by vikrambhatt on 10/01/2020.
//

#ifndef HEURISTICALGORITHM_ROUTINES_H
#define HEURISTICALGORITHM_ROUTINES_H

#include <cstddef>
#include <vector>

struct vertex_with_gains {
    int vtx;
    long gain;
};

void adjtocsr(int **xadj,
              int **adjncy,
              int **adjwgt,
              int *nvtxs,
              int *nedges,
              const char *file_path);

void random_bisection(int **part,
                      int nvtxs);

void assert_bisection_valid(int *part,
                            int nvtxs);

long partition_cost(const int *part,
                    const int *xadj,
                    const int *adjncy,
                    const int *adjwgt,
                    const int nvtxs);

void compute_gains(vertex_with_gains **D1,
                   vertex_with_gains **D2,
                   size_t *size_D1,
                   size_t *size_D2,
                   const int *xadj,
                   const int *adjncy,
                   const int *adjwgt,
                   const int *part,
                   int nvtxs);


long weight(const int vtx_x,
            const int vtx_y,
            const int *xadj,
            const int *adjncy,
            const int *adjwgt);

void update_gains(vertex_with_gains *D1,
                  vertex_with_gains *D2,
                  const size_t size_D1,
                  const size_t size_D2,
                  const int *xadj,
                  const int *adjncy,
                  const int *adjwgt);

int maximum_gain_swaps(std::vector<long> &G);

void validate_gains(std::vector<long> &G);

void calculate_fiedler_values(
        const int *part,
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int nvtxs,
        double &partx_fiedler_value,
        double &party_fiedler_value
);

#endif //HEURISTICALGORITHM_ROUTINES_H
