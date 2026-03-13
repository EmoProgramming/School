#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool isInMap(int difference, int j, vector<unordered_map<int, int>>& DP) {
    if (DP[j].find(difference) != DP[j].end()) {
        return true;
    } else {
        return false;
    }
}

int main() {

    int n;
    vector<int> sequence;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        sequence.push_back(number);
    }

    vector<unordered_map<int, int>> DP(n);
    int difference;
    int maximumLength = 2;

    for (int i = n-2; i >= 0; i--) {

        for (int j = i+1; j < n; j++) {
            difference = sequence[j] - sequence[i];

            if (isInMap(difference, j, DP)) {
                DP[i][difference] = DP[j][difference] + 1;
                if (DP[i][difference] > maximumLength) {
                    maximumLength = DP[i][difference];
                }
            } else {
                DP[i][difference] = 2;
            }

        }
    }
    
    if (n == 1) {
        cout << 1;
    } else {
    cout << maximumLength;
    }

    return 0;
}
