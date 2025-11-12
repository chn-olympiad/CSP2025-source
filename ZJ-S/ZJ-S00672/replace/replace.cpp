#include <bits/stdc++.h>
#define ll long long
#define Fcin; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e3 + 10;
string s1[N], s2[N];
string mp1[1005][1005], mp2[1005][1005];
int main () {
	Fcin;
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> s1[i] >> s2[i];
	while (m--) {
		int cnt = 0;
		string s, t; cin >> s >> t;
		for (int i = 1; i <= n; i++) {
			if (s1[i] == s && s2[i] == t) {
				cnt++;
				break;
			}
		}
		int l = s.size ();
		for (int i = 0; i < l; i++) {
			mp1[i][i] = s[i];
			for (int j = i + 1; j < l; j++) {
				mp1[i][j] = mp1[i][i] + s[j];
			}
		}
		for (int i = 0; i < l; i++) {
			mp2[i][i] = t[i];
			for (int j = i + 1; j < l; j++) {
				mp2[i][j] = mp2[i][i] + t[j];
			}
		}
		for (int i = 0; i < l; i++) {
		  if (mp1[0][i] == mp2[0][i]) {
		  	for (int j = 1; j <= n; j++) {
		  		if (mp1[0][i] + s2[j] == t && mp1[i + 1][l - 1] == s1[j]) cnt++;
			  }
		  }	
		  else break;		
		}
		for (int i = 0; i < l; i++) {
			if (mp1[i][l - 1] == mp2[i][l - 1]) {
				for (int j = 1; j <= n; j++) {
					if (s2[j] + mp1[i][l - 1] == t && mp1[0][i - 1] == s1[j]) cnt++;
				}
			}
			else break;
		}
		for (int i = 0; i < l; i++) {
			if (mp1[0][i] == mp2[0][i]) {
				for (int j = l - 1; j > i; j--) {
					if (mp1[j][l - 1] == mp2[j][l - 1]) {
						for (int k = 1; k <= n; k++) {
							if (mp1[0][i] + s2[k] + mp1[j][l - 1] == t && mp1[i + 1][j - 1] == s1[k]) cnt++;
						}
					}
					else break;
				}
			}
			else break;
		}
		cout << cnt << "\n";
	}
	return 0;
}

