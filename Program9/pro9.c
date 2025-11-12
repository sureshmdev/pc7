#include <stdio.h> 
#include <mpi.h> 
 
int main(int argc, char *argv[]) { 
    int rank, val, max, min, sum, prod; 
 
    MPI_Init(&argc, &argv); 
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); 
 
    val = rank + 1; 
 
    MPI_Reduce(&val, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD); 
    MPI_Reduce(&val, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD); 
    MPI_Reduce(&val, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD); 
    MPI_Reduce(&val, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD); 
if (rank == 0) { 
printf("Max: %d\nMin: %d\nSum: %d\nProduct: %d\n", max, min, sum, prod); 
} 
MPI_Finalize(); 
return 0; 
}

// sudo apt update, sudo apt install openmpi-bin libopenmpi-dev
// Ubuntu (WSL)
// mpicc pro9.c -o pro9.exe
// mpirun -np 2 ./pro9.exe


// #include <stdio.h>
// #include <mpi.h>
// #define TOTAL_OPS 4


// int main(int argc, char *argv[]) {
//     int rank, val, val_arr[TOTAL_OPS];
//     MPI_Init(&argc, &argv);
//     MPI_Op DES[] = {MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD};

//     MPI_Comm_rank(MPI_COMM_WORLD, &rank);
//     val = rank + 1;

//     for (int i = 0; i < TOTAL_OPS; i++) {
//         MPI_Reduce(&val, &val_arr[i], 1, MPI_INT, DES[i], 0, MPI_COMM_WORLD);
//     }
//     if (!rank) {
//         printf("\nMax: %d\n Min: %d\n Sum: %d\n Product: %d\n", val_arr[0], val_arr[1], val_arr[2], val_arr[3]);
//     } 
//     MPI_Finalize();
//     return 0;
// }