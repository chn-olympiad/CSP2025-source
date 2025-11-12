#include <bits/stdc++.h>
using namespace std;
int n, m, t, ans = 1;
string s;

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= m; i++) {
		scanf("%d", &t);
		if (t != 0) {
			ans *= t;
		}
	}
	printf("%d", ans);
	return 0;
}