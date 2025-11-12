#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n, m, a[105];
bool cmp(int i1, int i2)
{
    return i1 > i2;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n*m; i++)
    {
        cin >> a[i];
    }
    int tgt = a[1];
    sort(a+1, a+n*m+1, cmp);
    for (int i = 1; i <= n*m; i++)
    {
        if (a[i] == tgt)
        {
            tgt = i;
            break;
        }
    }
    int c = (tgt+n-1)/n, r;
    if (c%2 == 1)
    {
        r = (tgt-1)%n+1;
    }
    else
    {
        r = n-tgt%n+1;
    }
    cout << c << " " << r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
