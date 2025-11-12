#include <bits/stdc++.h>
using namespace std;
int n, m, temp, ans1, ans2;
struct node {
	int a, id;
} a[111];
bool cmp(node& a, node& b) {return a.a > b.a;}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) cin >> a[i].a, a[i].id = i;
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++) {
		if (a[i].id == 1) {
			temp = i;
			break;
		}
	}
	ans1 = (temp + (n - 1)) / n;
	ans2 = (temp % m == 0 ? m : temp % m);
	ans2 = (ans1 & 1 ? ans2 : m - ans2 + 1);
	cout << ans1 << ' ' << ans2;
	return 0;
}
