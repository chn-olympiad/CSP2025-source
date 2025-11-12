#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int t, n, ans;
priority_queue<pair<int, int> > q1, q2, q3;
struct res{
	int a1, a2, a3;
} a[N];
signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &n);
		ans = 0; 
		while (!q1.empty()) q1.pop();
		while (!q2.empty()) q2.pop();
		while (!q3.empty()) q3.pop();
		for (int i = 1; i <= n; i++) {
			scanf("%lld %lld %lld", &a[i].a1, &a[i].a2, &a[i].a3);
			pair<int, int> x = {a[i].a1, 1}, y = {a[i].a2, 2}, z = {a[i].a3, 3};
			if (y.first < z.first) swap(y, z);
			if (x.first < y.first) swap(x, y);
			if (y.first < z.first) swap(y, z);
			ans += x.first; 
			if (x.second == 1) q1.push({y.first - x.first, i});
			if (x.second == 2) q2.push({y.first - x.first, i});
			if (x.second == 3) q3.push({y.first - x.first, i});
		}
		while (q1.size() > n / 2 || q2.size() > n / 2 || q3.size() > n / 2) {
			if (q1.size() > n / 2) {
				int c = -q1.top().first, i = q1.top().second; q1.pop();
				ans -= c; 
				if (a[i].a1 >= a[i].a2 && a[i].a2 >= a[i].a3) q2.push({a[i].a3 - a[i].a2, i});
				else if (a[i].a1 >= a[i].a3 && a[i].a2 <= a[i].a3) q3.push({a[i].a2 - a[i].a3, i});
			} else if (q2.size() > n / 2) {
				int c = -q2.top().first, i = q2.top().second; q2.pop();
				ans -= c; 
				if (a[i].a2 >= a[i].a1 && a[i].a1 >= a[i].a3) q1.push({a[i].a3 - a[i].a1, i});
				else if (a[i].a2 >= a[i].a3 && a[i].a1 <= a[i].a3) q3.push({a[i].a1 - a[i].a3, i});
			} else if (q3.size() > n / 2) {
				int c = -q3.top().first, i = q3.top().second; q3.pop();
				ans -= c; 
				if (a[i].a3 >= a[i].a2 && a[i].a2 >= a[i].a1) q2.push({a[i].a1 - a[i].a2, i});
				else if (a[i].a3 >= a[i].a1 && a[i].a2 <= a[i].a1) q1.push({a[i].a2 - a[i].a1, i});
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
