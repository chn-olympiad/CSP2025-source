#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

int t,n,ans,a[N][5];
priority_queue<int,vector<int>,greater<int> > q[3];

void solve(int x){
	while(q[x].size() > n / 2){
		ans -= q[x].top();
		q[x].pop();
	}
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t --> 0){
		ans = 0;
		scanf("%lld",&n);
		for(int i = 1;i <= n;i++)
			scanf("%lld %lld %lld",&a[i][1],&a[i][2],&a[i][3]);
		while(!q[1].empty()) q[1].pop();
		while(!q[2].empty()) q[2].pop();
		while(!q[3].empty()) q[3].pop();
		for(int i = 1;i <= n;i++){
			if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
				ans += a[i][1],q[1].push(min(a[i][1] - a[i][2],a[i][1] - a[i][3]));
			else if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
				ans += a[i][2],q[2].push(min(a[i][2] - a[i][1],a[i][2] - a[i][3]));
			else ans += a[i][3],q[3].push(min(a[i][3] - a[i][1],a[i][3] - a[i][2]));
		}
		if(q[1].size() > n / 2) solve(1);
		else if(q[2].size() > n / 2) solve(2);
		else if(q[3].size() > n / 2) solve(3);
		printf("%lld\n",ans);
	}
	return 0;
}