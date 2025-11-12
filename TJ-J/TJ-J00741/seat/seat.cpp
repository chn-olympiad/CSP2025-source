#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a1,n,m,ax,x,c,r;
    int a[110];
    cin >> n >> m >> a1;
    a[a1] = 1;
    for(int i = 1;i <= n*m - 1;i++)
    {
        cin >> ax;
        a[ax] = 1;
    }
    for(int j = 100;j >= 0;j--)
    {
        if(a[j] == 1)
        {
            x++;
            if(j == a1)
            {
                break;
            }
        }
    }
    c = x / n;
    r = x % n;
    if(r == 0)
    {
        cout << c << " " << n;
    }
    else
    {
        if(c % 2 == 0)
        {
            cout << c+1 << " " << r;
        }
        else
        {
            cout << c+1 << " " << n-r+1;
        }
    }
    return 0;
}
