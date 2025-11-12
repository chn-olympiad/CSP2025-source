#include <bits/stdc++.h>
using namespace std;

int main() {
    feropen("employ.in", "r", stdin);
    feropen("employ.out", "w", stdout);
    int n;
    cin >> n;
    cout << n*(n + 1) / 2;
    return 0;
}
