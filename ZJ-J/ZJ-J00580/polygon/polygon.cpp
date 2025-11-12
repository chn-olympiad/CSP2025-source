#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[5005],ans;
void dfs(int x,int sum,int ma,int cnt){
	if(x==n+1){
		if(sum>2*ma&&cnt>=3) ans++;
		return;
	}
	dfs(x+1,sum+a[x],a[x],cnt+1);
	dfs(x+1,sum,ma,cnt);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans%998244353;
}
//40
