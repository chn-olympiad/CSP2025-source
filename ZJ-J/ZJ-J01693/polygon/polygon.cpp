#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,a[N],vis[N];
long long ans=0;
void dfs(int nx,int sum,int ma,int tot)
{
	if(tot>=3&&sum>ma*2)
	{
		ans++;
		ans%=mod;
	}
	if(nx==n+1) return;
	for(int i=nx;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ma=max(ma,a[i]);
			sum+=a[i];
			is[++tot]=a[i];
			dfs(i+1,sum,ma,tot);
			tot--;
			vis[i]=0;
			sum-=a[i];
		}
	}
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
return 0;
}
