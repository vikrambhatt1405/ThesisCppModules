//
// Created by vikrambhatt on 09/01/2020.
//

#ifndef FIEDLERVALUECALCULATION_ROUTINES_H
#define FIEDLERVALUECALCULATION_ROUTINES_H

void adjtocsr(int **xadj,
              int **adjncy,
              int **adjwgt,
              int *nvtxs,
              int *nedges,
              const char *file_path);

void random_bisection(int **part,
                      int nvtxs);

void assert_bisection_valid(
        int *part,
        int nvtxs);

long partition_cost(
        const int *part,
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int nvtxs);

void calculate_fiedler_values(
        const int *part,
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int nvtxs,
        double& partx_fiedler_value,
        double& party_fiedler_value
);

#endif //FIEDLERVALUECALCULATION_ROUTINES_H
