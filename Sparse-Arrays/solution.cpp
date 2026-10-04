#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> frequency;
    vector<int> result;

    for (string str : stringList) {
        frequency[str]++;
    }

    for (string query : queries) {
        result.push_back(frequency[query]);
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> stringList(n);

    for (int i = 0; i < n; i++) {
        cin >> stringList[i];
    }

    int q;
    cin >> q;

    vector<string> queries(q);

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    vector<int> result = matchingStrings(stringList, queries);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }

    return 0;
}