#include <bits/stdc++.h>
using namespace std;

int maxOfNeighbors(const vector<int>& arr, int i) {
    int left = (i - 1 >= 0) ? arr[i - 1] : INT_MIN;
    int right = (i + 1 < (int)arr.size()) ? arr[i + 1] : INT_MIN;
    return max(left, right);
}

void fun(vector<int> arr) {
    int score = 0;

    while ((int)arr.size() > 1) {
        // Find index of max element
        int maxIdx = 0;
        for (int i = 1; i < (int)arr.size(); ++i) {
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }

        // Add max of neighbors to score
        int addScore = maxOfNeighbors(arr, maxIdx);
        if (addScore != INT_MIN) { // Only add if at least one neighbor exists
            score += addScore;
        }

        // Remove arr[maxIdx]
        arr.erase(arr.begin() + maxIdx);
    }

    cout << score << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        while (q--) {
            int i, x, score = 0;
            cin >> i >> x;
            a[i] = x;
            fun(a);
        }
    }
    return 0;
}
