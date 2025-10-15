#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

void merge(int arr[], int l, int m, int r){
    int i = l, j = m + 1, k = 0;
    int* temp = (int *)malloc((r - l + 1) * sizeof(int));
    while(i<=m && j<=r)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];
    while(i<=m)
        temp[k++] = arr[i++];
    while(j<=r)
        temp[k++] = arr[j++];
    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = temp[k];
    free(temp);
}

void mergeSort(int arr[], int l, int r){
    if (l<r){
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr,l,m,r);
    }
}

void parallelMergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l + r) / 2;
        #pragma omp parallel sections
        {
            #pragma omp section
            parallelMergeSort(arr, l, m);
            #pragma omp section
            parallelMergeSort(arr, m + 1, r);
        }
        merge(arr, l, m, r);
    }
}

int main(){
    int n = 100000;
    int *arr = (int *)malloc(n * sizeof(int));
    int *arr2 = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = arr2[i] = rand();

    double start = omp_get_wtime();
    mergeSort(arr, 0, n - 1);
    double end = omp_get_wtime();
    printf("Sequential Time: %f seconds\n", end - start);

    start = omp_get_wtime();
    parallelMergeSort(arr2, 0, n - 1);
    end = omp_get_wtime();
    printf("Parallel Time: %f seconds\n", end - start);

    free(arr);
    free(arr2);

    return 0;
}

// gcc -fopenmp pro1.c -o pro1
// ./pro1