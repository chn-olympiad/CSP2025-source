#include<bits/stdc++.h>
#define int long long
#define void inline void
using namespace std;
const int maxn = 1e+5 + 5;
int n, T, s1tot, s2tot, s3tot;
int a[maxn][3], s1[maxn], s2[maxn], s3[maxn];
void init()
{
    s1tot = s2tot = s3tot = 0;
}
inline bool cmp0(int x, int y)
{
    return a[x][0] - max(a[x][1], a[x][2]) < a[y][0] - max(a[y][1], a[y][2]);
}
inline bool cmp1(int x, int y)
{
    return a[x][1] - max(a[x][0], a[x][2]) < a[y][1] - max(a[y][0], a[y][2]);
}
inline bool cmp2(int x, int y)
{
    return a[x][2] - max(a[x][1], a[x][0]) < a[y][2] - max(a[y][1], a[y][0]);
}
void suibian3()
{
    cin >> n;
    init();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] >= max(a[i][1], a[i][2]))
        {
            ans += a[i][0];
            s1[++s1tot] = i;
        }
        else if (a[i][1] >= max(a[i][0], a[i][2]))
        {
            ans += a[i][1];
            s2[++s2tot] = i;
        }
        else
        {
            ans += a[i][2];
            s3[++s3tot] = i;
        }
    }
    sort(s1 + 1, s1 + s1tot + 1, cmp0);
    sort(s2 + 1, s2 + s2tot + 1, cmp1);
    sort(s3 + 1, s3 + s3tot + 1, cmp2);
    if (s1tot > n / 2)
    {
        swap(s3, s1);
        swap(s3tot, s1tot);
        for (int i = 1; i <= n; i++)
        {
            swap(a[i][2], a[i][0]);
        }
    }
    if (s2tot > n / 2)
    {
        swap(s3, s2);
        swap(s3tot, s2tot);
        for (int i = 1; i <= n; i++)
        {
            swap(a[i][2], a[i][1]);
        }
    }
    if (s3tot > n / 2)
    {
        for (int i = 1; i <= s3tot - n / 2; i++)
        {
            ans -= a[s3[i]][2];
            if (a[s3[i]][0] > a[s3[i]][1])
            {
                ans += a[s3[i]][0];
                s1[++s1tot] = s3[i];
            }
            else 
            {
                ans += a[s3[i]][1];
                s2[++s2tot] = s3[i];
            }
        }
    }
    cout << ans << '\n';
}
signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        suibian3();
    }
    return 0;
}
