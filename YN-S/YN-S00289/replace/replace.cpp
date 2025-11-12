#include <bits/stdc++.h>
using namespace std;
string s1[200005], s2[200005];
string sq1, sq2;
int n, q;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for (int i = 1; i <= q; i++) {
		cin >> sq1 >> sq2;
		long long ans = 0;
		for (int j = 1; j <= n; j++) {
			if (sq2.find(s2[j]) != -1 && sq1.find(s1[j]) != -1) {
				if (sq1.find(s1[j]) == sq2.find(s2[j])) {
					string st = sq1;
					st.replace(sq1.find(s1[j]), s1[j].size(), s2[j]);
					if (st == sq2)
						ans++;
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}