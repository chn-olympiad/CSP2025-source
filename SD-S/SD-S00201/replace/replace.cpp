#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e6 + 10;
int n, q;
string s[N][2];
int nxt[N];
void getnxt(int *nxt, string s, int n) {
	int i = 0, j = nxt[0] = -1;
	while (i < n) {
		while (~j && s[i] != s[j]) j = nxt[j];
		i++ , j ++ ;
		nxt[i] = j;
	}
}
signed main()
{
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) {
		cin >> s[i][1] >> s[i][2];
	}
	while (q -- ) {
		string t1, t2; cin >> t1 >> t2;
		int ans = 0;
		for (int i = 1; i <= n; i ++ ) {
			int len1 = s[i][1].length();
			int len2 = t1.length();
//			cout << i << ":\n";
			for (int j = 0; j + len1 - 1 < len2; j ++ ) {
				if (t1.substr(j, len1) == s[i][1]) {
//					cout << t1.substr(j, len1) << "\n";
//					cout << "!" << t1.substr(0, j) + s[i][2] + t1.substr(j + len1, len2-j-len1) << endl;	
					if (t1.substr(0, j) + s[i][2] + t1.substr(j + len1, len2-j-len1) == t2) {
						ans ++ ;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

