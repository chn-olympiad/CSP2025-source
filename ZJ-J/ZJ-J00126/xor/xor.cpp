#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    int j = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = k ^ sum[i];
        bool flag = 0;
        int tmp = j;
        while (tmp <= i)
        {
            if (sum[tmp - 1] == x)
            {
                flag = 1;
                ans++;
                break;
            }
            tmp++;
        }
        if (flag)
        {
            j = i + 1;
        }
    }
    cout << ans << endl;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int _;
    _ = 1;
    while (_--)
    {
        solve();
    }
    return 0;
}