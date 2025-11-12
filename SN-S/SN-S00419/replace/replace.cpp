#include <bits/stdc++.h>
#define ull unsigned long long
#define Maxn 2005
#define base 131

using namespace std;

int n, q, l1, l2, res = 0;
int l[Maxn];
ull hsh1[Maxn], hsh2[Maxn];
ull t1[Maxn], t2[Maxn];
ull qp[Maxn];
string s;

ull GetHash(int l, int r, ull hsh[]) {
	if (l > r) { return 0; }
	return hsh[r] - hsh[l - 1] * qp[r - l + 1];
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	qp[0] = 1;
	for (int i = 1; i <= 2000; i ++) {
		qp[i] = qp[i - 1] * base;
	}
	
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		cin >> s;
		for (int j = 0; j < (int)s.size(); j ++) {
			hsh1[i] = hsh1[i] * base + s[j];
		} cin >> s;
		for (int j = 0; j < (int)s.size(); j ++) {
			hsh2[i] = hsh2[i] * base + s[j];
		} l[i] = s.size();
	}
	
	for (int i = 1; i <= q; i ++) {
		cin >> s, l1 = s.size();
		for (int j = 0; j < (int)s.size(); j ++) {
			t1[j + 1] = t1[j] * base + s[j];
		} cin >> s, l2 = s.size();
		for (int j = 0; j < (int)s.size(); j ++) {
			t2[j + 1] = t2[j] * base + s[j];
		}
		
		if (l1 != l2) { cout << 0 << "\n"; continue; }
		
		res = 0;
		for (int j = 1; j <= n; j ++) {
			for (int k = 1; k + l[j] - 1 <= l1; k ++) {
				if (GetHash(1, k - 1, t1) == GetHash(1, k - 1, t2)
				 && GetHash(k, k + l[j] - 1, t1) == hsh1[j]
				 && GetHash(k, k + l[j] - 1, t2) == hsh2[j]
				 && GetHash(k + l[j], l1, t1) == GetHash(k + l[j], l1, t2)) {
					res ++;
				}
			}
		} cout << res << "\n";
	} return 0;
}
