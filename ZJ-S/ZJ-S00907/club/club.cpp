#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, a[N][3];
void Main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &a[i][j]);
    vector<int> q0, q1, q2;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2])
        {
            q0.emplace_back(i);
            res += a[i][0];
        }
        else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2])
        {
            q1.emplace_back(i);
            res += a[i][1];
        }
        else
        {
            q2.emplace_back(i);
            res += a[i][2];
        }
    }
    sort(q0.begin(), q0.end(), [&](const int &x, const int &y)
         { return a[x][0] - max(a[x][1], a[x][2]) < a[y][0] - max(a[y][1], a[y][2]); });
    sort(q1.begin(), q1.end(), [&](const int &x, const int &y)
         { return a[x][1] - max(a[x][0], a[x][2]) < a[y][1] - max(a[y][0], a[y][2]); });
    sort(q2.begin(), q2.end(), [&](const int &x, const int &y)
         { return a[x][2] - max(a[x][1], a[x][0]) < a[y][2] - max(a[y][1], a[y][0]); });
    for (int i = 0; int(q0.size()) - i > n / 2; i++)
    {
        int x = q0[i];
        res -= a[x][0] - max(a[x][1], a[x][2]);
    }
    for (int i = 0; int(q1.size()) - i > n / 2; i++)
    {
        int x = q1[i];
        res -= a[x][1] - max(a[x][0], a[x][2]);
    }
    for (int i = 0; int(q2.size()) - i > n / 2; i++)
    {
        int x = q2[i];
        res -= a[x][2] - max(a[x][1], a[x][0]);
    }
    printf("%d\n", res);
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int TaskCnt = 1;
    scanf("%d", &TaskCnt);
    while (TaskCnt--)
        Main();
    return 0;
}