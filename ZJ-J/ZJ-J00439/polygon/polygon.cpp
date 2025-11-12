#include<bits/stdc++.h>
using namespace std;
const int N=5010;
long long n,ans=0;
long long a[N];
vector<long long> v(n+10);
void dfs(long long x,long long y)
{
	if(x==n+1)
	{
		if(y<3)
		{
			return;
		}
		long long t=0,maxx=0;
		for(int i=0;i<y;i++)
		{
			t+=v[i];
			maxx=max(maxx,v[i]);
		}
		if(t>maxx*2)
		{
			ans++;
		}
		return;
	}
	else if(x>n)
	{
		return;
	}
	for(int i=1;i<n;i++)
	{
		v[y]=a[x];
		dfs(i+x,y+1);
		v[y]=0;
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		dfs(i,0);
	}
	cout<<ans;
	return 0;
}
