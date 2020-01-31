cd /home/vikrambhatt/CLionProjects/SpectralBisection
cmake .
make
for i in /mnt/sdb/data/clustering/*.graph
do
  # shellcheck disable=SC2034
  file=$(readlink -f "$i")
  echo $file
  ./SpectralBisection $file >> /home/vikrambhatt/Academics/Research/Results/metis_recursive_result.txt
done