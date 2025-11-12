#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 1e5+5;

ll T, n;
inline void solve()
{
	ll ans = 0;
	scanf("%lld", &n);
	vector<vector<ll> > a(n+3, vector<ll>(3,0));
	priority_queue<ll> q[3];
	
	for(int i = 1; i <= n; i++) {
		ll mxv = 0, mxp = 0;
		for(int j = 0; j <= 2; j++){
			scanf("%lld", &a[i][j]);
			if(a[i][j] > mxv) {
				mxv = a[i][j]; mxp = j;
			}
		}
		sort(a[i].begin(),a[i].end());
		q[mxp].push(a[i][1]-a[i][2]);
		ans += a[i][2];
//		printf("chose %d to %lld, gain=%lld, del=%lld\n", i, mxp, a[i][2], a[i][1]-a[i][2]);		
	}
	
	size_t x = 3;
	for(int j = 0; j < 3; j++) {
		if(q[j].size() > (size_t)(n/2)) {
			x = j; break;
		}
	}
	if(x == 3) {
		printf("%lld\n", ans);
		return;
	}
	while(q[x].size() > (size_t)(n/2)) {
		ll t = q[x].top(); q[x].pop();
//		printf("ad del=%lld from %lld to %lld\n", t, ans, ans+t);
		ans += t;
	}
	printf("%lld\n", ans);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld", &T);
	for(int i = 0; i < T; i++) {
		solve();
	}




	return 0;
}

//check WA/RE/MLE/TLE

