//
// Created by vikrambhatt on 16/12/2019.
//
#include <cassert>
#include <cstdlib>
void assert_bisection_valid(int* part, int nvtxs) {
    int zeros = 0, ones = 0;
    for (int i = 0; i < nvtxs; ++i) {
        if (part[i] == 0) zeros++;
        if (part[i] == 1) ones++;
    }
    assert(zeros+ones == nvtxs);
    assert(abs(zeros-ones)<=1);
}