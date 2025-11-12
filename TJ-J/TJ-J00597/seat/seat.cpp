#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int b[12][12]={},a[105]={},mine,p=0,n,m,i,j;
    cin>>n>>m;
    cin>>mine;
    for(i=2;i<=n*m;i++)
    {
        cin>>a[i];
    }
    a[1]=mine;
    sort(a+1,a+n*m+1,cmp);
    for(j=1;j<=m;j++)
    {
        if(j%2==0)
        {
            for(i=n;i>=1;i--)
            {
                p++;
                if(a[p]==mine)
                {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
        if(j%2==1)
        {
            for(i=1;i<=n;i++)
            {
                p++;
                if(a[p]==mine)
                {
                    cout<<j<<" "<<i;
                    return 0;
                }
            }
        }
    }
}
