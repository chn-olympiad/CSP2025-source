#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;

    vector<int> vec;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            vec.push_back(s[i] - '0');
        }
    }

    sort(vec.begin(), vec.end(), greater<int>());
    for (int i = 0; i < vec.size(); i++) {
        printf("%d", vec[i]);
    }
    return 0;
}

