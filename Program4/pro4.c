#include<stdio.h>
#include<omp.h>
#include<stdbool.h>

bool is_prime(int n){
    if(n<2)
        return false;
    for (int i = 2; i * i <= n;i++) if(n%i==0)
            return false;
    return true;
}

int main(){
    int n;
    printf("Enter upper limit: ");
    scanf("%d", &n);

    double start = omp_get_wtime();
    for (int i = 1; i <= n;i++) if (is_prime(i)){}
    double end = omp_get_wtime();
    printf("Serial Time: %f\n", end - start);

    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 1; i <=n; i++) if (is_prime(i)){}
    end = omp_get_wtime();
    printf("Parallel Time: %f\n", end - start);

    return 0;
}

// gcc -fopenmp pro4.c -o pro4
// ./pro4