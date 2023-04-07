# core dump in the local directory if an error occur
ulimit -c unlimited
echo 'core' | sudo-g5k tee /proc/sys/kernel/core_pattern

# compile
cd lib/sha256_intel_avx/
sudo-g5k apt install nasm
make clean && make all
cd ../../
make clean && make all

# mpirun -machinefile $OAR_NODEFILE ./verify_data
mpirun -machinefile $OAR_NODEFILE  -map-by node:PE=1 ./phase_ii

