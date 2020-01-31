//
// Created by vikrambhatt on 26/12/2019.
//
#include <iostream>
#include "routines.h"
#include "doubly_linked_list.h"
#include <sstream>
#include <cassert>
#include <stdexcept>

//std::ostream &operator<<(std::ostream &os, ll::Node &arg) {
//    os << "vertex = " << arg.vtx << ", gain = " << arg.gain << ", left =  " << arg.left << ", right =  " << arg.right;
//    return os;
//}

void assert_valid_tables(std::vector<ll::Node *> &partX,
                         std::vector<ll::Node *> &partY,
                         int nvtxs) {
    int nodes = 0;
    for (int l = 0; l < partY.size(); ++l) {
        ll::Node *temp = partY[l];
        while (temp) {
//            std::cout << "Address = " << temp << " , " << *temp << std::endl;
            nodes++;
            temp = temp->right;
        }
    }
    std::stringstream s;
    s << "PartY Size: " << nvtxs / 2 << " Nodes: " << nodes << std::endl;
    if (nvtxs / 2 != nodes) throw std::invalid_argument(s.str());
    nodes = 0;
    for (int l = 0; l < partX.size(); ++l) {
        ll::Node *temp = partX[l];
        while (temp) {
//            std::cout << "Address = " << temp << " , " << *temp << std::endl;
            nodes++;
            temp = temp->right;
        }
    }
    s.str(std::string());
    s << "PartX Size: " << nvtxs - nvtxs / 2 << " Nodes: " << nodes << std::endl;
    if ((nvtxs - nvtxs / 2) != nodes) throw std::invalid_argument(s.str());

}
