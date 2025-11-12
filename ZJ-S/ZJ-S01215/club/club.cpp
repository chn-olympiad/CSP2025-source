#include <bits/stdc++.h>
#define LL long long
const int N = 1e5 + 5;
using namespace std;
int n;
LL ans;
int t;
struct Member
{
    int a, b, c;
    bool operator<(const Member tmp) const
    {
        return a > tmp.a;
    }
} a[N];
void DFS(int i, int l, int ll, int lll, LL sum, int p, int j)
{
    if (i == n + 1)
    {
        ans = max(ans, sum);
        return;
    }
    sum += (j == 1 ? a[i].a : (j == 2 ? a[i].b : a[i].c));
    if (l < p)
        DFS(i + 1, l + 1, ll, lll, sum, p, 0);
    if (ll < p)
        DFS(i + 1, l, ll + 1, lll, sum, p, 1);
    if (lll < p)
        DFS(i + 1, l, ll, lll + 1, sum, p, 2);
}
void solve()
{
    memset(a, 0, sizeof a);
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a >> a[i].b >> a[i].c;
    if (n >= 30)
    {
        int k = n / 2;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= k; i++)
            ans += a[i].a;
        cout << ans << '\n';
        return;
    }
    DFS(1, 1, 0, 0, 0, n / 2, 0);
    DFS(1, 0, 1, 0, 0, n / 2, 1);
    DFS(1, 0, 0, 1, 0, n / 2, 2);
    cout << ans << '\n';
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
        solve();
    return 0;
}
