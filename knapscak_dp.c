#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int capacity, int weights[], int values[], int n) {
    int i, w;
    int K[n + 1][capacity + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weights[i - 1] <= w)
                K[i][w] = max(values[i - 1] + K[i - 1][w - weights[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    printf("Maximum value: %d\n", K[n][capacity]);

    printf("Selected items: ");
    int res = K[n][capacity];
    for (i = n; i > 0 && res > 0; i--) {
      
        if (res == K[i - 1][capacity])
            continue;
        else {
            printf("%d ", i);
            res -= values[i - 1];
            capacity -= weights[i - 1];
        }
    }
}

int main() {
    int weights[] = {10, 20, 30,40,50};
    int values[] = {60, 100, 120,150,90};
    int capacity = 80;
    int n = sizeof(values) / sizeof(values[0]);

    knapsack(capacity, weights, values, n);
    
    return 0;
}


