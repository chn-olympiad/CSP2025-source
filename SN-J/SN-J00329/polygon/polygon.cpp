//SN-J00329 zhangjiakang xi'an gaoxindiyizhongxue
#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const int maxn=5e3+10;
const int mod=998244353;
int n;
ll a[maxn],ans=0;
void dfs(ll pos,ll tot,ll maxx)
{
	if(pos>n)
	{
		if(tot>maxx*2)ans++;
		ans%=mod;
		return ;
	}
	dfs(pos+1,tot,maxx);
	dfs(pos+1,tot+a[pos],a[pos]);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0);
	cout<<ans;    
	return 0;
}

