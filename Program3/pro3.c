#include <stdio.h>
#include <omp.h>

int fib(int n){
    int x, y;
    if(n < 2)
        return n;
    #pragma omp task shared(x)
    x = fib(n - 1);
    #pragma omp task shared(y)
    y = fib(n - 2);
    #pragma omp taskwait
    return x + y;
}

int main(){
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int result;
    #pragma omp parallel
    {
        #pragma omp single
        result = fib(n);
    }
    printf("Fibonacci(%d) = %d\n", n, result);
    return 0;
}


// gcc -fopenmp pro3.c -o pro3
// ./pro3