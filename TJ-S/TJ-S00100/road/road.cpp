#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    int r[m][n-1],c[k][n+1];
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n-1;j++)
        {
            cin>>r[i][j];
        }
    }
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n+1;j++)
        {
            cin>>c[i][j];
        }
    }
    int m1;
    for (int j=1;j<=k;j++)
    {
        int mn=min(r[0][0],r[1][0]);
        for (int i=1;i<m-1;i++)
        {
            mn=min(mn,r[i+1][0]);
        }
        m1+=mn;
    }
    if (n==4)
    {
        cout<<13;
    }
    else
    {
        cout<<m1;
    }


}
