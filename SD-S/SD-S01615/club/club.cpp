#include<bits/stdc++.h>
using namespace std;
const long long N = 200005;
long long ans,n,t;
long long a[N][7];
void dfs(long long u,long long t,long long x,long long y,long long z) { //第几 价值 1室人数 2室人数 3室人数 
	if(x > n / 2 || y > n / 2 || z > n / 2) return;
	if(u > n) {
		ans = max(ans,t);
		return;
	}
	dfs(u + 1,t + a[u][1],x + 1,y,z);
	dfs(u + 1,t + a[u][2],x,y + 1,z);
	dfs(u + 1,t + a[u][3],x,y,z + 1);
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	freopen("club1.in","r",stdin);
//	freopen("club2.in","r",stdin);
//	freopen("club3.in","r",stdin);
//	freopen("club4.in","r",stdin);
//	freopen("club5.in","r",stdin);
	cin>>t;
	while(t --) {
		cin>>n;
		ans = 0;
		for(long long i = 1;i <= n;i ++) {
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(1,0,0,0,0);
		cout<<ans<<"\n"; 
	}
	return 0;
}


