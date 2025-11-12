#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n,r,q=0;
    cin>>m>>n;
    int a=m*n,b[a];
    int c[21][21];
    cin>>r;
    for(int i=2;i<=a;i++)
    {
        cin>>b[i];
    }
    b[a]=r;
    for(int i=1;i<=a;i++)
    {
        int e,f;
        e=b[i];
        f=b[i+1];
        b[i]=f;
        b[i+1]=e;
    }
    for(int i=1;i<=m;i++)
    {
        if(m%2==1)
        {
            for(int j=1;j<=n;j++)
            {
                q++;
                c[i][j]=b[q];

            }
        }
        else
        {
            for(int j=n;j>=1;j--)
            {
                q++;
                c[i][j]=b[q];

            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int f=c[i][j];
            if(f==r)
            {
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
