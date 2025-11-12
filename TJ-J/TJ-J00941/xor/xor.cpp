#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1000005;
const ll M=1005;
ll n,m,T,a[N],b[N],f[N],ans;
struct NODE
{
	ll l,r;
}sum[N];

bool cmp(NODE a,NODE b)
{
	return a.r<b.r;
}

int main()
{
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	ll o=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			ll cnt=a[j];
			for(int k=j+1;k<=i;k++)
			{
				cnt^=a[k];
			}
			if(cnt==m)
			{
				sum[o].l=j;
				sum[o].r=i;
				o++;
			}
		}
	}
	sort(sum+1,sum+o+1,cmp);
	ans=1;
	ll LAST_r=sum[2].r;
	for(int i=3;i<=o;i++)
	{
		if(LAST_r<sum[i].l)
		{
			ans++;
			LAST_r=sum[i].r;
		}
	}
	cout<<ans;
	return 0;
} 
