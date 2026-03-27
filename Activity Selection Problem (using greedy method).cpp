#include <iostream>
#include <algorithm>
using namespace std;

struct Activity {
    int start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(Activity arr[], int n) {
    sort(arr, arr + n, compare);

    cout << "Selected Activities:\n";

    int i = 0;
    cout << "(" << arr[i].start << ", " << arr[i].finish << ")\n";

    for (int j = 1; j < n; j++) {
        if (arr[j].start >= arr[i].finish) {
            cout << "(" << arr[j].start << ", " << arr[j].finish << ")\n";
            i = j; // update last selected activity
        }
    }
}

int main() {
    int n;
    cout << "Enter number of activities: ";
    cin >> n;

    Activity arr[n];

    cout << "Enter start and finish times of activities:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i].start >> arr[i].finish;  }

    activitySelection(arr, n);

    return 0;}
