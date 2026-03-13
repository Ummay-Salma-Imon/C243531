#include <iostream>
using namespace std;


int binarySearch(int sortedArr[], int arrSize, int targetKey)
{
    int left = 0;          // Start of search range
    int right = arrSize - 1; // End of search range

    // Keep narrowing the range until we find the key or exhaust the array
    while (left <= right)
    {
        int middle = (left + right) / 2; // Find midpoint of current range

        // If mid element is the key, return its index immediately
        if (sortedArr[middle] == targetKey)
            return middle;
        // Key is bigger than mid? Look only in the right half
        else if (sortedArr[middle] < targetKey)
            left = middle + 1;
        // Key is smaller than mid? Look only in the left half
        else
            right = middle - 1;
    }
    // If loop ends, key isn't in the array
    return -1;
}

int main()
{
    int numElements, searchKey;
    // Get number of elements (array must be sorted!)
    cin >> numElements;

    int userArray[numElements];
    // Input sorted array elements (user must enter in order!)
    for (int i = 0; i < numElements; i++)
        cin >> userArray[i];

    // Get the key we want to find
    cin >> searchKey;

    // Run binary search and store result
    int keyPosition = binarySearch(userArray, numElements, searchKey);

    // Print result - index if found, "Not found" otherwise
    if (keyPosition != -1)
        cout << keyPosition;
    else
        cout << "Not found";

    return 0;
}
