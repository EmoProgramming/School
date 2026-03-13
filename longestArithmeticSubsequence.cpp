#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    vector<int> sequence;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        sequence.push_back(number);
    }

    return 0;
}
