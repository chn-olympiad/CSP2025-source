#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int e = a[1];
    sort(a+1,a+1+n*m);
    int b = 0;
    for (int i = 1;i <= n*m;i++)
    {
        if (a[i] == e)
        {
            b=n*m+1-i;
            break;
        }
    }
    int c = b/n;
    int d = b%n;
    if (d == 0)
    {
        cout << c << " " << n;
    }
    else if((c+1)%2 == 1)
    {
        cout << (c+1) << " " << d;
    }
    else
    {
        cout << (c+1) << " " << (n-d+1);
    }
    return 0;
}

