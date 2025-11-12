#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
     return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[1005],n,m,b[1005][1005];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            b[i][j]=a[i];
        }
    }
    int num=a[1];
    int p;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==num)
        {
           p=i;
           break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=m;j++)
        {
            if(a[p]==b[i][j])
            {
                cout<<j<<" "<<i;
                break;
            }
        }
    }
    return 0;
}
