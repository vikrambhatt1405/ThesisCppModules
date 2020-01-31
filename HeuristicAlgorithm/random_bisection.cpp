#include <cstdlib>
#include <vector>
#include <numeric>
#include <random>
#include <algorithm>
#include <iostream>
#include <chrono>

//
// Created by vikrambhatt on 16/12/2019.
//
void random_bisection(int** part,
                      int nvtxs)
{
    *part = new int[nvtxs];
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<int> vtx_indices(nvtxs);
    std::vector<int> _part(nvtxs,0);
    std::iota(vtx_indices.begin(), vtx_indices.end(), 0);
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vtx_indices.begin(), vtx_indices.end(), std::default_random_engine(seed));
    for (int i = 0; i < nvtxs/2 ; ++i) {
        _part[vtx_indices[i]] = 1;
    }
    std::copy(_part.begin(), _part.end(), *part);
}
