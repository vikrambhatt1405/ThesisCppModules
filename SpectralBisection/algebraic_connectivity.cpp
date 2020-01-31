//
// Created by vikrambhatt on 04/01/2020.
//
#include <eigen3/Eigen/Eigen>
#include <iostream>


void algebraic_connectivity(
        const int *part,
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int nvtxs,
        double &fiedler_value_x,
        double &fiedler_value_y) {
    std::vector<int> part_x;
    std::vector<int> part_y;
    for (int i = 0; i < nvtxs; ++i) {
        if (part[i]) part_y.push_back(i);
        else part_x.push_back(i);
    }

    std::cout<<part_x.size()<<" "<<part_y.size()<<" "<<nvtxs<<std::endl;
//    Eigen::MatrixXi L_x(part_x.size(), part_x.size());
//    Eigen::MatrixXi L_y(part_y.size(), part_y.size());
//    for (int i = 0; i < part_x.size(); ++i) {
//        for (int j = xadj[part_x[i]]; j < xadj[part_x[i]+1] ; ++j) {
//
//        }
//    }

}