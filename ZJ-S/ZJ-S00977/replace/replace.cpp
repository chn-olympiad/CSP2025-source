#include <bits/stdc++.h>
using namespace std;

string a[200005], b[200005];


int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
	}
	while (q--) {
		int ans = 0;
		string s1, s2;
		cin >> s1 >> s2;
		for (int i = 1; i <= n; i++) {
			int it;
			if ((it = s1.find(a[i])) != -1) {
				string tmp = "";
				for (int j = 0; j < s1.length(); j++) {
					if (j >= it && j < it + a[i].length())
						tmp += b[i][j - it];
					else
						tmp += s1[j];
				}
				if (tmp == s2)
					ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
