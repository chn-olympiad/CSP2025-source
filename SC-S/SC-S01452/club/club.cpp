#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
int t, n, cnt[4];
struct node{
	int a, b, c;
}a[N];
bool operator<(const node& a, const node& b) {
	int mx_a = max({a.a, a.b, a.c}) - min({a.a, a.b, a.c});
	int mx_b = max({b.a, b.b, b.c}) - min({b.a, b.b, b.c});
	int max_a = max({a.a, a.b, a.c}), max_b = max({b.a, b.b, b.c});
	int min_a = min({a.a, a.b, a.c}), min_b = min({b.a, b.b, b.c});
	int mid_a = a.a + a.b + a.c - max_a - min_a, mid_b = b.a + b.b + b.c - max_b - min_b;
	if (mx_a != mx_b)	return mx_a > mx_b;
	if (max_a != max_b)	return max_a > max_b;
	if (mid_a != mid_b)	return mid_a > mid_b;
	return min_a > min_b;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		int ans = 0;
		cnt[1] = cnt[2] = cnt[3] = 0;
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) {
			if (a[i].a == max({a[i].a, a[i].b, a[i].c})) {
				if (cnt[1] < (n / 2)) {
					++cnt[1];
					ans += a[i].a;
					continue;
				}
				int mn = min(a[i].b, a[i].c);
				int mid = a[i].b + a[i].c - mn;
				if (mid == a[i].b) {
					if (cnt[2] < (n / 2)) {
						++cnt[2];
						ans += a[i].b;
						continue;
					}
					++cnt[3];
					ans += a[i].c;
				}
				else{
					if (cnt[3] < (n / 2)) {
						++cnt[3];
						ans += a[i].c;
						continue;
					}
					++cnt[2];
					ans += a[i].b;
				}
			}
			else if (a[i].b == max({a[i].a, a[i].b, a[i].c})){
				if (cnt[2] < (n / 2)) {
					++cnt[2];
					ans += a[i].b;
					continue;
				}
				int mn = min(a[i].a, a[i].c);
				int mid = a[i].a + a[i].c - mn;
				if (mid == a[i].a) {
					if (cnt[1] < (n / 2)) {
						++cnt[1];
						ans += a[i].a;
						continue;
					}
					++cnt[3];
					ans += a[i].c;
				}
				else{
					if (cnt[3] < (n / 2)) {
						++cnt[3];
						ans += a[i].c;
						continue;
					}
					++cnt[1];
					ans += a[i].a;
				}
			}
			else{
				if (cnt[3] < (n / 2)) {
					++cnt[3];
					ans += a[i].c;
					continue;
				}
				int mn = min(a[i].a, a[i].b);
				int mid = a[i].b + a[i].a - mn;
				if (mid == a[i].b) {
					if (cnt[2] < (n / 2)) {
						++cnt[2];
						ans += a[i].b;
						continue;
					}
					++cnt[1];
					ans += a[i].a;
				}
				else{
					if (cnt[1] < (n / 2)) {
						++cnt[1];
						ans += a[i].a;
						continue;
					}
					++cnt[2];
					ans += a[i].b;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}