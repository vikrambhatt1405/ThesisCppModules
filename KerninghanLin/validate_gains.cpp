//
// Created by vikrambhatt on 18/12/2019.
//

#include <vector>
#include <cassert>
#include <iostream>
void validate_gains(std::vector<long>& G){
    long sum=0;
    for(auto i: G){
        std::cout<<i<<" ";
        sum += i;
    }
    std::cout<<std::endl;
    std::cout<<"Size: "<<G.size()<<std::endl;
    std::cout<<"Sum: "<<sum<<std::endl;
    assert(sum==0);
}
