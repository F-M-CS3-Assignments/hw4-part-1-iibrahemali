// Ibrahem - Mar 21

#include "bdc.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// convert vector to string
string vec_to_string(vector<int> v) {
    if (v.empty()) {
        return "[]";
    }

    string output = "[";
    for (size_t i = 0; i < v.size() - 1; i++) {
        output += to_string(v[i]) + ", ";
    }
    output += to_string(v.back()) + "]";
    return output;
}

// find largest divisible subset
vector<int> biggest_divisible_conglomerate(vector<int> input) {
    if (input.empty()) {
        return {};
    }

    // sort input
    sort(input.begin(), input.end());

    int n = input.size();
    vector<int> dp(n, 1); // track chain length
    vector<int> parent(n, -1); // track previous index

    int maxLen = 1; // max chain length
    int maxIdx = 0; // index of last element

    // build dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            // check divisibility
            if (input[i] % input[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        // update max length
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    // reconstruct chain
    vector<int> result;
    int curr = maxIdx;
    while (curr != -1) {
        result.push_back(input[curr]);
        curr = parent[curr];
    }

    // reverse for ascending order
    reverse(result.begin(), result.end());

    return result;
}
