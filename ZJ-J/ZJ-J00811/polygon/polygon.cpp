#include<bits/stdc++.h>
using namespace std;
const int slen=1e5+10;
int a[slen],b[slen];int n,ans;
bool f[slen],f2[slen];
void dfs(int v,int t,int maxv,int pm)
{
	if(t==n)
	{
		if(v>maxv&&f2[pm]!=1)	ans++;
		f2[pm]=1;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==1)	continue;
		f[i]=1;
		maxv=max(maxv,a[i]);
		dfs(v+2*a[i],t+1,maxv,pm*10+a[i]);
		f[i]=0;
	}
	if(v>maxv&&f2[pm]!=1)	ans++;
		f2[pm]=1;
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}