#include <stdio.h>

int main() {
    int low = 0, n, i, j, mid, high, temp, key;
    int a[20], flag = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the search element: ");
    scanf("%d", &key);

    // Sorting the array using bubble sort
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Printing the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (key == a[mid]) {
            flag = 1;
            break;
        } else if (key > a[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (flag == 1) {
        printf("Search element is found at position %d\n", mid);
    } else {
        printf("Search element is not found\n");
    }

    return 0;
}

