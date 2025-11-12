#include <bits/stdc++.h>
using namespace std;
int T, n, ans;

struct node {
	int id, a1, a2, a3;
} s[100005];

inline bool cmp(node a, node b) {
	return a.a1 > b.a1;
}

int main() {

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> T;
	while (T--) {
		cin >> n;
		int cnt = n / 2;
		for (int i = 1; i <= n; i++) {
			s[i].id = i;
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
		}
		stable_sort(s + 1, s + n + 1, cmp) ;
		for (int i = 1; i <= cnt; i++) {
			ans += s[i].a1;
		}
		cout << ans << "\n";
	}


	return 0;
}
