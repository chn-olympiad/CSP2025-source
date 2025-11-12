#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],l;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<(n*m);i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<(n*m);i++)
    {
        int o=0,bh;
        for(int j=0;j<(n*m);i++)
        {
            if(a[j]>o)
            {
                o=a[j];
                bh=j;
                if(j==1)
                {
                    l=i+1;
                }
            }
        }
        a[bh]=0;
    }
    int aa=0,ab=0,ac=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(l<n*m && l>n*(m-1))
            {
                aa=l-n*(m-1);
                ab=j;
            }
            else if(l==n*m)
            {
                if(j%2==0)
                {
                    cout<<m<<" "<<1;
                }
                else
                {
                    cout<<m<<" "<<n;
                }
                return 0;
            }
        }
    }
    if(ab%2==0)
    {
        ac=aa;
    }
    else
    {
        ac=n-aa;
    }
    cout<<ab<<" "<<ac;
    return 0;
}
