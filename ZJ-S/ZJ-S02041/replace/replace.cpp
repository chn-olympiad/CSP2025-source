#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int N = 2e5 + 7, M = 1e3;
string s1[N], s2[N];
int n, q;
void IOS() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	return ;
}
void file() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	return ;
}
void __init() {
	file();
	IOS();
	return ;
}
void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
	}
	while (q--) {
		int ans = 0;
		string t1, t2;
		cin >> t1 >> t2;
		int len1 = t1.size();
		int len2 = t2.size();
		if (len1 != len2) {
			cout << "0\n";
			continue;
		}
		int len = len1;
		string last = t1;
		for (int i = 0; i < len; ++i) {
			for (int j = 1; j <= n; ++j) {
				int a = t1.find(s1[j]);
				int b = t2.find(s2[j]);
				if (a == b) {
					int L = s1[j].size();
					for (int k = 0; k < L; ++k) {
						t1[k + i] = s2[j][k];
					}
					if (t1 == t2) {
						++ans;
					} else t1 = last;
				}
			}
		}
		cout << ans << '\n';
	}
	return ;
}
int main(void) {
	__init();
	LL _ = 1;
//	cin >> _;
	while (_--) {
		solve();
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
b a
a c

*/