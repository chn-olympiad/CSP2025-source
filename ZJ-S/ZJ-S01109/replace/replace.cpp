#include <bits/stdc++.h>
using namespace std;
int n, q, L1, L2;
string s[200010][3], Q[200010][3];
namespace Sub1 {
	const int maxn = 2010;
	const int md[3] = {998244353, 1000000007}, base = 20090723;
	struct node {
		int v[2];
		friend node operator + (node x, node y) {
			node z;
			for(int i = 0; i <= 1; i++) z.v[i] = (x.v[i] + y.v[i]) % md[i];
			return z;
		}
		friend node operator - (node x, node y) {
			node z;
			for(int i = 0; i <= 1; i++) z.v[i] = (x.v[i] - y.v[i] + md[i]) % md[i];
			return z;
		}
		friend node operator * (node x, node y) {
			node z;
			for(int i = 0; i <= 1; i++) z.v[i] = 1ll * x.v[i] * y.v[i] % md[i];
			return z;
		}
		bool operator == (node &y) const {
			for(int i = 0; i <= 1; i++) {
				if(v[i] != y.v[i]) return false;
			}
			return true;
		}
	}hsh[5][maxn][maxn], pw[maxn];
	node find(int op, int id, int l, int r) {
		return hsh[op][id][r] - (hsh[op][id][l - 1] * pw[r - l + 1]);
	}
	void solve() {
		pw[0] = {1, 1};
		for(int i = 1; i <= max(L1, L2); i++) pw[i] = pw[i - 1] * (node){base, base};
		for(int i = 1; i <= n; i++) {
			hsh[1][i][0] = (node){0, 0};
			for(int j = 0; j < s[i][1].size(); j++) {
				char c = s[i][1][j];
				hsh[1][i][j + 1] = hsh[1][i][j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')}; 
			}
			hsh[2][i][0] = (node){0, 0};
			for(int j = 0; j < s[i][2].size(); j++) {
				char c = s[i][2][j];
				hsh[2][i][j + 1] = hsh[2][i][j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')}; 
			}
		}
		for(int i = 1; i <= q; i++) {
			string t1 = Q[i][1], t2 = Q[i][2];
			int l1 = t1.size(), l2 = t2.size();
			if(l1 != l2) {
				cout << "0\n";
				continue;
			}
			hsh[3][i][0] = (node){0, 0};
			for(int j = 0; j < t1.size(); j++) {
				char c = t1[j];
				hsh[3][i][j + 1] = hsh[3][i][j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')}; 
			}
			hsh[4][i][0] = (node){0, 0};
			for(int j = 0; j < t2.size(); j++) {
				char c = t2[j];
				hsh[4][i][j + 1] = hsh[4][i][j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')}; 
			}
			int ans = 0, l = 1, r = l1;
			for(int j = l1 - 1; ~j; j--) {
				if(t1[j] != t2[j]) {
					r = j + 1;
					break;
				}
			}
			for(int j = 0; j < l1; j++) {
				if(t1[j] != t2[j]) {
					l = j + 1;
					break;
				}
			}
			for(int j = 1; j <= n; j++) {
				if(s[j][1].size() > l1 || s[j][1].size() < r - l + 1) continue;
				node tmp = find(1, j, 1, s[j][1].size()), tmp2 = find(2, j, 1, s[j][2].size());
				for(int k = r - s[j][1].size() + 1; k <= l && k <= l1 - s[j][1].size() + 1; k++) {
					if(find(3, i, k, k + s[j][1].size() - 1) == tmp && find(4, i, k, k + s[j][2].size() - 1) == tmp2) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
		}
	}
}
namespace SubA {
	const int maxn = 2e5 + 10, maxm = 5e6 + 10;
	const int md[3] = {998244353, 1000000007}, base = 20090723;
	struct node {
		int v[2];
		friend node operator + (node x, node y) {
			node z;
			for(int i = 0; i <= 1; i++) z.v[i] = (x.v[i] + y.v[i]) % md[i];
			return z;
		}
		friend node operator - (node x, node y) {
			node z;
			for(int i = 0; i <= 1; i++) z.v[i] = (x.v[i] - y.v[i] + md[i]) % md[i];
			return z;
		}
		friend node operator * (node x, node y) {
			node z;
			for(int i = 0; i <= 1; i++) z.v[i] = 1ll * x.v[i] * y.v[i] % md[i];
			return z;
		}
		bool operator == (node &y) const {
			for(int i = 0; i <= 1; i++) {
				if(v[i] != y.v[i]) return false;
			}
			return true;
		}
	}pw[maxm];
	vector <node> hsh[3][maxn], hsh3, hsh4;
	node find(int op, int id, int l, int r) {
		return hsh[op][id][r] - (hsh[op][id][l - 1] * pw[r - l + 1]);
	}
	node find3(int l, int r) {
		return hsh3[r] - (hsh3[l - 1] * pw[r - l + 1]);
	}
	node find4(int l, int r) {
		return hsh4[r] - (hsh4[l - 1] * pw[r - l + 1]);
	}
	void solve() {
		pw[0] = {1, 1};
		for(int i = 1; i <= max(L1, L2); i++) pw[i] = pw[i - 1] * (node){base, base};
		for(int i = 1; i <= n; i++) {
			int j = 0;
			hsh[1][i].push_back((node){0, 0});
			for(char c : s[i][1]) {
				hsh[1][i].push_back(hsh[1][i][j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')});
				j++;
			}
			j = 0;
			hsh[2][i].push_back((node){0, 0});
			for(char c : s[i][2]) {
				hsh[2][i].push_back(hsh[2][i][j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')});
				j++;
			}
		}
		for(int i = 1; i <= q; i++) {
			string t1 = Q[i][1], t2 = Q[i][2];
			int l1 = t1.size(), l2 = t2.size();
			if(l1 != l2) {
				cout << "0\n";
				continue;
			}
			hsh3.clear(), hsh4.clear();
			hsh3.push_back((node){0, 0});
			for(int j = 0; j < t1.size(); j++) {
				char c = t1[j];
				hsh3.push_back(hsh3[j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')});
			}
			hsh4.push_back((node){0, 0});
			for(int j = 0; j < t1.size(); j++) {
				char c = t2[j];
				hsh4.push_back(hsh4[j] * (node){base, base} + (node){(int)(c - 'a'),(int)(c - 'a')});
			}
			int ans = 0, l = 1, r = l1;
			for(int j = l1 - 1; ~j; j--) {
				if(t1[j] != t2[j]) {
					r = j + 1;
					break;
				}
			}
			for(int j = 0; j < l1; j++) {
				if(t1[j] != t2[j]) {
					l = j + 1;
					break;
				}
			}
			for(int j = 1; j <= n; j++) {
				if(s[j][1].size() > l1 || s[j][1].size() < r - l + 1) continue;
				node tmp = find(1, j, 1, s[j][1].size()), tmp2 = find(2, j, 1, s[j][2].size());
				for(int k = r - s[j][1].size() + 1; k <= l && k <= l1 - s[j][1].size() + 1; k++) {
					if(find3(k, k + s[j][1].size() - 1) == tmp && find4(k, k + s[j][2].size() - 1) == tmp2) {
						ans++;
					}
				}
			}
			cout << ans << "\n";
		}
	}
}
namespace SubB {
	const int maxn = 5e6 + 10;
	map <int, int> mp;
	struct query {
		string t1, t2;
		int id, len;
	}qq[maxn];
	int ans[maxn];
	struct node {
		string s1, s2;
		int len;
	}ss[maxn];
	void solve() {
		for(int i = 1; i <= q; i++) {
			qq[i].t1 = Q[i][1], qq[i].t2 = Q[i][2], qq[i].id = i, qq[i].len = Q[i][1].size();
		}
		for(int i = 1; i <= n; i++) ss[i].s1 = s[i][1], ss[i].s2 = s[i][2], ss[i].len = s[i][1].size();
		sort(ss + 1, ss + 1 + n, [&](node x, node y) {
			return x.len < y.len;
		});
		sort(qq + 1, qq + 1 + q, [&](query x, query y) {
			return x.len < y.len;
		});
		int j = 1;
		for(int i = 1; i <= q; i++) {
			while(j <= n && ss[j].len <= qq[i].len) {
				int p1 = 0, p2 = 0;
				for(int k = 0; k < ss[j].len; k++) {
					if(ss[j].s1[k] == 'b') p1 = k;
					if(ss[j].s2[k] == 'b') p2 = k;
				}
				mp[p1 - p2]++;
				j++;
			}
			int p1 = 0, p2 = 0;
			for(int k = 0; k < qq[i].len; k++) {
				if(qq[i].t1[k] == 'b') p1 = k;
				if(qq[i].t2[k] == 'b') p2 = k;
			}
			if(mp.count(p1 - p2)) ans[qq[i].id] = mp[p1 - p2];
			else ans[qq[i].id] = 0;
		}
		for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
	}
}
int main() {
//	system("fc code.out replace4.ans");
//	freopen("data.in", "r", stdin);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
		L1 += s[i][1].size(), L1 += s[i][2].size();
	}
	for(int i = 1; i <= q; i++) {
		cin >> Q[i][1] >> Q[i][2];
		L2 += Q[i][1].size(), L2 += Q[i][2].size();
	}
	if(n <= 1000 && q <= 1000 && L1 <= 2000 && L2 <= 2000) {
		Sub1::solve();
		return 0;
	}
	if(q == 1) {
		SubA::solve();
		return 0;
	}
	SubB::solve();
	return 0;
}
