#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans;
void dfs(int x,int y,int maxn)
{
	if(x>n){
		if(y>maxn*2) ans++;
		return;
	}
	dfs(x+1,y+a[x],max(maxn,a[x]));
	dfs(x+1,y,maxn);
}
signed main(void)
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0,0);
	printf("%lld",ans);
	return 0;
}
