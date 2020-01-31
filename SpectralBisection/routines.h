//
// Created by vikrambhatt on 04/01/2020.
//

#ifndef SPECTRALBISECTION_ROUTINES_H
#define SPECTRALBISECTION_ROUTINES_H

void adjtocsr(int **xadj,
              int **adjncy,
              int **adjwgt,
              int *nvtxs,
              int *nedges,
              const char *file_path);

void algebraic_connectivity(
        const int *part,
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        int nvtxs,
        double &fiedler_value_x,
        double &fiedler_value_y);

void process_mem_usage(
        double &vm_usage,
        double &resident_set);

#endif //SPECTRALBISECTION_ROUTINES_H
