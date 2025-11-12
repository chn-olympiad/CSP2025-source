#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 , maxm = 5e6;

int n , q , l[maxn + 5];
string s[maxn + 5] , t[maxn + 5];
bool preb[maxm + 5] , sufb[maxm + 5];

int main() {
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	scanf ("%d%d" , &n , &q);
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> t[i];
		l[i] = s[i].size();
	}
	while (q--) {
		string x , y;
		cin >> x >> y;
		int len = x.size();
		x = ' ' + x;
		y = ' ' + y;
		int cnt = 0;
		preb[0] = sufb[len + 1] = true;
		for (int i = 1; i <= len; i++)
			preb[i] = preb[i - 1] & (x[i] == y[i]);
		for (int i = len; i >= 1; i--)
			sufb[i] = sufb[i + 1] & (x[i] == y[i]);
		for (int i = 1; i <= n; i++) {
			bool ok = false;
			for (int j = 1; j <= len - l[i] + 1; j++)
				if (x.substr(j , l[i]) == s[i] && y.substr(j , l[i]) == t[i] && preb[j - 1] && sufb[j + l[i]])
					ok = true;
			cnt += ok;
		}
		printf ("%d\n" , cnt);
	}
}
