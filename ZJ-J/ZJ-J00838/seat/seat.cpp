#include <bits/stdc++.h>
using namespace std;
long long n, m, A1, idx;
vector<long long> a;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    a.resize(n * m + 1);
    for (long long i = 1; i <= n * m; i++)
        cin >> a[i];
    A1 = a[1];
    sort(a.begin() + 1, a.end(), greater<long long>());
    idx = lower_bound(a.begin() + 1, a.end(), A1, greater<long long>()) - a.begin();
    cout << ((idx - 1) / n + 1) << ' ';
    if ((idx - 1) % (2 * n) + 1 <= n)
        cout << (idx - 1) % (2 * n) + 1 << endl;
    else
        cout << 2 * n - ((idx - 1) % (2 * n)) << endl;
    return 0;
}