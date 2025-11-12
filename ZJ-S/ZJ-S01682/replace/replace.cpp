#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, L = 5e6 + 5;
int n, q, BTEEC = 0;
string s1[N], s2[N];
vector <int> vec[N];
unordered_map < string, int > mp;
unordered_map < string, bool > thd, ttl;
string hd[N], tl[N];

void solve(string t1, string t2) {
	int n = t1.size();
	t1 = " " + t1, t2 = " " + t2;
	int l = 0, r;
	for (int i = 1; i <= n; ++i)
		if(t1[i] != t2[i]) {
			l = i;
			break;
		}
	for (int i = n; i >= 1; --i)
		if(t1[i] != t2[i]) {
			r = i;
			break;
		}
	string str = "";
	for (int i = l; i <= r; ++i) str += t1[i];
	for (int i = l; i <= r; ++i) str += t2[i];
	int idx = mp[str], ans = 0;
	thd.clear(), thd.clear();
	thd[""] = ttl[""] = true;
	str = "";
	for (int j = l - 1; j >= 1; --j) {
		str += t1[j];
		thd[str] = true;
	}
	str = "";
	for (int j = r + 1; j <= n; ++j) {
		str += t1[j];
		ttl[str] = true;
	}
	for (int j : vec[idx]) {
//		cout << j << ' ';
		ans += thd[hd[j]] & ttl[tl[j]];	
	}
	cout << ans << '\n';
	return;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		if(s1[i] == s2[i]) continue;
		s1[i] = " " + s1[i], s2[i] = " " + s2[i];
		int l, r, m = s1[i].size() - 1;
//		cout << m << ' ';
		for (int j = 1; j <= m; ++j) {
			if(s1[i][j] != s2[i][j]) {
				l = j;
				break;
			}
		}
		for (int j = m; j >= 1; --j) {
			if(s1[i][j] != s2[i][j]) {
				r = j;
				break;
			}
		}
//		cout << l << ' ' << r << endl;
		string str = "";
		for (int j = l; j <= r; ++j) str += s1[i][j];
		for (int j = l; j <= r; ++j) str += s2[i][j];
		if(!mp[str]) mp[str] = ++ BTEEC;
		vec[mp[str]].push_back(i);
		str = "";
		for (int j = l - 1; j >= 1; --j) str += s1[i][j];
		hd[i] = str;
		str = "";
		for (int j = r + 1; j <= m; ++j) str += s1[i][j];
		tl[i] = str;
	}
	while(q --) {
		string t1, t2;
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << 0 << '\n';
			continue;
		}
		solve(t1, t2);
	}
	return 0;
}
/*
7 2
xabcx xadex
xabc xade
abc ade
xabcxx xadexx
ab cd
bc de
aa bb
xabcx xadex
aaaa aabb
*/
