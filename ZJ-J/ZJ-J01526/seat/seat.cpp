#include <bits/stdc++.h>
using namespace std;

struct node {
    int v = INT_MAX;
    int p = 0;
};

bool comp(node ii, node jj) {
    return ii.v > jj.v;
}

int mod(int num, int m) {
    int res = num % m;
    if (res) return res;
    else return m;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<node> a(n * m + 1);
    for (int i = 1; i <= n * m; ++i) {
        cin >> a[i].v;
        a[i].p = i;
    }
    
    int num;
    sort(a.begin(), a.end(), comp);
    for (int i = 1; i <= n * m; ++i) {
        if (a[i].p == 1) {
            num = i;
            break;
        }
    }

    int x, y;
    y = (int)ceil(1.0 * num / n);
    if (y & 1) x = mod(num, 2 * n);
    else x = 2 * n - mod(num, 2 * n) + 1;

    cout << y << ' ' << x << '\n';

    return 0;
}
