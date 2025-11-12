#include<bits/stdc++.h>
using namespace std;
int n,a[5001],mx,s,s1,s0,ss,ss1,ss0,sss;
void dfs(int c,int sh,int maxx,int zzz)
{
	if(c==n+1)
	{
		if(maxx*2<sh&&zzz>=3)
		  ++s;
		return;
	}
	dfs(c+1,sh,maxx,zzz);
	dfs(c+1,sh+a[c],max(maxx,a[c]),zzz+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	dfs(1,0,0,0);
	cout<<s;
	return 0;
}