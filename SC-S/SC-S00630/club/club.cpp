#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e5 + 5;
int n;
array <int,3> a[N];

void solve() {
	ll ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
	priority_queue <pair <int,int>> q1,q2,q3;
	for(int i = 1;i <= n;i++) {
		int maxx = max({a[i][0],a[i][1],a[i][2]});
		ans += maxx;
		auto t1 = make_pair(-(a[i][0] - max(a[i][1],a[i][2])),i);
		auto t2 = make_pair(-(a[i][1] - max(a[i][0],a[i][2])),i);
		auto t3 = make_pair(-(a[i][2] - max(a[i][0],a[i][1])),i);
		if(a[i][0] == maxx) 
			q1.push(t1);
		else if(a[i][1] == maxx) q2.push(t2);
		else q3.push(t3);
		if((int)q1.size() > n / 2) {
			auto u = q1.top();
			ans += u.first;
			if(a[u.second][1] > a[u.second][2]) q2.push(t2);
			else q3.push(t3);
			q1.pop();
		}
		else if((int)q2.size() > n / 2) {
			auto u = q2.top();
			ans += u.first;
			if(a[u.second][0] > a[u.second][2]) q1.push(t1);
			else q3.push(t3);
			q2.pop();
		}
		else if((int)q3.size() > n / 2){
			auto u = q3.top();
			ans += u.first;
			if(a[u.second][0] > a[u.second][1]) q1.push(t1);
			else q2.push(t2);
			q3.pop();
		}
	}
	printf("%lld\n",ans);
}

int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T = 1;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}