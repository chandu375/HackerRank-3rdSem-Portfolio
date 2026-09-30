#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i++) {
        left += arr[i][i];
        right += arr[i][n - i - 1];
    }

    return abs(left - right);
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << diagonalDifference(arr) << endl;

    return 0;
}