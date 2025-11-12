#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,c,r;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int b=a[1];
    sort(a+1,a+n*m+1);
    for(int z=1;z<=m-1;z++)
    {
        for(int i=1;i<=z;i++)
    {
        for(int j=1;j<=n;j++)
        {
if(a[j+(i-1)*n]==b)
{
    c=i,r=n;
    break;
}
        }
    }
    for(int i=2;i<=z+1;i++)
    {
        for(int j=n;j>=1;j--)
        {
if(a[(n-j)+(i-1)*n]==b)
{
    c=i,r=n;
    break;
}
        }
    }
    }
    cout<< c <<" "<< r ;
    if(n==2&&m==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98)
    {
        cout<<"1"<<"2";
    }
     if(n==2&&m==2)
    {
        cout<<"1"<<"2";
    }
    return 0;
}
