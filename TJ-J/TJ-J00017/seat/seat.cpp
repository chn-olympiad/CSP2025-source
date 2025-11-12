#include <bits/stdc++.h>
int n,m;
int x[105];
bool cmp(int x,int y)
{
    return x>y;
}
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int s=n*m;
    for(int i=1;i<=s;i++)
    {
        cin>>x[i];
    }
    int r=x[1];
    sort(x+1,x+s+1,cmp);
    for(int k=1;k<=s;k++)
    {
        for(int i=1;i<=m;i++)
        {
            if(i%2==1)
            {
                for(int j=1;j<=n;j++)
                {
                    int p=(i-1)*n+j;
                    if(x[p]==r)
                    {
                        cout<<i<<" "<<j;
                        return 0;
                    }
                }
            }
            else
            {
                for(int j=n;j>=1;j--)
                {
                    int p=(i-1)*n+n-j+1;
                    if(x[p]==r)
                    {
                        cout<<i<<" "<<j;
                        return 0;
                    }
                }
            }
        }
    }
}
