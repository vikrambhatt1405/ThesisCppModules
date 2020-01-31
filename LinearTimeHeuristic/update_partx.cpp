//
// Created by vikrambhatt on 01/01/2020.
//
#include "routines.h"
#include <vector>
#include <iostream>

void update_partx(
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partX,
        const long nbr,
        const long updated_gain,
        const long maxgain_x,
        long& partx_maxgain_idx,
        long &new_maxgainx,
        bool& maxgain_updated) {
    auto& node = vtx_array[nbr];
    node.gain = updated_gain;
    if (partX[updated_gain + maxgain_x] == nullptr) {
        partX[updated_gain + maxgain_x] = &node;
        node.left = nullptr;
        node.right = nullptr;
    } else {
//        std::cout<<partX.size()<<","<<updated_gain + maxgain_x<<std::endl;
        partX[updated_gain + maxgain_x]->left = &node;
        node.right = partX[updated_gain + maxgain_x];
        partX[updated_gain + maxgain_x] = &node;
        node.left = nullptr;
    }
    if (updated_gain > new_maxgainx) {
        new_maxgainx = updated_gain;
        partx_maxgain_idx = new_maxgainx + maxgain_x;
        maxgain_updated = true;
    }
}
