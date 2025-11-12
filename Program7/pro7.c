#include <stdio.h> 
#include <mpi.h> 
 
int main(int argc, char *argv[]) { 
    int rank, value; 
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
 
    if (rank == 0) { 
        value = 50; 
    } 
 
    MPI_Bcast(&value, 1, MPI_INT, 0, MPI_COMM_WORLD); 
    printf("Process %d received value %d\n", rank, value); 
 
    MPI_Finalize(); 
    return 0; 
}

// sudo apt update, sudo apt install openmpi-bin libopenmpi-dev
// Ubuntu (WSL)
// mpicc pro7.c -o pro7.exe
// mpirun -np 2 ./pro7.exe