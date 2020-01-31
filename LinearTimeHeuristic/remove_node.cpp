//
// Created by vikrambhatt on 01/01/2020.
//

#include <vector>
#include <iostream>
#include "routines.h"

std::ostream &operator<<(std::ostream &os, ll::Node &arg) {
    os << "vertex = " << arg.vtx << ", gain = " << arg.gain << ", left =  " << arg.left << ", right =  " << arg.right;
    return os;
}

void remove_node(
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partX,
        std::vector<ll::Node *> &partY,
        const int part_id,
        const long nbr,
        const long maxgain_x,
        const long maxgain_y
) {
    auto &node = vtx_array[nbr];
    auto current_gain = vtx_array[nbr].gain;

    if (part_id == 0) {
        if (node.left == nullptr) {
            partX[current_gain + maxgain_x] = node.right;
            if (node.right != nullptr) {
                node.right->left = nullptr;
                node.right = nullptr;
            }
        } else {
            node.left->right = node.right;
            if (node.right != nullptr) node.right->left = node.left;
            node.left = nullptr;
            node.right = nullptr;
        }
    }

    if (part_id == 1) {
        if (node.left == nullptr) {
            partY[current_gain + maxgain_y] = node.right;
            if (node.right != nullptr) {
                node.right->left = nullptr;
                node.right = nullptr;
            }
        } else {
            node.left->right = node.right;
            if (node.right != nullptr) node.right->left = node.left;
            node.left = nullptr;
            node.right = nullptr;
        }
    }

}
