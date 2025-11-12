#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q;
int l[MAXN];
int ans;
string s1[MAXN], s2[MAXN];
string t1, t2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s1[i] >> s2[i];
		l[i] = s1[i].length();
	}
	for (int i = 0; i < q; i++) {
		cin >> t1 >> t2;
		ans = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < t1.length() - l[j]; k++) {
				if (t1.substr(k, l[j]) == s1[j] && t2.substr(k, l[j]) == s2[j]) {
					if (t1.substr(0, k) == t2.substr(0, k) && t1.substr(k + l[j]) == t2.substr(k + l[j])) {
						ans++;
					}
				}
			}
		}
		cout << ans;
	}
	return 0;
}