#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[500005],last=0,n,k,f[500005];
ll c[500005],dp[500005];
struct shu{
	ll wei,v,l;
}b[500005];
bool cmp(shu a,shu b)
{
	if(a.v==b.v)
	{
		return a.wei>b.wei;
	}
	return a.v<b.v;
}
ll maxx(ll a,ll b)
{
	return a>b?a:b;
}
ll lower(ll p)
{
	ll l=0,r=n+1,mid;
	while(true)
	{
		//r=b[r].l;l=b[l].l;
		if(b[l].v==b[r-1].v)
		{
			if(b[l].v==p) return b[l].l;
			else return 13;
		}
		mid=(l+r)/2;
		if(b[mid].v>p) r=mid;
		else l=mid;
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	ll cm=0;
	//没有思路
	//it seems that i can sort and ^^^^^^^^^^^
	//haha huila 10:28 AC
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i].v=a[i]^cm;
		cm=cm^a[i];
		f[i]=b[i].v;
		b[i].wei=i;
	}
	b[0].v=0;
	sort(b,b+n+1,cmp);
	for(ll i=1;i<=n;i++)
	{
		if(b[i].v==b[last].v)b[i].l=last;
		else{b[i].l=i;last=i;}
	}
	for(ll i=1;i<=n;i++)
	{
			bool xm=true;
			ll mm=lower(f[i]^k);
			if(mm==13)
			{
				c[i]=500002;
				continue;
			}
			while(b[mm].wei>=i)
			{
				++mm;
				if(b[mm].v!=(f[i]^k))
				{
					c[i]=500002;
					xm=false;
					break;
				}
			}
			if(xm)c[i]=b[mm].wei;
	}
	memset(dp,0,sizeof(dp));
	dp[500002]=-1;
	for(ll i=1;i<=n;i++)
	{
		dp[i]=maxx(dp[i-1],dp[c[i]]+1);
	}
	cout<<dp[n];
	return 0;
}