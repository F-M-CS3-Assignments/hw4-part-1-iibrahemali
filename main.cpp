// Ibrahem - Mar 21

#include "bdc.h"

#include <vector>
#include <cassert>
#include <iostream>
#include <set>

using namespace std;

int main() {
    // Test 1 (example from assignment description)
    vector<int> values = {28, 22, 7, 2, 8, 14, 24, 56};
    vector<int> ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    set<int> answerSet(ans.begin(), ans.end());
    set<int> soln = {56, 14, 7, 28};
    bool first = (answerSet == soln);
    soln = {56, 28, 14, 2};
    bool second = (answerSet == soln);
    assert(first || second);

    // Test 2
    values = {10, 5, 3, 15, 20};
    ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {20, 5, 10};
    set<int> answerSet2(ans.begin(), ans.end());
    assert(answerSet2 == soln);

    // Test 3: Empty input
    values = {};
    ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    assert(ans.empty());

    // Test 4: Single element
    values = {17};
    ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    assert(ans == vector<int>{17});

    // Test 5: No valid subset (all primes)
    values = {3, 5, 7, 11, 13};
    ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    assert(ans == vector<int>{13} || ans == vector<int>{3});

    // Test 6: All elements divisible by the first element
    values = {2, 4, 8, 16, 32};
    ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    assert(ans == values);

    // Test 7: Larger input with multiple valid subsets
    values = {1, 2, 3, 4, 6, 8, 12, 24};
    ans = biggest_divisible_conglomerate(values);
    cout << "input: " << vec_to_string(values) << endl;
    cout << "output: " << vec_to_string(ans) << endl << endl;
    soln = {1, 2, 4, 8, 24};
    set<int> answerSet3(ans.begin(), ans.end());
    assert(answerSet3 == soln);

    cout << "All tests passed!" << endl;
    return 0;
}
