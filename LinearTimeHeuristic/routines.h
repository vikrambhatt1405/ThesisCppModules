//
// Created by vikrambhatt on 16/12/2019.
//
#ifndef HEURISTICALGORITHMV2_ROUTINES_H
#define HEURISTICALGORITHMV2_ROUTINES_H

#include <cstddef>
#include <vector>
#include "doubly_linked_list.h"

void adjtocsr(int *&xadj,
              int *&adjncy,
              int *&adjwgt,
              int &nvtxs,
              int &nedges,
              const char *file_path);

void random_bisection(int **part,
                      int nvtxs);

void assert_bisection_valid(int *part,
                            int nvtxs);

long partition_cost(const int *part,
                    const int *xadj,
                    const int *adjncy,
                    const int *adjwgt,
                    const int nvtxs);


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
                  const long,
                  long &,
                  const long,
                  long &);

int maximum_gain_swaps(std::vector<long> &G, long &cost_reduction);

void validate_gains(std::vector<long> &G);

void create_gains_table(
        const int *xadj,
        const int *adjncy,
        const int *adjwgt,
        const int *part,
        int nvtxs,
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partX,
        std::vector<ll::Node *> &partY,
        long &maxgain_x,
        long &partx_maxgain_idx,
        long &maxgain_y,
        long &party_maxgain_idx);

void remove_node(
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partX,
        std::vector<ll::Node *> &partY,
        int part_id,
        long nbr,
        long maxgain_x,
        long maxgain_y);

void update_partx(
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &partX,
        long nbr,
        long updated_gain,
        long maxgain_x,
        long &partx_maxgain_idx,
        long &new_maxgainx,
        bool &maxgain_updated);

void update_party(
        std::vector<ll::Node> &vtx_array,
        std::vector<ll::Node *> &party,
        long nbr,
        long updated_gain,
        long maxgain_y,
        long &party_maxgain_idx,
        long &new_maxgainy,
        bool &maxgain_updated);

void assert_valid_tables(std::vector<ll::Node *> &partX,
                         std::vector<ll::Node *> &partY,
                         int nvtxs);

void choose_maxgain_vtx(
        std::vector<ll::Node *> &partX,
        std::vector<ll::Node *> &partY,
        long partx_maxgain_idx,
        long party_maxgain_idx,
        int &selected_vtx,
        long &selected_vtx_gain,
        long &partx_size,
        long &party_size,
        float maxbal);

void dfs(int *&xadj, int *&adjncy, bool *&marked, int vtx, int &counter);

bool DFS(int *&xadj, int *&adjncy, int nvtxs);

#endif //HEURISTICALGORITHMV2_ROUTINES_H
