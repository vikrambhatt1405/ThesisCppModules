//
// Created by vikrambhatt on 18/12/2019.
//

#include <cstdlib>

void set_adjwgt(int* adjwgt, const int* xadj, const int* adjncy, const int nvtxs){
    srand(123);
    for (int i = 0; i < nvtxs; ++i) {
        for (int j = xadj[i]; j < xadj[i+1] ; ++j) {
            if(adjwgt[j]==0){
                int wgt = rand()%50 + 10;
                adjwgt[i] = wgt;
                for (int k = xadj[adjncy[j]]; k < xadj[adjncy[j]+1] ; ++k) {
                        if(adjwgt[k]==0 && adjncy[k]==i){
                            adjwgt[k]=wgt;
                            break;
                        }
                }
            }
        }
    }
}
