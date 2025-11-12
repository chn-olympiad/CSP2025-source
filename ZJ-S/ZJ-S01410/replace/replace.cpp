#include <bits/stdc++.h> 
using namespace std;

const int maxn = 2e5 + 5;
typedef long long ll;

int n, q;

string L[maxn], R[maxn], mode0[maxn], mode1[maxn];

void check(string &s, string &t) {
	int ans = 0;
	int i = 0, j = s.size() - 1;
	while (i < s.size() && s[i] == t[i]) i++;
	while (j > 0 && s[j] == t[j]) j--;
	string l = s.substr(0, i);
//	string r = "";
	string r = (j == s.size() - 1 ? "" : s.substr(j + 1, s.size()));
	string m0 = s.substr(i, j - i + 1);
	string m1 = t.substr(i, j - i + 1);
	for (int i = 1; i <= n; i++) {
		if (mode0[i] != m0 || mode1[i] != m1) continue ;
		int u = L[i].size(), v = R[i].size();
		if (l.size() < u|| r.size() < v) continue ;
		string lstr = l.substr(l.size() - u, u), rstr = r.substr(0, v);
		if (lstr != L[i] || rstr != R[i]) continue ;
		ans++;
	}
	cout << ans << endl;
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int x = 1; x <= n; x++) {
		string s, t;
		cin >> s >> t;
		int i = 0, j = s.size() - 1;
		while (i < s.size() && s[i] == t[i]) i++;
		while (j > 0 && s[j] == t[j]) j--;
		L[x] = s.substr(0, i);
		R[x] = s.substr(j + 1, s.size() - j);
		mode0[x] = s.substr(i, j - i + 1);
		mode1[x] = t.substr(i, j - i + 1);
//		cout << L[x] << " " << R[x]  << " " << mode0[x] << ' ' << mode1[x] << endl;
	}
	
	while (q--) {
		string s, t;
		cin >> s >> t;
		check(s, t);
	}
}

