#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int n, dp[5][N];

struct node {
	int a, b, c;
} s[N];

bool cmp(node x, node y) {
	if (x.a == y.a) {
		if (x.b == y.b )
			return x.c > y.c ;
		else
			return x.b > y.b ;
	}
	return x.a > y.a;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		int m = n / 2, ans = 0;
		for (int i = 1; i <= n; i++)
			cin >> s[i].a >> s[i].b >> s[i].c ;
		sort(s + 1, s + n + 1, cmp);
		for (int i = 1; i <= m; i++)
			ans += s[i].a ;
		for (int i = 1; i <= m; i++)
			ans += s[i].b ;
		cout << ans << endl;
	}
	return 0;
}