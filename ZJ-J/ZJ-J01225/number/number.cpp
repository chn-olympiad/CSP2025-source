#include <bits/stdc++.h>
using namespace std;
bool isdigit(char c) {
    return (c >= '0' && c <= '9');
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string str;
    getline(cin, str);
    vector<int> nums;
    for (char c : str) {
        if (c >= '0' && c <= '9') {
            nums.push_back(c - '0');
        }
    }
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--) {
        cout << nums[i];
    }
    return 0;
}