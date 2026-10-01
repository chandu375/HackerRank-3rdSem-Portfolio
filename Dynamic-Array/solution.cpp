#include <iostream>
#include <vector>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<vector<int>> arr(n);
    vector<int> answers;
    int lastAnswer = 0;

    for (auto q : queries) {
        int type = q[0];
        int x = q[1];
        int y = q[2];

        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            arr[idx].push_back(y);
        }
        else {
            lastAnswer = arr[idx][y % arr[idx].size()];
            answers.push_back(lastAnswer);
        }
    }

    return answers;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> queries(q, vector<int>(3));

    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> result = dynamicArray(n, queries);

    for (int value : result) {
        cout << value << endl;
    }

    return 0;
}