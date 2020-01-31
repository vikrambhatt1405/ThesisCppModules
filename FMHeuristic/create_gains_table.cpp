//
// Created by vikrambhatt on 19/12/2019.
//

#include <iostream>
#include <algorithm>
#include "doubly_linked_list.h"
#include "routines.h"
#include <stdexcept>
#include <cassert>


void create_gains_table(
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int *part,
        const int nvtxs,
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partX,
        std::vector<ll::Node *> &partY,
        long &maxgain_x,
        long &partx_maxgain_idx,
        long &maxgain_y,
        long &party_maxgain_idx) {


    maxgain_x = INT64_MIN;
    maxgain_y = INT64_MIN;

    for (int i = 0; i < nvtxs; ++i) {
        vtx_array.emplace_back();
        vtx_array[i].vtx = i;
        vtx_array[i].gain = INT64_MIN;
        vtx_array[i].left = nullptr;
        vtx_array[i].right = nullptr;
    }

    for (int i = 0; i < nvtxs; ++i) {
        int part_id = part[i];
        long degree = 0;
        for (int j = xadj[i]; j < xadj[i + 1]; ++j) {
            degree += adjwgt[j];
        }
        if (degree > maxgain_x && part_id == 0)
            maxgain_x = degree;
        if (degree > maxgain_y && part_id == 1)
            maxgain_y = degree;
    }
    partX.resize(std::abs(2 * maxgain_x) + 1);
    partY.resize(std::abs(2 * maxgain_y) + 1);

    int vtxs_processed = 0;
    partx_maxgain_idx = 0;
    party_maxgain_idx = 0;
    long partx_gain_sofar = INT64_MIN;
    long party_gain_sofar = INT64_MIN;
    for (int k = 0; k < nvtxs; ++k) {
        int part_id = part[k];
        long external_cost = 0;
        long internal_cost = 0;
        for (int j = xadj[k]; j < xadj[k + 1]; ++j) {
            if (part[adjncy[j]] == part_id) internal_cost += adjwgt[j];
            else external_cost += adjwgt[j];
        }
        long gain = external_cost - internal_cost;
        if (part_id == 0) {
            if (gain > maxgain_x) throw std::out_of_range("Gain Exceeded \n");
            if (gain > partx_gain_sofar) {
                partx_maxgain_idx = gain + maxgain_x;
                partx_gain_sofar = gain;
            }
            if (partX[gain + maxgain_x]) {
                vtx_array[k].gain = gain;
                vtx_array[k].right = partX[gain + maxgain_x];
                partX[gain + maxgain_x]->left = &(vtx_array[k]);
                partX[gain + maxgain_x] = &(vtx_array[k]);
            } else {
                partX[gain + maxgain_x] = &(vtx_array[k]);
                vtx_array[k].gain = gain;
            }
            vtxs_processed++;

        }
        if (part_id == 1) {
            if (gain > maxgain_y) throw std::out_of_range("Gain exceeded \n");
            if (gain > party_gain_sofar) {
                party_maxgain_idx = gain + maxgain_y;
                party_gain_sofar = gain;
            }
            if (partY[gain + maxgain_y]) {
                vtx_array[k].gain = gain;
                vtx_array[k].right = partY[gain + maxgain_y];
                partY[gain + maxgain_y]->left = &(vtx_array[k]);
                partY[gain + maxgain_y] = &(vtx_array[k]);
            } else {
                partY[gain + maxgain_y] = &(vtx_array[k]);
                vtx_array[k].gain = gain;
            }
            vtxs_processed++;
        }
    }
    assert(vtxs_processed == nvtxs);
    assert_valid_tables(
            partX,
            partY,
            nvtxs);

}
