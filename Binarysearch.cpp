#include <iostream>
using namespace std;

int binarySearch(int sortedArr[], int arrSize, int targetKey)
{
    int left = 0;          // Start of search range (index)
    int right = arrSize - 1; // End of search range (index)

    // Narrow down search range by half each time
    while (left <= right)
    {
        int middle = (left + right) / 2; // Midpoint index

        // If mid element is the key, return POSITION (index + 1)
        if (sortedArr[middle] == targetKey)
            return middle + 1; // Convert index to human position
        // Key is bigger? Search right half
        else if (sortedArr[middle] < targetKey)
            left = middle + 1;
        // Key is smaller? Search left half
        else
            right = middle - 1;
    }
    // Key not found
    return -1;
}

int main()
{
    int numElements, searchKey;
    // Ask for array size (array MUST be sorted!)
    cout << "Enter number of elements (sorted array): ";
    cin >> numElements;

    int userArray[numElements];
    cout << "Enter " << numElements << " sorted numbers: ";
    for (int i = 0; i < numElements; i++)
        cin >> userArray[i];

    // Ask for key to search
    cout << "Enter number to search: ";
    cin >> searchKey;

    // Get POSITION (not index)
    int keyPosition = binarySearch(userArray, numElements, searchKey);

    // Print result (position-based)
    if (keyPosition != -1)
        cout << "Number found at position: " << keyPosition << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
