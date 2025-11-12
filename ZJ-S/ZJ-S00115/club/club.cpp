#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define L(i, l, r, a) for(int i = l; i <= r; i += a)
#define R(i, l, r, a) for(int i = r; i >= l; i -= a)
#define N 100010
using namespace std;
int T, n, ans, bo[4];
struct NODE {
	int a, b, c;
}a[N];
int calc(NODE n1) {
	return max({n1.a, n1.b, n1.c}) - (n1.a + n1.b + n1.c - min({n1.a, n1.b, n1.c}) - max({n1.a, n1.b, n1.c}));
}
bool cmp(NODE n1, NODE n2) {
	int res1 = calc(n1);
	int res2 = calc(n2);
	return res1 < res2;
}
void solve() {
	cin >> n;
	ans = 0;
	bo[1] = bo[2] = bo[3] = 0;
	L(i, 1, n, 1) {
		cin >> a[i].a >> a[i].b >> a[i].c;
		if(max({a[i].a, a[i].b, a[i].c}) == a[i].a) {
			ans += a[i].a;
			bo[1]++;
		}
		else if(max({a[i].a, a[i].b, a[i].c}) == a[i].b) {
			ans += a[i].b;
			bo[2]++;
		}
		else if(max({a[i].a, a[i].b, a[i].c}) == a[i].c) {
			ans += a[i].c;
			bo[3]++;
		}
	}
	sort(a + 1, a + n + 1, cmp);
	int id = 0;
	if(bo[1] * 2 > n) id = 1;
	if(bo[2] * 2 > n) id = 2;
	if(bo[3] * 2 > n) id = 3;
	L(i, 1, n, 1) {
		if(bo[id] * 2 <= n) break;
		if(max({a[i].a, a[i].b, a[i].c}) == a[i].a) {
			if(id == 1) {
				ans -= calc(a[i]);
				bo[1]--;
			}
		}
		else if(max({a[i].a, a[i].b, a[i].c}) == a[i].b) {
			if(id == 2) {
				ans -= calc(a[i]);
				bo[2]--;
			}
		}
		else if(max({a[i].a, a[i].b, a[i].c}) == a[i].c) {
			if(id == 3) {
				ans -= calc(a[i]);
				bo[3]--;
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}