#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#define L(i, l, r, a) for(int i = l; i <= r; i += a)
#define R(i, l, r, a) for(int i = r; i >= l; i -= a)
#define N 100010
#define M 5000000
#define ull unsigned long long
using namespace std;
int n, q, sz;
string s1[N], s2[N], t1, t2;
const int B = 131;
ull p[M + 10], hs1[N], hs2[N], ht1[M], ht2[M];
void init() {
	L(i, 0, sz - 1, 1) {
		ht1[i + 1] = ht1[i] * B + t1[i];
		ht2[i + 1] = ht2[i] * B + t2[i];
	}
}
ull geth1(int l, int r) {
	return ht1[r + 1] - ht1[l] * p[r - l + 1];
}
ull geth2(int l, int r) {
	return ht2[r + 1] - ht2[l] * p[r - l + 1];
}
void solve() {
	int ans = 0;
	cin >> t1 >> t2;
	if(t1.size() != t2.size()) {
		puts("0");
		return;
	}
	sz = t1.size();
	init();
	L(i, 0, sz - 1, 1) {
		if(ht1[i] != ht2[i]) break;
		L(j, 1, n, 1) {
			int len = s1[j].size();
			if(i + len - 1 > sz) continue;
			ull tmph1 = geth1(i, i + len - 1), tmph2 = geth2(i, i + len - 1);
			if(tmph1 == hs1[j] && tmph2 == hs2[j]) {
				tmph1 = geth1(i + len, sz - 1);tmph2 = geth2(i + len, sz - 1);
				if(tmph1 == tmph2) ans++;
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	p[0] = 1;
	L(i, 1, M, 1) p[i] = p[i - 1] * B;
	cin >> n >> q;
	L(i, 1, n, 1) {
		cin >> s1[i] >> s2[i];
		L(j, 0, s1[i].size() - 1, 1) hs1[i] = hs1[i] * B + s1[i][j];
		L(j, 0, s2[i].size() - 1, 1) hs2[i] = hs2[i] * B + s2[i][j];
	}
	while(q--) {
		solve();
	}
	return 0;
}