#include <bits/stdc++.h>
using namespace std;
int f[15][15];
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x=0;
    for(int i=1;i<=m;i++)
    {
        if (i%2==0)
        {
            for(int j=n;j>=1;j--)
            {
                x++;
                f[j][i]=x;
            }
        }
        else
        {
            for(int j=1;j<=n;j++)
            {
                x++;
                f[j][i]=x;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int numn=a[1];
    int pos;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if (a[i]==numn)
        {
            pos=i;
            break;
        }
    }
    //cout<<pos;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (f[i][j]==pos)
            {
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
