//
// Created by vikrambhatt on 22/01/2020.
//
#include "routines.h"

void dfs(int *&xadj, int *&adjncy, bool *&marked, int vtx, int &counter) {
    counter++;
    marked[vtx] = true;
    for (int j = xadj[vtx]; j < xadj[vtx + 1]; ++j) {
        if (!marked[adjncy[j]]) {
            dfs(xadj, adjncy, marked, adjncy[j], counter);
        }
    }
}

bool DFS(int *&xadj, int *&adjncy, const int nvtxs) {
    bool *marked = new bool[nvtxs]();
    marked[0] = true;
    int counter = 0;
    dfs(xadj, adjncy, marked, 0, counter);
    delete[] marked;
    return counter == nvtxs;
}