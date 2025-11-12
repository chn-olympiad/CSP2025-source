#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],s[5001];
long long j=3;
bool flag[5001];
long long ans=0;
void dfs(long long v,int dep)
{
	if(dep>=j)
	{
		return;
	}
	if(v>a[j])
	{
		ans++;
		ans%=998244353;
	}
		for(int i=dep;i<j;i++)
		{
			if(flag[i]==0)
			{
				flag[i]=1;
				dfs(v+a[i],i);
				flag[i]=0;
			}
		}
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
	for(j;j<=n;j++)
	{
		memset(flag,0,sizeof(flag));
		dfs(0,1);
	}
	cout<<ans%998244353;
	return 0;
}

