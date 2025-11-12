#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109];
int b[11][11],sum;
int cdl;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    cdl=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            b[i][j]=a[n*m-sum];
            sum++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n/2;j++)
        {
            if(i%2==0)
            {
                swap(b[i][j],b[i][n-(j-1)]);
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(b[i][j]==cdl)
            {
                cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
