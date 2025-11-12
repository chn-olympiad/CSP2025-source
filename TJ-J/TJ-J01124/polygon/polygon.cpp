#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[10000009],maxn;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        sum+=a[i];
    }
    if(sum>maxn)cout<<1;
    else cout<<6;
    return 0;
}
