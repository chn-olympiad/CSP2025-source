//02
#include <bits/stdc++.h>
using namespace std;
int n,m,a[114514],c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int b;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n*m;i++)
    {
        b=max(a[i],a[i+1]);
    }
    for (int i=1;i<=n*m;i++)
    {
        if (a[1]==max(a[i],b))
        {
            c=1;
            r=1;
        }
        else
        {
            if (n<=m)
            {
            for (int j=1;j<=n;j++)
            {
                if (i<=j*m)
                {
                    c=j;
                    r=m;
                }
                if (i==j*n+j&&j%2==1)
                {//(n+1),(n-j);
                    c=n+1;
                    r=n-j+2;
                }
                if (i==j*n+j&&j%2==0)
                {
                    c=n+1;
                    r=1;
                }
            }
            }
            else
            {
                for (int j=1;j<=m;j++)
                {
                if (i<=j*m)
                {
                    c=j;
                    r=m;
                }
                if (i==j*n+j&&j%2==1)
                {//(n+1),(n-j);
                    c=n+1;
                    r=n-j+2;
                }
                if (i==j*n+j&&j%2==0)
                {
                    c=n+1;
                    r=1;
                }
                }
            }

        }
    }
    cout<<c<<" "<<r;
    return 0;
}
