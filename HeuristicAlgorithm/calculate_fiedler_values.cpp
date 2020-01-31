//
// Created by vikrambhatt on 09/01/2020.
//
#include <armadillo>
#include <map>
#include <cassert>

void calculate_fiedler_values(
        const int *part,
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int nvtxs,
        double &partx_fiedler_value,
        double &party_fiedler_value
) {

    int size_x = nvtxs - (nvtxs / 2);
    int size_y = nvtxs / 2;
    std::map<int, int> map_x;
    std::map<int, int> map_y;
    std::map<int, int> reverse_map_x;
    std::map<int, int> reverse_map_y;
    int vtx_x = 0;
    int vtx_y = 0;
    for (int i = 0; i < nvtxs; ++i) {
        if (part[i] == 0) {
            map_x.insert(std::pair<int, int>(i, vtx_x));
            reverse_map_x.insert(std::pair<int, int>(vtx_x++, i));
        } else {
            map_y.insert(std::pair<int, int>(i, vtx_y));
            reverse_map_y.insert(std::pair<int, int>(vtx_y++, i));
        }
    }
    assert(map_x.size() == size_x);
    assert(map_y.size() == size_y);
    for (auto pair: map_y){
        std::cout<<pair.first<<","<<pair.second<<std::endl;
    }

    std::vector<double> values_x;
    std::vector<arma::uword> colind;
    std::vector<arma::uword> rowptr;
    rowptr.push_back(0);
    for (int i = 0; i < size_x; ++i) {
        int vtx = reverse_map_x[i];
        int degree = 0;
        for (int j = xadj[vtx]; j < xadj[vtx + 1]; ++j) {
            if (part[adjncy[j]] == 0) {
                degree += adjwgt[j];
            }
        }
        values_x.push_back(-(double) degree);
        colind.push_back(i);
        for (int j = xadj[vtx]; j < xadj[vtx + 1]; ++j) {
            if (part[adjncy[j]] == 0) {
                values_x.push_back(adjwgt[j]);
                colind.push_back(map_x[adjncy[j]]);
            }
        }
        rowptr.push_back(values_x.size());
    }
    arma::dvec values_xx(values_x);
    arma::uvec rowind(colind);
    arma::uvec colptr(rowptr);
    arma::sp_mat lx(rowind, colptr, values_xx, size_x, size_x);
    arma::vec eigval_x;
    arma::mat eigvec_x;
    arma::eigs_sym(eigval_x, eigvec_x, lx, 2, "sm");
    std::cout << eigval_x << std::endl;
//    arma::umat locations_x(2, N_x);
//    arma::umat locations_y(2, N_y);
//    std::cout << "here" << std::endl;
//    std::cout << locations_x.n_cols << "," << locations_x.n_rows << std::endl;
//    for (int j = 0; j < size_x; ++j) {
//        int vtx = reverse_map_x[j];
//        int degree = 0;
//        for (int i = xadj[vtx]; i < xadj[vtx + 1]; ++i) {
//            if (part[i] == 0) {
//                values_x.push_back((double) adjwgt[i]);
//                degree += adjwgt[i];
////                auto pos = values_x.size() - 1;
////                locations_x(0, pos) = j;
////                locations_x(1, pos) = reverse_map_x[adjncy[i]];
//            }
//            values_x.push_back(-(double) degree);
////            locations_x(0, values_x.size() - 1) = j;
////            locations_x(1, values_x.size() - 1) = j;
//        }
//    }
//    arma::umat locations_x(2, values_x.size());
//    int counter = 0;
//    for (int l = 0; l < size_x; ++l) {
//        int vtx = reverse_map_x[l];
//        int degree = 0;
//        for (int i = xadj[vtx]; i < xadj[vtx + 1]; ++i) {
//            if (part[i] == 0) {
//                degree += adjwgt[i];
//                locations_x(0, counter) = l;
//                locations_x(1, counter++) = map_x[i];
//            }
//        }
//        locations_x(0, counter) = l;
//        locations_x(1, counter++) = l;
//    }
//    std::cout << counter << "," << values_x.size() << std::endl;
////    std::vector<double> values_y;
//    for (int k = 0; k < size_y; ++k) {
//        int vtx = map_y[k];
//        int degree = 0;
//        for (int i = xadj[vtx]; i < xadj[vtx + 1]; ++i) {
//            if (part[i] == 1) {
//                values_y.push_back((double) adjwgt[i]);
//                degree += adjwgt[i];
//                auto pos = values_y.size();
////                locations_y(0, pos) = k;
////                locations_y(1, pos) = reverse_map_y[adjncy[i]];
//            }
//            values_y.push_back(-(double) degree);
////            locations_y(0, values_y.size() - 1) = k;
////            locations_y(1, values_y.size() - 1) = k;
//        }
//    }
//    arma::dvec values_xx(values_x);
//    arma::dvec values_yy(values_y);
//    std::cout << values_x.size() << std::endl;
//    std::cout<<locations_x<<std::endl;
//    std::cout<<values_xx<<std::endl;
//    std::cout << values_y.size() << std::endl;
//    arma::sp_mat lx(locations_x, values_xx);
//    arma::sp_mat ly(locations_y, values_yy);

//    arma::eigs_sym(eigval_y, eigvec_y, ly, 2, "sm");

}
