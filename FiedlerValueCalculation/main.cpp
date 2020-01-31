#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include "routines.h"

int main(int argc, char **argv) {
    int *xadj;
    int *adjncy;
    int *adjwgt;
    int nvtxs;
    int nedges;
    int *part;
    long edgecut;
    double partx_fiedler_value;
    double party_fiedler_value;
    adjtocsr(&xadj, &adjncy, &adjwgt, &nvtxs, &nedges, "/mnt/sdb/data/walshaw/3elt.graph");
    random_bisection(&part, nvtxs);
    assert_bisection_valid(part, nvtxs);
    edgecut = partition_cost(part, xadj, adjncy, adjwgt, nvtxs);
    calculate_fiedler_values(part, xadj, adjncy, adjwgt, nvtxs, partx_fiedler_value, party_fiedler_value);
    return 0;
}