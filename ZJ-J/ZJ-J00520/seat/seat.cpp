#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int m, n;
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m * n; i++)
        scanf("%d", &a[i]);
    int k = a[1];
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    int l = 1, r = n * m + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == k)
        {
            l = mid;
            break;
        }
        else if (a[mid] < k) r = mid;
        else l = mid;
    }
    int col = l / m;
    if (l % m != 0) col++;
    int ln;
    if (col % 2 == 0)
    {
        ln = m + 1 - l % m;
        if (l % m == 0) ln = 1;
    }
    else
        ln = (l % m == 0) ? m : l % m;
    printf("%d %d\n", col, ln);
    return 0;
}