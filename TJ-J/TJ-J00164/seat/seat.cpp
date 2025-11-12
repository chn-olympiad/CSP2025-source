#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int q[n*m+1];
    for (int i=1;i<=n*m;i++)
    {
        cin>>q[i];
    }
    sort(q+1,q+n*m+2);
    int e=1;
    for (int j=1;j<=m;j++)
    {
        if (j%2==1)
        {
            for (int i=1;i<=n;i++)
            {
                a[i][j]==q[e];
                e++;
            }

        }
        else
        {
            for (int i=n;i>=1;i--)
            {
                a[i][j]==q[e];
                e++;
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]==q[1])
            {
                cout<<i<<" "<<j;
            }
        }
    }

}
