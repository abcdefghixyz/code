//#include <stdio.h>
//#define MAX_ELEMENTS 100
//
//int total[MAX_ELEMENTS];
//int solution[MAX_ELEMENTS];
//int n, sum;
//
//void subsetSum(int k, int r, int s) {
//    int i;
//    solution[k] = 1;
//    if (s + total[k] == sum) {
//        printf("Subset with sum %d: ", sum);
//        for (i = 0; i <= k; i++) {
//            if (solution[i])
//                printf("%d ", total[i]);
//        }
//        printf("\n");
//    } else if (s + total[k] + total[k + 1] <= sum) {
//        subsetSum(k + 1, r - total[k], s + total[k]);
//    }
//    if ((s + r - total[k] >= sum) && (s + total[k + 1] <= sum)) {
//        solution[k] = 0;
//        subsetSum(k + 1, r - total[k], s);
//    }
//}
//
//void generateSubsets() {
//    int i, total_sum = 0;
//    for (i = 0; i < n; i++) {
//        total_sum += total[i];
//    }
//    if (total_sum < sum) {
//        printf("No subset possible with sum %d\n", sum);
//        return;
//    }
//    printf("Subsets with sum equal to %d are:\n", sum);
//    subsetSum(0, total_sum, 0);
//}
//
//int main() {
//    int i;
//    printf("Enter the number of elements: ");
//    scanf("%d", &n);
//    printf("Enter the elements: ");
//    for (i = 0; i < n; i++) {
//        scanf("%d", &total[i]);
//    }
//    printf("Enter the desired sum: ");
//    scanf("%d", &sum);
//    generateSubsets();
//    return 0;
//}

#include <stdio.h>
#include <stdlib.h> // For qsort

#define MAX_ELEMENTS 100

int total[MAX_ELEMENTS];
int solution[MAX_ELEMENTS];
int n, sum;

// Comparator function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void subsetSum(int k, int s, int remaining_sum) {
	int i;
    if (k == n) {
        if (s == sum) {
            printf("Subset with sum %d: ", sum);
            for (i = 0; i < n; i++) {
                if (solution[i])
                    printf("%d ", total[i]);
            }
            printf("\n");
        }
        return;
    }

    // Include the current element in the subset
    solution[k] = 1;
    subsetSum(k + 1, s + total[k], remaining_sum - total[k]);

    // Exclude the current element from the subset
    solution[k] = 0;
    if (s + remaining_sum - total[k] >= sum) {
        subsetSum(k + 1, s, remaining_sum - total[k]);
    }
}

void generateSubsets() {
	int i;
    int total_sum = 0;
    for ( i = 0; i < n; i++) {
        total_sum += total[i];
    }
    if (total_sum < sum) {
        printf("No subset possible with sum %d\n", sum);
        return;
    }
    printf("Subsets with sum equal to %d are:\n", sum);
    subsetSum(0, 0, total_sum);
}

int main() {
	int i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for ( i = 0; i < n; i++) {
        scanf("%d", &total[i]);
    }
    printf("Enter the desired sum: ");
    scanf("%d", &sum);
    
    // Sort the total array
    qsort(total, n, sizeof(int), compare);
    
    generateSubsets();
    return 0;
}

