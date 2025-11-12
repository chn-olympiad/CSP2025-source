#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n,maxn=0;
    cin>>n;
    bool all_1=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) all_1=0;
        maxn=max(maxn,a[i]);
    }
    if(all_1) cout<<n-2;
    else if(n==3)
    {
        if(a[1]+a[2]+a[3]>=2*maxn)
            cout<<1;
        else cout<<-1;
    }
    else cout<<n*(n-1)-n*a[1]/a[n];
	return 0;
 }
