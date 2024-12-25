#define _USE_MATH_DEFINES 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int rand10(int mmax);
double rand_double(double dmin, double dmax);
int* rand10_arr(int n, int mmax);
double* rand_double_arr(int n, double dmin, double dmax);

int main() {
    int mmax, n, K;
    double dmin, dmax;
    system("chcp 1251");
    srand(time(NULL));
    printf("¬ведите максимальное число дл€ генерации случайного целого числа:\n");
    scanf("%d", &K);
    printf("¬ведите количество случайных чисел дл€ генерации:\n");
    scanf("%d", &n);
    int* array = rand10_arr(n, K);
    int* counter = (int*)calloc(K + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        counter[array[i]]++;
    }
    int max_count = 0;
    for (int i = 1; i <= K; i++) {
        if (counter[i] > max_count) {
            max_count = counter[i];
        }
    }
    printf("√истограмма:\n");
    const int R = 50;
    for (int i = 1; i <= K; i++) {
        double x = (double)counter[i] / max_count * R;
        printf("%d | ", i);
        for (int j = 0; j < (int)x; j++) {
            printf("*");
        }
        printf(" (%d)\n", counter[i]);
    }
    free(array);
    free(counter);
}
int rand10(int mmax) {
    return 1 + rand() % mmax;
}

int* rand10_arr(int n, int mmax) {
    int* ptr_arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        ptr_arr[i] = rand10(mmax);
    }
    return ptr_arr;
}

double rand_double(double dmin, double dmax) {
    return dmin + (dmax - dmin) * rand() / RAND_MAX;
}

double* rand_double_arr(int n, double dmin, double dmax) {
    double* ptr_arr = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        ptr_arr[i] = rand_double(dmin, dmax);
    }
    return ptr_arr;
}