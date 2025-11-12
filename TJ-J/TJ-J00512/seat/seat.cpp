#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 10;
int n, m, tot, a[N];
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    tot = n * m;
    for (int i = 1; i <= tot; i++) cin >> a[i];
    int rnk = 1;
    for (int i = 2; i <= tot; i++) if (a[i] > a[1]) rnk++;
    int row, col = (rnk + n - 1) / n;
    int id = rnk - (col - 1) * n;
    if (col & 1) row = id;
    else row = n - id + 1;
    cout << col << ' ' << row << '\n';
    return 0;
}
