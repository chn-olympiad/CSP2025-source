#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int a[5005],n,f[5005],ans;
void dfs(int x,int maxn,int sum)
{
	if(sum>maxn*2)
	{
		ans++;
		ans%=p;
	}
	if(x>=n) return;
	for(int i=x+1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			dfs(i,max(maxn,a[i]),sum+a[i]);
			f[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	dfs(0,0,0);
	cout<<ans;
	return 0;
} 
