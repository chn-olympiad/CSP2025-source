#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5009];
long long ans[5009];
int dfs(int u,int v)
{
	if (u==n+1)
	{
		long long sum=0,mx=0,k=0;
		for(int i=1;i<v;i++)
		{
			sum+=ans[i];
			mx=max(mx,ans[i]);
		}
		if (sum>mx*2&&v>3) k++;
		return k;
	}
	ans[v]=a[u];
	return (dfs(u+1,v+1)+dfs(u+1,v))%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cout<<dfs(1,1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}