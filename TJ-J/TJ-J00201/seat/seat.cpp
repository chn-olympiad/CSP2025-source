#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    long long a[n][m];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << a[n][m];
    return 0;
}
