//Luogu 743373-Vitamin_B:)
//ZJ-S01668
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ull, ull> pll;
typedef pair <string, string> pss;

//const ull base = 131, mod = 993244853;

int n, q, m, x, y, len[200005], tot;

string a[200005], b[200005], s, t;
map <pss, vector <int> > mp;
//map <pll, vector <int> > mp;
//
//ull ha (const string a) {
//
//	ull sum = 0;
//
//	for (const char& i : a)
//		sum = sum * base + i;
//
//	return sum;
//}

int main () {
//	freopen ("replace4.in", "r", stdin);
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);

	cin >> n >> q;

	for (int i = 1; i <= n; ++ i) {

		cin >> a[i] >> b[i];

		x = y = 0, m = a[i].size ();

		for (int j = 0; j < m; ++ j)
			if (a[i][j] != b[i][j]) {
				x = j;
				break ;
			}
		for (int j = m - 1; ~j; -- j)
			if (a[i][j] != b[i][j]) {
				y = j;
				break ;
			}

		mp[ {a[i].substr (x, y - x + 1), b[i].substr (x, y - x + 1)}].emplace_back (i);

	}

	while (q --) {

		cin >> s >> t, m = s.size ();

		if (s.size () != t.size ()) {
			cout << "0\n";
			continue ;
		}

		x = y = tot = 0;

		for (int i = 0; i < m; ++ i)
			if (s[i] != t[i]) {
				x = i;
				break ;
			}
		for (int i = m - 1; ~i; -- i)
			if (s[i] != t[i]) {
				y = i;
				break ;
			}

		for (const int& i : mp[ {
		s.substr (x, y - x + 1), t.substr (x, y - x + 1)
		}]) {

			const int X = s.find (a[i]), Y = t.find (b[i]);

			if (X != string::npos && X == Y)
				++ tot;

		}

		cout << tot << '\n';

	}

	return 0;
}
