#include <iostream>
#include <metis.h>
#include "routines.h"
#include <filesystem>
#include <chrono>

int main(int argc, char *argv[]) {
    int *xadj;
    int *adjncy;
    int *adjwgt;
    int nvtxs;
    int nedges;
    idx_t n_parts = 2;
    idx_t ncon = 1;
    idx_t edgecut;
    double fiedler_value_x;
    double fiedler_value_y;
    adjtocsr(&xadj, &adjncy, &adjwgt, &nvtxs, &nedges, argv[1]);
    auto part = new idx_t[nvtxs];
    auto start = std::chrono::high_resolution_clock::now();
//    METIS_PartGraphKway(&nvtxs, &ncon, xadj, adjncy, NULL, NULL, adjwgt, &n_parts, NULL, NULL, NULL, &edgecut, part);
    METIS_PartGraphRecursive(&nvtxs, &ncon, xadj, adjncy, NULL, NULL, adjwgt, &n_parts, NULL, NULL, NULL, &edgecut,
                             part);
    auto stop = std::chrono::high_resolution_clock::now();
    double vm, rss;
    process_mem_usage(vm, rss);
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//    std::cout << "VM: " << vm << "; RSS: " << rss << std::endl;
    std::filesystem::path p((std::string(argv[1])));
    std::cout << p.filename().c_str() << "&" << nvtxs << "&" << nedges << "&" << edgecut << "&" << rss / 1000 << "&"
              << vm / 1000 << "&" << duration.count() << "\\\\" << std::endl;
//    algebraic_connectivity(part, xadj, adjncy, adjwgt, nvtxs, fiedler_value_x, fiedler_value_y);
    return 0;
}
