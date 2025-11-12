#include<bits/stdc++.h>
using namespace std;
long long n,q,qs[1010],c[1010],tt,m,anss,a[1010];
long long MOD=998244353;
char cc;
struct st
{
	long long num,sum,lr;
}f[1010];
long long js(int x,int y)
{
	int ans=1;
	for(int i=y;i>=max(y-x,1);i--)
	{
		ans*=i;
	}
	return ans;
}
long long llrr(long long x)
{
	int l=0,r=n,ans;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(qs[mid]>=x)
		{
			r=mid-1;
		}
		else
		{
			ans=mid;
			l=mid+1;
		}
	}
	return ans;
}
void dfs(long long x,long long y,long long z)
{
	if(x>tt)
	{
		if(y>=m)
		{
			anss+=z;
		}
		return;
	}
	long long qw=f[x].lr-y-qs[f[x].lr];
	for(int i=0;i<=min(qw,f[x].sum);i++)
	{
		dfs(x+1,y+i,z*js(i,qw)*js(i,f[x].sum));
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>cc;
		a[i]=(cc=='1');
		qs[i]=qs[i-1]+1-a[i];
	}
	qs[0]=-1;
	c[0]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
	{
		if(c[i]!=c[i-1])
		{
			f[++tt].sum=1;
			f[tt].num=c[i];
			f[tt].lr=llrr(c[i]);
		}
		else
		{
			f[tt].sum++;
		}
	}
	if(llrr(c[n])-qs[llrr(c[n])]<m)
	{
		cout<<0;
		return 0;
	}
	dfs(1,0,1);
	cout<<anss;
	return 0;
}
