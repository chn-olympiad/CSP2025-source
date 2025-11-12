#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN = 5e5 + 5;

int n, k, a[MAXN];
bool checkA = 1, checkB = 1;

signed main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 1) {
            checkA = 0;
        }
        if (a[i] > 1) {
            checkB = 0;
        }
    }
    if (n <= 2 && k == 0 && checkA) {
        if (n == 1) {
            cout << "0";
            return 0;
        } else {
            cout << "1";
            return 0;
        }
        return 0;
    } else if (n <= 100 && k == 0 && checkA) {
        if (n == 1) {
            cout << "0";
            return 0;
        } else {
            cout << n / 2;
            return 0;
        }
        return 0;
    } else {
        cout << "1145141919810";
        return 0;
    }
    return 0;
}//期望得分10pts，我只读懂了题，甚至不会写除了特殊性质A以外的所有数据，我真的太菜了。 
