#include <bits/stdc++.h>
using namespace std;
int n, q, cnt;
string s[200020], s1[200020], t, t1;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> s1[i];
	}
	for (int f = 1; f <= q; f++) {
		cin >> t >> t1;
		for (int i = 1; i <= n; i++) {
			int x = t.find(s[i]), y = t1.find(s1[i]);
			if (x != -1 && y != -1)
				cnt++;
		}
		cout << cnt << "\n";
		cnt = 0;
	}
	return 0;
}