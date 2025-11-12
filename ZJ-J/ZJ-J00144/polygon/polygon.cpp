#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5010],cc[5010];
long long ans;
int cmp(int cp1,int cp2)
{
	return cp1>cp2;
}
long long ksm(long long ksm1,long long ksm2)
{
	long long pp=ksm1,ansa=1;
	while(ksm2)
	{
		if(ksm2&1)
		{
			ansa=ansa*pp;
			ansa%=MOD;
		}
		ksm2>>=1;
		pp=pp*pp;
		pp%=MOD;
	}
	return ansa;
}
void dfs(int k,int now,int chushi,int zg)
{
	if(zg>chushi&&k>2)
	{
		ans+=ksm(2,n-now);
		return;
	}
	if(k==n)
	{
		return;
	}
	for(int i=now+1;i<=n;i++)
	{
		dfs(k+1,i,chushi,zg+a[i]);
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n-1;i++)
	{
		dfs(1,i,a[i],0);
	}
	cout<<ans%MOD;
	return 0;
}