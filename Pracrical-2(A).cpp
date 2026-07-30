#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Pointer points to the last element of the array
    int *ptr = &arr [n - 1];

    cout << "Array elements in reverse order: ";

    for(int i = 0; i < n; i++)
    {
        cout << *ptr << " ";
        ptr--;
    }

    return 0;
}
