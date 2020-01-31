#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <sstream>

void adjtocsr(int **xadj,
              int **adjncy,
              int **adjwgt,
              int *nvtxs,
              int *nedges,
              const char *file_path) {
    std::vector<int> _xadj = {0};
    std::vector<int> _adjncy;
    std::vector<std::string> graph_pms;
    std::string s;
    std::ifstream adj_file;
    adj_file.open(file_path, std::ios::in);
    if (!adj_file) {
        std::cout << "FILE NOT FOUND:" << file_path << std::endl;
        exit(1);
    }
    while (getline(adj_file, s)) {
        if (s.rfind("%") != 0) break;
    }
    std::istringstream iss(s);
    for (std::string p; iss >> p;) {
        graph_pms.push_back(p);
    }
    *nvtxs = std::stoi(graph_pms[0]);
    *nedges = std::stoi(graph_pms[1]);
    while (getline(adj_file, s)) {
        std::istringstream iadj(s);
        if (!s.empty()) {
            for (std::string p; iadj >> p;) {
                _adjncy.push_back(std::stoi(p) - 1);
            }
            _xadj.push_back(_adjncy.size());
        }
    }
    adj_file.close();
    *xadj = new int[(*nvtxs) + 1];
    *adjncy = new int[_adjncy.size()];
    assert((*nvtxs) + 1 == _xadj.size());
    assert(2 * (*nedges) == _adjncy.size());
    std::copy(_xadj.begin(), _xadj.end(), *xadj);
    std::copy(_adjncy.begin(), _adjncy.end(), *adjncy);
    srand(123);
    *adjwgt = new int[_adjncy.size()];
    for (int i = 0; i < *nvtxs; ++i) {
        for (int j = (*xadj)[i]; j < (*xadj)[i + 1]; ++j) {
            int wgt;
            if ((*adjwgt)[j] == 0) {
                wgt = rand() % 50 + 1;
                int neighbour = (*adjncy)[j];
                (*adjwgt)[j] = wgt;
                for (int k = (*xadj)[neighbour]; k < (*xadj)[neighbour + 1]; ++k) {
                    if ((*adjncy)[k] == i && (*adjwgt)[k] == 0) (*adjwgt)[k] = wgt;
                }
            }
        }
    }

}