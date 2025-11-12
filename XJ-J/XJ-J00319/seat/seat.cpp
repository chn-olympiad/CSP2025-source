#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
int n,m,c,r,a[N],k,b,cnt;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k)
        {
            b=i;
            break;
        }
    }
    if(b%n==0)
    {
        c=b/n;
        if(c%2==1)r=n;
        else      r=1;
    }
    else
    {
        c=b/n+1;
        if(c%2==1)
        {
            r=b%n;
        }
        else
        {
            r=n-(b%n)+1;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}