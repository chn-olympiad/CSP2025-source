#include<bits/stdc++.h>
using namespace std;
int n,a[100005],vis[10005],ans,vvs[10005],tns,qc[100005][105],t;
void dfs(int step,int k)
{
	if(step>k)
	{
		int mx=-1e9,h=0,hh=0;
		t++;
		for(int i=1;i<=k;i++) qc[t][k]=vvs[i];
		sort(qc[t]+1,qc[t]+k+1);
		for(int i=1;i<t;i++)
		{
			int as=0;
			for(int j=1;j<=k;j++) if(qc[i][j]==qc[t][j]) as++;
			if(as==k) hh=1;
		}
		if(hh==1) return;
		for(int i=0;i<=k;i++)
		{
			mx=max(a[vvs[i]],mx);
			h+=a[vvs[i]];
		}
		if(mx*2<h) ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vvs[step]=i;
			vis[i]=1;
			dfs(step+1,k);
			vis[i]=0;
			vvs[step]=0;
		}
	}
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		dfs(1,i);
	}
	cout<<ans-1;
	return 0;
}
