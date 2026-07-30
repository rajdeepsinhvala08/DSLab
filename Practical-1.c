#include <stdio.h>

int main() {
    int arr[100], n, i, pos, value, key, found = 0;

    // Create array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Traversal
    printf("\nArray elements are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Insertion
    printf("\n\nEnter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    printf("Enter value to insert: ");
    scanf("%d", &value);

    for(i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos - 1] = value;
    n++;

    printf("\nArray after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Deletion
    printf("\n\nEnter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    for(i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    printf("\nArray after deletion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // Search
    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            printf("Element found at position %d\n", i + 1);
            break;
        }
    }

    if(!found) {
        printf("Elements not found.\n");
    }

    return 0;
}
