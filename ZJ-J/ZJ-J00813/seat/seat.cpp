#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200];
int r, weizhi;
int x, y;

int main()
{
    freopen("seat.in",  "r", stdin);
    freopen("seat.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n * m; i++)
    {
        scanf("%d", a+i);
    }
    r = a[0];
    sort(a, a+n*m, greater<int>());
    for (int i = 0; i < n * m; i++)
    {
        if (a[i] == r)
        {
            weizhi = i;
            break;
        }
    }
    x = weizhi / n + 1;
    y = weizhi % n + 1;
    if (x % 2 == 0)
    {
        y = n + 1 - y;
    }
    printf("%d %d", x, y);
    return 0;
}
