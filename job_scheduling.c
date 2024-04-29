#include <stdio.h>
#include <stdlib.h>

struct Job {
    int id;
    int deadline;
    int profit;
};

int compare(const void *a, const void *b) {
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

int findMaxDeadline(struct Job arr[], int n) {
    int maxDeadline = 0,i;
    for ( i = 0; i < n; ++i) {
        if (arr[i].deadline > maxDeadline)
            maxDeadline = arr[i].deadline;
    }
    return maxDeadline;
}

void jobSequence(struct Job arr[], int n) {
    qsort(arr, n, sizeof(struct Job), compare);

    int maxDeadline = findMaxDeadline(arr, n);
    int *slot = (int *)malloc(maxDeadline * sizeof(int));
    if (slot == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int i, j;
    for (i = 0; i < maxDeadline; ++i)
        slot[i] = -1;

    for (i = 0; i < n; ++i) {
        for (j = arr[i].deadline - 1; j >= 0; --j) {
            if (slot[j] == -1) {
                slot[j] = arr[i].id;
                break;
            }
        }
    }

    printf("Job sequence to maximize profit: ");
    for (i = 0; i < maxDeadline; ++i) {
        if (slot[i] != -1)
            printf("%d ", slot[i]);
    }
    printf("\n");

    free(slot);
}

int main() {
    int i,n;

    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    while (getchar() != '\n'); 

    struct Job *jobs = (struct Job *)malloc(n * sizeof(struct Job));
    if (jobs == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter deadline and profit for each job:\n");
    for (i = 0; i < n; ++i) {
        printf("Job %d: ", i + 1);
        scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
        while (getchar() != '\n'); 
        jobs[i].id = i + 1;
    }

    jobSequence(jobs, n);

    free(jobs);

    return 0;
}
