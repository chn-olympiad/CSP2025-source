#include<bits/stdc++.h>
#define LL long long
using namespace std;
int T, n;
int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf ("%d", &T);
	while(T--) {
		scanf ("%d", &n);
		priority_queue<LL, vector<LL>, greater<LL> > q[4];
		LL ans = 0;
		for (int i = 1; i <= n; ++i) {
			LL a[4];
			scanf ("%lld %lld %lld", &a[1], &a[2], &a[3]);
			int ma1 = 0, ma2 = 0, k1 = 0, k2 = 0;
			for (int j = 1; j <= 3; ++j) {
				if(ma1 <= a[j]) k2 = k1, ma2 =ma1, ma1 = a[j], k1 = j;
				else if(ma2 <= a[j]) k2 = j, ma2 = a[j];
			}
			ans += a[k1];
			q[k1].push(ma1 - ma2);
		}
		for (int j = 1; j <= 3; ++j)
			while(q[j].size() > n / 2)
				ans -= q[j].top(), q[j].pop();
		printf("%lld\n", ans);
	}
} 
