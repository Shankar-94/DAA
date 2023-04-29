#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BinarySearch(int arr[], int key, int low, int high) {
    int mid;
    if(low > high) {
        printf("Element not found");
    } else {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Element found at index %d", mid);
            return;
        } else if(arr[mid] > key) {
            return BinarySearch(arr, key, low, mid - 1);
        } else {
            return BinarySearch(arr, key, mid + 1, high);
        }
    }
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();

    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Elements of the array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Perform bubble sort
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - 1; j++) {
            if(arr[j + 1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nElements of the array after sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int key;
    printf("\nEnter the element to search for: ");
    scanf("%d", &key);

    BinarySearch(arr, key, 0, n - 1);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nElapsed time: %f seconds", time_spent);

    return 0;
}
