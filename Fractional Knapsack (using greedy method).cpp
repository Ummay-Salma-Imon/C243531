#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    double value, weight;
};

bool compare(Item a, Item b) {
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(Item arr[], int n, double W) {
    sort(arr, arr + n, compare);

    double totalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            totalValue += arr[i].value;
        } else {
            totalValue += arr[i].value * (W / arr[i].weight);
            break;
        }  }

    return totalValue;}

int main() {
    int n;
    double W;
    cin >> n >> W;

    Item arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i].value >> arr[i].weight;

    cout << "Maximum value in Knapsack = " << fractionalKnapsack(arr, n, W) << endl;

    return 0;}
