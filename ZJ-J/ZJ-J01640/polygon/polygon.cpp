#include<bits/stdc++.h>
using namespace std;
long long sum,mod=998244353,s1,s2;
int n,a[5010],mxn;
void dfs(int st,long long s,int mx)
{
	if(st>n)
	{
		if(s>mx*2)
		{
			sum++;
			sum%mod;
		}
		return;
	}
	dfs(st+1,s,mx);
	dfs(st+1,s+a[st],max(mx,a[st]));
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		  s1++;
		if(a[i]==0)
		  s2++;
		mxn=max(mxn,a[i]);
	}
	if(mxn==1)
	{
		long long m=1,mm=2,mn=1;
		for(int i=1;i<=s1;i++)
		  m=m*2%mod;
		for(int i=1;i<=s2;i++)
		  mn=mn*2%mod;
		for(int i=2;i<=s1;i++)
		  mm=(mm+i)%mod;
		cout<<(m%mod-mm)%mod*mn%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<sum;
	return 0;
}
