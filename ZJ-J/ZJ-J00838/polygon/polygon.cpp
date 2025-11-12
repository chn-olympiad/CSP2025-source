#include <bits/stdc++.h>
using namespace std;
long long n, ans = 0;
vector<long long> a;
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    a.resize(n + 1);
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end());
    for (long long i = 3; i <= n; i++)
    {
        long long cnt = 0;
        for (long long S = 1; S < (1 << i - 1); S++)
        {
            long long sum = 0;
            for (long long j = 0; j < i - 1; j++)
            {
                if (S & (1 << j))
                    sum += a[j + 1];
            }
            if (sum > a[i])
                cnt++;
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}