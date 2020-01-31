//
// Created by vikrambhatt on 17/12/2019.
//
#include <vector>
int maximum_gain_swaps(std::vector<long>& G){
    long max_sum=G[0];
    int max_pos = 0;
    long sum=G[0];
    for (int i = 1; i <G.size() ; ++i) {
        sum = sum + G[i];
        if(sum > max_sum){
            max_sum = sum;
            max_pos = i;
        }
    }
    return max_pos;
}
