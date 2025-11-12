#include <bits/stdc++.h>
using namespace std;
long long n, k, ans = 0;
vector<long long> a, ps, s_idx;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n + 1);
    s_idx.resize(n + 1);
    ps.resize(n + 1, 0);
    for (long long i = 1; i <= n; i++)
        cin >> a[i], ps[i] = ps[i - 1] ^ a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
        {
            if ((ps[j] ^ ps[i - 1]) == k)
            {
                i = j;
                ans++;
                break;
            }
        }
    cout << ans << endl;
    return 0;
}