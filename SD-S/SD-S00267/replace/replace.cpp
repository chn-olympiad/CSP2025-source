#include <bits/stdc++.h>
using namespace std;
const unsigned long long base = 131;
const int N = 1000100;
int n, p[N];
struct str { 
	string s;
	vector<unsigned long long> h;
	void hash() {
		h.clear();
		h.push_back(0);
		for (int i = 0; i < s.size(); i++) {
			h.push_back(h.back() * base + s[i]);
		}
	}
	unsigned long long get(int i, int j) {
		return h[j] - h[i - 1] * p[j - i + 1];
	}
}t[2], s[N][2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	int q;
	cin >> q;
	p[0] = 1;
	for (int i = 1; i <= N - 10; i++) {
		p[i] = p[i - 1] * base;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i][0].s >> s[i][1].s;
		s[i][0].hash(); s[i][1].hash();
	}
	while (q--) {
		cin >> t[0].s >> t[1].s;
		t[0].hash(); t[1].hash();
		int cnt = 0;
		for (int j = 1; j <= t[0].s.size(); j++) {
			for (int k = 1; k <= n; k++) {
				if (s[k][0].s.size() <= j) {
					if (t[0].get(j - s[k][0].s.size() + 1, j) == s[k][0].get(1, s[k][0].s.size()) && 
						t[1].get(j - s[k][1].s.size() + 1, j) == s[k][1].get(1, s[k][1].s.size())) {
							if (j - s[k][1].s.size() + 1 > 1) {
							    if (t[0].get(1, j - s[k][0].s.size() + 1 - 1) != t[1].get(1, j - s[k][0].s.size() + 1 - 1)) {
							    	continue;
								}
							}
							if (j < t[0].s.size()) {
								if (t[0].get(j + 1, t[0].s.size()) != t[1].get(j + 1, t[0].s.size())) {
									continue;
								}
							} 
								cnt++; 
						}
				}
			}
		}
		cout << cnt << endl;
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

*/
