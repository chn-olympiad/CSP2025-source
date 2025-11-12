#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, q, l[200005];
string s1[200005], s2[200005], t1, t2;
ll ans;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		l[i] = s1[i].length();
	}
	while (q--) {
		cin >> t1 >> t2;
		ans = 0;
		int len = t1.length();
		string a1;
		for (int i = 0; i < len; i++) {
			for (int j = 1; j <= n; j++) {
				if (l[j] + i > len)
					continue;
				if ((t1.substr(i, l[j]) == s1[j]) and (a1 + s2[j] + t1.substr(l[j] + i) == t2))
					ans++;
			}
			a1 = a1 + t1.substr(i, 1);
		}
		cout << ans << endl;
	}
	return 0;
}