#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
void dfs(int now,int maxx,int sum,int nxt)
{
	if(now>=3&&maxx*2<sum) ans++;
	if(now==n) return;
	for(int i=nxt+1;i<=n;++i)
	dfs(now+1,max(maxx,a[i]),sum+a[i],i);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i)
	for(int j=i+1;j<=n;++j)
	dfs(2,max(a[i],a[j]),a[i]+a[j],j);
	cout<<ans;
	return 0;
}//40pts
