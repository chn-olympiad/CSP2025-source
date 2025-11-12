// T1 club
// ?
#include <bits/stdc++.h>
using namespace std;
struct node {
	int s, id;
} b[10];
bool cmp(node p, node q) {
	return p.s > q.s;
}
int T, n, a[100010][4], l[10], ans, c[100010], d[100010], e[100010][4], p[10];
int Q[1110];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> n;
		memset(a, 0, sizeof a);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++) 
				cin >> a[i][j];
		memset(l, 0, sizeof l);
		memset(e, 0, sizeof e);
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++)
				b[j].s = b[j].id = 0;
			for (int j = 1; j <= 3; j++) 
				b[j].s = a[i][j], b[j].id = j;
			sort(b + 1, b + 1 + 3, cmp);
			int t = b[1].id;
			if (b[1].s > b[2].s) {
				e[t][++l[t]] = b[1].s - b[2].s;
			}
			else if (b[2].s > b[3].s) {
				l[b[1].id]++;
				l[b[2].id]++;
			}
			else {
				l[b[1].id]++;
				l[b[2].id]++;
				l[b[3].id]++; 
			}
			ans += b[1].s;
		}
		for (int i = 1; i <= 3; i++)
			sort(e[i] + 1, e[i] + 1 + l[i]);
		p[1] = p[2] = p[3] = 2043504350;
		if (l[1] >= l[2] && l[1] >= l[3]) {
			p[1] = 0;
			for (int i = 1; i <= l[1] - n / 2; i++) p[1] += e[1][i];
		}
		if (l[2] >= l[1] && l[2] >= l[3]) {
			p[2] = 0;
			for (int i = 1; i <= l[2] - n / 2; i++) p[2] += e[2][i];
		}
		if (l[3] >= l[1] && l[3] >= l[2]) {
			p[3] = 0;
			for (int i = 1; i <= l[3] - n / 2; i++) p[3] += e[3][i];
		}
		if (p[1] == p[2] && p[2] == p[3] && p[3] == 2043504350) cout << ans << '\n';
		else cout << ans - min(p[1], min(p[2], p[3])) << '\n';
	}
	return 0;
}