#include<bits/stdc++.h>
using namespace std;
int n,k,xr[5005][5005],a[500005],ans,nnn[5005][5005];
void dfs(int step,int l,int qjs)
{
	if(step>n)
	{
		ans=max(ans,qjs);
		return;
	}
	if(nnn[l][step]) dfs(step+1,step+1,qjs+1);
	dfs(step+1,l,qjs);
	dfs(step+1,step,qjs);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		cout<<n/2;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			xr[i][j]=xr[i][j-1]^a[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(xr[i][j]==k) nnn[i][j]=1;
		}
	}
	dfs(1,1,0);
	cout<<ans;
	return 0;
}
