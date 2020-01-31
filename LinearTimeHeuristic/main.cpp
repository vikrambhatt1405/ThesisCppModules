#include "routines.h"
#include "doubly_linked_list.h"
#include <vector>
#include <iostream>
#include <stdexcept>

int main(int argc, char **argv) {
    int *xadj;
    int *adjncy;
    int *adjwgt;
    int nvtxs;
    int nedges;
    int *part;
    long costreduction;
    int pass = 0;
    float maxbal = 0.55;
    std::vector<ll::Node> vtx_array;
    std::vector<ll::Node *> partX;
    std::vector<ll::Node *> partY;
    adjtocsr(xadj, adjncy, adjwgt, nvtxs, nedges, "/mnt/sdb/data/walshaw/3elt.graph");
    random_bisection(&part, nvtxs);
    long partx_size = nvtxs - nvtxs / 2;
    long party_size = nvtxs / 2;
    assert_bisection_valid(part, nvtxs);
    if (DFS(xadj, adjncy, nvtxs)){
        std::cout<<"Connected Graph"<<std::endl;
    } else{
        throw std::invalid_argument("Disconnected graph \n");
    }

////    do {
//        long maxgain_x;
//        long maxgain_y;
//        long partx_maxgain_idx;
//        long party_maxgain_idx;
//        create_gains_table(xadj, adjncy, adjwgt, part, nvtxs, vtx_array, partX, partY, maxgain_x, partx_maxgain_idx,
//                           maxgain_y, party_maxgain_idx);
//        std::vector<bool> locked(nvtxs, false);
//        std::vector<int> swap_vtx;
//        std::vector<long> gains;
//        std::cout << pass << " " << partition_cost(part, xadj, adjncy, adjwgt, nvtxs) << std::endl;
//        int selected_vtx = 0;
//        long selected_vtx_gain = 0;
//        while (swap_vtx.size() < nvtxs) {
//            choose_maxgain_vtx(partX, partY, partx_maxgain_idx, party_maxgain_idx,
//                               selected_vtx, selected_vtx_gain,
//                               partx_size, party_size, maxbal);
//            locked[selected_vtx] = true;
//            swap_vtx.emplace_back(selected_vtx);
//            gains.emplace_back(selected_vtx_gain);
//            update_gains(part, xadj, adjncy, adjwgt, vtx_array, partX, partY, locked,
//                         selected_vtx, selected_vtx_gain, maxgain_x, partx_maxgain_idx, maxgain_y, party_maxgain_idx);
//        }
//        int k = maximum_gain_swaps(gains, costreduction);
////        std::cout << costreduction << std::endl;
//        validate_gains(gains);
//        for (int i = 0; i < k; ++i) {
//            if (part[swap_vtx[i]] == 0) part[swap_vtx[i]] = 1;
//            else part[swap_vtx[i]] = 0;
//        }
//        pass++;
//        std::cout << pass << " " << partition_cost(part, xadj, adjncy, adjwgt, nvtxs) << std::endl;
//        vtx_array.clear();
//        partX.clear();
//        partY.clear();
//        maxgain_x = 0;
//        maxgain_y = 0;
//        partx_maxgain_idx = 0;
//        party_maxgain_idx = 0;
//        swap_vtx.clear();
//        gains.clear();
//        locked.clear();
////    } while (costreduction > 0);
//    std::cout << "Success" << std::endl;
        return 0;
}
