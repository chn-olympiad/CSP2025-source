#include <iostream>
using namespace std;
const int MAXN = 2e5 + 5, MAXQ = 2e4 + 5, MAXLEN = 2e3 + 5;
string s1[MAXN], s2[MAXN], t1, t2;
int nxt[MAXN][MAXLEN];
int main(void) {
	ios_base :: sync_with_stdio(false);
	cin . tie(0);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1;i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		nxt[i][0] = -1;
		for (int j = 1, k = -1;s1[i][j]; ++j) {
			while (k != -1 && s1[i][j] != s1[i][k + 1])
				k = nxt[i][k];
			if (s1[i][j] == s1[i][k + 1])
				++k;
			nxt[i][j] = k;
		}
	}
	while (q--) {
		cin >> t1 >> t2;
		int ans = 0;
		for (int i = 1;i <= n; ++i) {
			for (int j = 0, k = -1;t1[j]; ++j) {
				while (k != -1 && t1[j] != s1[i][k + 1])
					k = nxt[i][k];
				if (t1[j] == s1[i][k + 1])
					++k;
				if (!s1[i][k + 1]) {
					string s = t1;
					for (int l = j - k;l <= j; ++l) 
						s[l] = s2[i][l - j + k];
					if (s == t2)
						++ans;
				}
			}
		}	
		cout << ans << '\n';
	}
	return 0;
} 
