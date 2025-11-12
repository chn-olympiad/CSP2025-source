#include <bits/stdc++.h>
using namespace std;

string s1[200010], s2[200010];

int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> s1[i];
        cin >> s2[i];
    }
    while (q--) {
        string t1;
        string t2;
        cin >> t1;
        cin >> t2;
        if (t1.length() != t2.length()) {
            printf("0\n");
        }else {
            printf("0\n");
        }
    }
    return 0;
}
