//
// Created by vikrambhatt on 01/01/2020.
//
#include "routines.h"
#include <vector>

void choose_maxgain_vtx(
        std::vector<ll::Node *> &partX,
        std::vector<ll::Node *> &partY,
        const long partx_maxgain_idx,
        const long party_maxgain_idx,
        int &selected_vtx,
        long &selected_vtx_gain,
        long &partx_size,
        long &party_size,
        float maxbal) {

    auto i = partx_maxgain_idx;
    auto j = party_maxgain_idx;
    float size_ratio = (float) partx_size / ((float) partx_size + (float) party_size);
//    if (((1 - maxbal) <= size_ratio) && (size_ratio <= maxbal)) {
        if (partX[i] != nullptr && partY[i] != nullptr) {
            if (partX[i]->gain > partY[j]->gain) {
                selected_vtx = partX[i]->vtx;
                selected_vtx_gain = partX[i]->gain;
                partx_size--;
                party_size++;
            } else {
                selected_vtx = partY[j]->vtx;
                selected_vtx_gain = partY[j]->gain;
                partx_size++;
                party_size--;
            }
        } else if (partX[i] != nullptr) {
            selected_vtx = partX[i]->vtx;
            selected_vtx_gain = partX[i]->gain;
            partx_size--;
            party_size++;
        } else if (partY[j] != nullptr) {
            selected_vtx = partY[j]->vtx;
            selected_vtx_gain = partY[j]->gain;
            partx_size++;
            party_size--;
        }
//    } else if(size_ratio > maxbal){
//        selected_vtx = partX[i]->vtx;
//        selected_vtx_gain = partX[i]->gain;
//        partx_size--;
//        party_size++;
//    } else if(size_ratio < 1- maxbal){
//        selected_vtx = partY[j]->vtx;
//        selected_vtx_gain = partY[j]->gain;
//        partx_size++;
//        party_size--;
//    }

}

