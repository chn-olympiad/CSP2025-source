#include<bits/stdc++.h>
using namespace std;
int a[5010],n,vis[5010];
const int mod=998244353;
long long cnt;
void dfs(int p,int ans,long long sum,int maxl,int t)
{
	if(p==ans+1)
	{
		if(sum>maxl*2)
		{
			cnt=(cnt+1)%mod;
			return;
		}
	}
	for(int i=t+1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(a[i]>maxl)
			dfs(p+1,ans,sum+a[i],a[i],i);
			else dfs(p+1,ans,sum+a[i],maxl,i);
			vis[i]=0;
		}
	}
}
int main()
{
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		dfs(1,i,0,0,0);
	}
	cout<<cnt;
	return 0;
}
//#Shang4Shan3Ruo6Shui4
