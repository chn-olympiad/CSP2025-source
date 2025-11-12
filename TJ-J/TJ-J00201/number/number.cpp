#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    char s[1000010];
    long long a[1000010], n = 1000010;
    for(int x = 0; x <= n; x++)
    {
        cin >> s[x];
    }
    for (int i = 0; i <= n; i++)
    {
        if (s[i] <= 9) a[i] = s[i];
    }
    sort(a, a+n);
    for (int j = n; j >= 0; j++)
    {
        if (a[j] == a[j-1])
        {
            a[j] = 0;
            a[j] = a[j-1];
            cout << a[j];
        }
    }
    return 0;
}
