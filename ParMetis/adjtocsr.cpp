#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <mpi.h>

void adjtocsr(int** xadj,
              int** adjncy,
              int** vtxdist,
              int* nvtxs,
              int* nedges,
              const std::string& file_path,
              MPI_Comm *comm){
    int id;
    int n_proc;
    int adjncy_size, xadj_size;
    int total_vtxs, total_edges;
    std::vector<int> _xadj = {0};
    std::vector<int> _adjncy;
    MPI_Comm_rank(*comm, &id);
    MPI_Comm_size(*comm, &n_proc);
    if(id ==  n_proc-1) {
        std::ifstream adj_file;
        adj_file.open(file_path, std::ios::in);
        if (!adj_file) {
            std::cout << "FILE CREATION FAILED" << std::endl;
            MPI_Abort(*comm, 1);
        }
        std::string s;
        getline(adj_file, s);
        total_vtxs = stoi(s);
        getline(adj_file, s);
        total_edges = stoi(s);
        MPI_Bcast(&total_vtxs, 1, MPI_INT, n_proc - 1, *comm);
        MPI_Bcast(&total_edges, 1, MPI_INT, n_proc - 1, *comm);
        for (int process = 0; process < n_proc - 1; ++process) {
            int vtxs_read=0;
            _xadj = {0};
                while(vtxs_read<total_vtxs/n_proc){
                    getline(adj_file, s);
                    std::string delim = " ";
                    auto start = 0U;
                    auto end = s.find(delim);
                    while (end != std::string::npos)
                    {
                        start = end + delim.length();
                        end = s.find(delim, start);
                        _adjncy.push_back(std::stoi(s.substr(start, end-start)));
                    }
                    vtxs_read+=1;
                    _xadj.push_back(_adjncy.size());
                }
                adjncy_size = _adjncy.size();
                xadj_size = _xadj.size();
                MPI_Send(&adjncy_size, 1, MPI_INT, process, process+8, *comm);
                MPI_Send(&xadj_size, 1, MPI_INT, process, process+16, *comm);
                MPI_Send(_adjncy.data(), _adjncy.size(), MPI_INT, process, process+32, *comm);
                MPI_Send(_xadj.data(), _xadj.size(), MPI_INT, process, process+64, *comm);
                _xadj.clear();
                _adjncy.clear();
        } // Data distributed for all other process at this point
        // Now assign the rest of data to this process n_proc-1
        _xadj = {0};
        _adjncy.clear();
        while (getline(adj_file, s)){
                std::string delim = " ";
                auto start = 0U;
                auto end = s.find(delim);
                while (end != std::string::npos)
                {
                    start = end + delim.length();
                    end = s.find(delim, start);
                    _adjncy.push_back(std::stoi(s.substr(start, end-start)));
                }
                _xadj.push_back(_adjncy.size());
            }
        *nvtxs = _xadj.size()-1;
        *nedges = _adjncy.size();
        *xadj = new int[_xadj.size()];
        *adjncy = new int[_adjncy.size()];
        std::copy(_xadj.begin(), _xadj.end(), *xadj);
        std::copy(_adjncy.begin(), _adjncy.end(), *adjncy);
        adj_file.close();
    }else{
        MPI_Status status[4];
        MPI_Request request[4];
        MPI_Bcast(&total_vtxs, 1, MPI_INT, n_proc-1, *comm);
        MPI_Bcast(&total_edges, 1, MPI_INT, n_proc - 1, *comm);
        MPI_Irecv(&adjncy_size, 1, MPI_INT, n_proc-1, id+8, *comm, &request[0]);
        MPI_Irecv(&xadj_size, 1, MPI_INT, n_proc-1, id+16, *comm, &request[1]);
        MPI_Wait(&request[0], &status[0]);
        MPI_Wait(&request[1], &status[1]);
        if (status[0].MPI_ERROR || status[1].MPI_ERROR) {
            std::cout<<"Array sizes not received."<<std::endl;
            MPI_Abort(*comm, status[0].MPI_ERROR ? status[0].MPI_ERROR : status[1].MPI_ERROR);
        }
        *nvtxs = xadj_size-1;
        *nedges = adjncy_size;
        *adjncy = new int[adjncy_size];
        *xadj = new int[xadj_size];
        MPI_Irecv(*adjncy, adjncy_size, MPI_INT, n_proc-1, id+32, *comm, &request[2]);
        MPI_Irecv(*xadj, xadj_size, MPI_INT, n_proc-1, id+64, *comm, &request[3]);
        MPI_Wait(&request[2], &status[2]);
        MPI_Wait(&request[3], &status[3]);
        if(status[2].MPI_ERROR || status[3].MPI_ERROR){
            std::cout<<"Arrays not recevied"<<std::endl;
            MPI_Abort(*comm, status[2].MPI_ERROR?status[2].MPI_ERROR:status[3].MPI_ERROR);
        }
    }
    //Define vtxdist for all processes
    *vtxdist = new int[n_proc+1]();
    for(int i=1; i<n_proc; ++i) {
        (*vtxdist)[i] = i*(total_vtxs/n_proc);
    }
    (*vtxdist)[n_proc] =  total_vtxs;
}
