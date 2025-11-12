#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[105];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen ("seat.in", "r", stdin);
    freopen ("seat.out", "w", stdout);
    cin >> n >> m;
    int num = n * m;
    for (int i = 1; i <= num; i++)
    {
        cin >> a[i];
    }
    int r = a[1];
    sort (a + 1, a + num + 1, cmp);
    int sum = 1;
    for (int i = 1; i <= num; i++)
    {
        if (a[i] > r)
        {
            sum++;
        }
        if (a[i] == r)
        {
            break;
        }
    }
    int k = 1;
    int a = 1;
    for (int i = 1; i <= m; i++)
    {
        if (i % 2 != 0)
        {
            int b = 1;
            for (int j = 1; j <= n; j++)
            {
                if (k < sum)
                {
                    k++;
                    b++;
                }
                if (k == sum)
                {
                    cout << a << " " << b;
                    return 0;
                }
            }
        }
        if (i % 2 == 0)
        {
            int b = n;
            for (int j = n; j >= 1; j--)
            {
                if (k < sum)
                {
                    k++;
                    b--;
                }
                if (k == sum)
                {
                    cout << a << " " << b;
                    return 0;
                }
            }
        }
        a++;
    }
}
