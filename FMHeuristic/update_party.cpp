//
// Created by vikrambhatt on 01/01/2020.
//
#include <iostream>
#include "routines.h"

void update_party(
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partY,
        const long nbr,
        const long updated_gain,
        const long maxgain_y,
        long &party_maxgain_idx,
        long &new_maxgainy,
        bool &maxgain_updated) {

    auto& node = vtx_array[nbr];
    node.gain = updated_gain;
    if (partY[updated_gain + maxgain_y] == nullptr) {
        partY[updated_gain + maxgain_y] = &node;
        node.left = nullptr;
        node.right = nullptr;
    } else {
//        std::cout<<partY.size()<<","<<updated_gain + maxgain_y<<std::endl;
        partY[updated_gain + maxgain_y]->left = &node;
        node.right = partY[updated_gain + maxgain_y];
        partY[updated_gain + maxgain_y] = &node;
        node.left = nullptr;
    }
    if (updated_gain > new_maxgainy) {
        new_maxgainy = updated_gain;
        party_maxgain_idx = new_maxgainy + maxgain_y;
        maxgain_updated = true;
    }
}