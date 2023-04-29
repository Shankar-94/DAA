#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();

    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    srand(time(NULL));
    printf("Generating random array of size %d...\n", n);
    for (i = 0; i < n; i++) {
        arr[i] = rand() %1000;
        printf("%d ", arr[i]);
    }
    printf("\n");
    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    clock_t end = clock();
    time_spent +=(double)(end-begin)/CLOCKS_PER_SEC;
    printf("\nExecution time: %f seconds\n",time_spent);
    return 0;
}
