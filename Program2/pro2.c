#include <stdio.h> 
#include <omp.h> 

int main() { 
    int n, i; 
    printf("Enter number of iterations: "); 
    scanf("%d", &n); 
    #pragma omp parallel for schedule(static,2) 
    for (i = 0; i < n; i++) { 
        printf("Thread %d: Iteration %d\n", omp_get_thread_num(), i); 
} 
    return 0; 
}

// gcc -fopenmp pro2.c -o pro2
// ./pro2