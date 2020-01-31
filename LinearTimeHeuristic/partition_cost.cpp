//
// Created by vikrambhatt on 17/12/2019.
//
long partition_cost(const int* part, const int* xadj, const int* adjncy, const int* adjwgt,  const int nvtxs){
    long cost=0;
    for (int i = 0; i < nvtxs ; ++i) {
        int part_id = part[i];
        for (int j = xadj[i]; j < xadj[i+1] ; ++j) {
            if(part[adjncy[j]] != part_id){
                cost += (long) adjwgt[j];
            }
        }
    }
    return cost;
}
