#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,maxn=5010;
int a[maxn],n,ans=0,f[maxn],dub[maxn];
void dfs(int now,int pl,int num,int ed)
{
	if(now>=ed)
	{
		return ;
	}
	if(pl+a[now]>a[ed]&&num>=1)
	{
		ans+=dub[ed-now]-1;
		ans%=mod;
		return ;
	}
	dfs(now+1,pl+a[now],num+1,ed);
	dfs(now+1,pl,num,ed);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	memset(f,0,sizeof(f));
	dub[0]=1;
	for(int i=1;i<=n;i++)
	{
		dub[i]=(dub[i-1]*2)%mod;
	}

	if(a[n]==1)
	{
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=(f[i-1]*2+1)%mod;
		}
		ans=f[n];
		ans=ans-n*(n+1)/2;
	}
	else
	{
		for(int i=3;i<=n;i++)
		{
			dfs(1,0,0,i);
		}
	}
	cout << ans << "\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
