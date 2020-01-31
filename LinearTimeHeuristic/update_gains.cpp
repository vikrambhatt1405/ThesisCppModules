//
// Created by vikrambhatt on 17/12/2019.
//

#include <iostream>
#include "routines.h"

void update_gains(const int *part,
                  const int *xadj,
                  const int *adjncy,
                  const int *adjwgt,
                  std::vector<ll::Node> &vtx_array,
                  std::vector<ll::Node *> &partX,
                  std::vector<ll::Node *> &partY,
                  std::vector<bool> &locked,
                  const int selected_vtx,
                  const long selected_vtx_gain,
                  const long maxgain_x,
                  long &partx_maxgain_idx,
                  const long maxgain_y,
                  long &party_maxgain_idx) {

    bool maxgain_updated = false;
    long new_maxgainx = selected_vtx_gain;
    long new_maxgainy = selected_vtx_gain;
    remove_node(vtx_array, partX, partY, part[selected_vtx], selected_vtx, maxgain_x, maxgain_y);
    for (int i = xadj[selected_vtx]; i < xadj[selected_vtx + 1]; ++i) {
        int nbr = adjncy[i];
        int part_id = part[nbr];
        long weight = adjwgt[i];
        long updated_gain = 0;
        if (locked[nbr]) continue;
        remove_node(vtx_array, partX, partY, part_id, nbr, maxgain_x, maxgain_y);
        if (part_id == part[selected_vtx] && part_id == 0) {
            updated_gain = vtx_array[nbr].gain + 2 * weight;
            update_partx(vtx_array, partX, nbr, updated_gain, maxgain_x, partx_maxgain_idx, new_maxgainx,
                         maxgain_updated);
        } else if (part_id == part[selected_vtx] && part_id == 1) {
            updated_gain = vtx_array[nbr].gain + 2 * weight;
            update_party(vtx_array, partY, nbr, updated_gain, maxgain_y, party_maxgain_idx, new_maxgainy,
                         maxgain_updated);
        } else if (part_id != part[selected_vtx] && part_id == 0) {
            updated_gain = vtx_array[nbr].gain - 2 * weight;
            update_partx(vtx_array, partX, nbr, updated_gain, maxgain_x, partx_maxgain_idx, new_maxgainx,
                         maxgain_updated);
        } else if (part_id != part[selected_vtx] && part_id == 1) {
            updated_gain = vtx_array[nbr].gain - 2 * weight;
            update_party(vtx_array, partY, nbr, updated_gain, maxgain_y, party_maxgain_idx, new_maxgainy,
                         maxgain_updated);
        }
    }
    if (!maxgain_updated) {
        while (partX[partx_maxgain_idx] == nullptr && partx_maxgain_idx>0) partx_maxgain_idx--;
        while (partY[party_maxgain_idx] == nullptr && party_maxgain_idx>0) party_maxgain_idx--;
    }
}

