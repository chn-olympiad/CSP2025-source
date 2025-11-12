#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int t, n, a[maxn][10];
int cnt[5], c[5][maxn];
long long ans;

inline int sec(int x, int y, int z)
{
    if ((y >= x && x >= z) || (z >= x && x >= y))
        return x;
    else if ((x >= y && y >= z) || (z >= y && y >= x))
        return y;
    else
        return z;
}

inline int maxpos(int x, int y, int z)
{
    if (x >= y && x >= z)
        return 1;
    else if (y >= x && y >= z)
        return 2;
    else
        return 3;
}

inline int secpos(int x, int y, int z)
{
    if ((y >= x && x >= z) || (z >= x && x >= y))
        return 1;
    else if ((x >= y && y >= z) || (z >= y && y >= x))
        return 2;
    else
        return 3;
}

inline int minpos(int x, int y, int z)
{
    if (x <= y && x <= z)
        return 1;
    else if (y <= x && y <= z)
        return 2;
    else
        return 3;
}

bool cmp(int i, int j)
{
    return a[i][4] > a[j][4];
}

int qin()
{
    int x = 0;
    char c;
    c = _getchar_nolock();
    while (c < '0' || c > '9')
        c = _getchar_nolock();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = _getchar_nolock();
    return x;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    t = qin();
    while (t--)
    {
        n = qin();
        cnt[1] = 0, cnt[2] = 0, cnt[3] = 0, ans = 0;
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= n; j++)
                c[i][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            a[i][1] = qin();
            a[i][2] = qin();
            a[i][3] = qin();
            a[i][5] = maxpos(a[i][1], a[i][2], a[i][3]);
            a[i][6] = secpos(a[i][1], a[i][2], a[i][3]);
            c[a[i][5]][++cnt[a[i][5]]] = i;
            a[i][4] = max(max(a[i][1], a[i][2]), a[i][3]) - sec(a[i][1], a[i][2], a[i][3]);
        }
        int maxx = maxpos(cnt[1], cnt[2], cnt[3]);
        sort(c[maxx] + 1, c[maxx] + cnt[maxx] + 1, cmp);
        int m = cnt[maxx];
        for (int i = n / 2 + 1; i <= m; i++)
        {
            c[a[c[maxx][i]][6]][++cnt[a[c[maxx][i]][6]]] = c[maxx][i];
            c[maxx][i] = 0;
        }
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= cnt[i]; j++)
                ans += a[c[i][j]][i];
        cout << ans << "\n";
    }
    return 0;
}