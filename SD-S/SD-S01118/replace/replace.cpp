#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

const int N = 2e5 + 10, M = 5e6 + 10;
const ULL B1 = 131, B2 = 1331;
string s[2][N];
int n, q;
ULL p1[M], p2[M];
struct Node {
	ULL s1, s2;
	Node operator* (Node b) {
		return {s1 * b.s1, s2 * b.s2};
	}
	Node operator+ (Node b) {
		return {s1 + b.s1, s2 + b.s2};
	}
	Node operator- (Node b) {
		return {s1 - b.s1, s2 - b.s2};
	}
	bool operator== (Node b) {
		return s1 == b.s1 && s2 == b.s2;
	}
	bool operator< (const Node &b) const {
		if (s2 == b.s2) return s1 < b.s1;
		return s2 < b.s2;
	} 
}B;
map<Node, int> from[2], to[2];

void work1(string s, string t, int id) {
	int l = 1, r = s.size() - 1;
	while (s[l] == t[l] && l < s.size()) l++;
	while (s[r] == t[r] && 0 < r) r--;
	Node s1 = {0, 0}, s2 = {0, 0};
	for (int i = 1; i <= r; i++) {
		Node ss = {s[i], s[i]};
		s1 = s1 * B + ss;
	}
	for (int i = l; i < s.size(); i++) {
		Node ss = {s[i], s[i]};
		s2 = s2 * B + ss;
	}
//	if (id == 1) cout << l << " " << r << "\n";
//	if (id == 1) cout << s1.s1 << " " << s1.s2 << "\n";
	to[0][s2] = from[0][s1] = id;
	s1 = {0, 0}, s2 = {0, 0};
	
	for (int i = 1; i <= r; i++) {
		Node tt = {t[i], t[i]};
		s1 = s1 * B + tt;
	}
	for (int i = l; i < t.size(); i++) {
		Node tt = {t[i], t[i]};
		s2 = s2 * B + tt;
	}
//	if (id == 1) cout << l << " " << r << "\n";
//	if (id == 1) cout << s1.s1 << " " << s1.s2 << "\n";
	to[1][s2] = from[1][s1] = id;
}

Node get_h(int l, int r, Node h[]) {
	Node p = {p1[r - l + 1], p2[r - l + 1]};
	return h[r] - h[l - 1] * p;
}

Node h[M];
unordered_map<int, int> work2(int l, int r, string t) {
	h[0] = {0, 0};
	for (int i = 1; i < t.size(); i++) {
		Node tt = {t[i], t[i]};
		h[i] = h[i - 1] * B + tt;
	}
//	cout << get_h(1, 4, h).s1 << " " << get_h(1, 4, h).s2 << " \n";
	unordered_map<int, int> mp;
	for (int i = 1; i <= l; i++) {
		if (from[0].count(get_h(i, r, h))) { 
			mp[from[0][get_h(i, r, h)]]++;
		}
	}
	for (int j = r; j < t.size(); j++) {
		if (to[0].count(get_h(l, j, h))) {
			mp[to[0][get_h(l, j, h)]]++;	
		}
	}
	return mp;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	B = {B1, B2};
	scanf("%d%d", &n, &q);
	p1[0] = p2[0] = 1;
	for (int i = 1; i < M; i++) {
		p1[i] = p1[i - 1] * B1;
		p2[i] = p2[i - 1] * B2;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[0][i] >> s[1][i];
		s[0][i] = ' ' + s[0][i];
		s[1][i] = ' ' + s[1][i];
		work1(s[0][i], s[1][i], i);
	}
	while (q--) {
		string t[2];
		cin >> t[0] >> t[1];
		t[0] = ' ' + t[0];
		t[1] = ' ' + t[1];
		if (t[0].size() != t[1].size()) {
			puts("0");
			continue;
		}
		int l = 1, r = t[0].size() - 1;
		while (l < t[0].size() && t[0][l] == t[1][l]) l++; 
		while (0 < r && t[0][r] == t[1][r]) r--;
		unordered_map<int, int> mp = work2(l, r, t[0]);
		h[0] = {0, 0};
		for (int i = 1; i < t[1].size(); i++) {
			Node tt = {t[1][i], t[1][i]};
			h[i] = h[i - 1] * B + tt;
		}
//		cout << get_h(1, 4, h).s1 << " " << get_h(1, 4, h).s2 << "\n";
//		cout << from[1][get_h(1, 4, h)] << "\n";
		for (int i = 1; i <= l; i++) {
			if (from[1].count(get_h(i, r, h))) {
				mp[from[1][get_h(i, r, h)]]++;
			}
		}
		int res = 0;
		for (int j = r; j < t[1].size(); j++) {
			if (to[1].count(get_h(l, j, h))) {
				mp[to[1][get_h(l, j, h)]]++;
				if (mp[to[1][get_h(l, j, h)]] == 4)
					res++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}


