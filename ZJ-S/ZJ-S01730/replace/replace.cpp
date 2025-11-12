#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(nullptr); \
cout.tie(nullptr);
ll n, q;
string s[200005][3];
string tj1, tj2;
void fr() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
}
bool check(string s, string t, ll id) {
	if (id + s.size() - 1 > t.size()) {
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != t[i + id]) {
			return 0;
		}
	}
	return 1;
}
void change(string x, string &y, ll id) {
	for (int i = 0; i < x.size(); i++) {
		y[id + i] = x[i];
	}
}
string jiequ(string s, ll x, ll y) {
	string h = "";
	for (int i = x; i <= x + y - 1; i++) {
		h += s[i];
	}
	return h;
}
ll ans = 0;
void dfs(string x) {
	for (int i = 0; i < x.size(); i++) {
		for (int j = 1; j <= n; j++) {
			if (check(s[j][1], x, i)) {
				string p = jiequ(x, i, s[j][2].size());
				change(s[j][2], x, i);
				if (x == tj2) {
					ans++;
				}
				change(p, x, i);
			}
		}
	}
}
int main() {
	fr();
	IOS
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	while(q--) {
		cin >> tj1 >> tj2;
		ans = 0;
		dfs(tj1);
		cout << ans << "\n";
	}
	return 0;
}

