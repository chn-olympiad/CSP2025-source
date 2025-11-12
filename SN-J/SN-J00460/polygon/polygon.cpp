//SN-J00460  把小煜  西安辅轮中学
#include<bits/stdc++.h>
#define int long long
const int mod=998244353;
using namespace std;
int n,a[5010],ans;
void dfs(int use,int x,int mx,int sm)
{
	if(x>n)
	{
		if(use>=3 && mx*2<sm) ans=(ans+1)%mod;
		return;	
	}
	dfs(use+1,x+1,max(mx,a[x]),sm+a[x]);
	dfs(use,x+1,mx,sm);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//记得检查：
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(0,1,0,0);
	cout<<ans;
	return 0;
}
