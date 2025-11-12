#include <bits/stdc++.h>
using namespace std;

string s;
int nums[10];

int main() {

    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;

    for (char c : s) {
        if (c >= '0' && c <= '9') {
            nums[c - '0']++;
        }
    }

    for (int i = 9; i >= 0; i--) {
        for (int j = 0; j < nums[i]; j++) cout << i;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}