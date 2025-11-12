#include <bits/stdc++.h>
using namespace std;
int a[120];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    int sc=a[1],pm;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==sc)
        {
            pm=i;break;
        }
    }
    int h=pm%n,l=pm/n;
    if(h==0) h=n;
    else l++;
    if(l%2==1)
    {
        cout<<l<<" "<<h;
    }
    else
    {
        cout<<l<<" "<<n-h+1;
    }
    return 0;
}
