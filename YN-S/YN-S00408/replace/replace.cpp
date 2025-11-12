#include <bits/stdc++.h>
#include <cstring>
using namespace std;

struct S {
	string s1;
	string s2;
};

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	S s[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> s[i].s1 >> s[i].s2;
	}
	for (int i = 1; i <= q; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (t1.find(s[j].s1) == -1)
				continue;
			else {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}