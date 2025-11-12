#include <bits/stdc++.h>
#define Maxn 100005

using namespace std;

int T, n, a[Maxn][5], hlf;
int st1[Maxn], top1 = 0;
int st2[Maxn], top2 = 0;
int st3[Maxn], top3 = 0;
int p[Maxn], res = 0;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> T;
	while (T --) {
		cin >> n, hlf = n / 2;
		top1 = top2 = top3 = 0;
		res = 0;
		
		for (int i = 1; i <= n; i ++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			if (a[i][1] >= a[i][2] && a[i][1] >= a[i][3]) {
				st1[++ top1] = i, res += a[i][1];
			} else if (a[i][2] >= a[i][1] && a[i][2] >= a[i][3]) {
				st2[++ top2] = i, res += a[i][2];
			} else if (a[i][3] >= a[i][2] && a[i][3] >= a[i][1]) {
				st3[++ top3] = i, res += a[i][3];
			}
		}
		
		if (top1 > hlf) {
			for (int i = 1; i <= top1; i ++) {
				p[i] = a[st1[i]][1] - max(a[st1[i]][2], a[st1[i]][3]);
			} sort(p + 1, p + top1 + 1);
			for (int i = 1; i <= top1 - hlf; i ++) {
				res -= p[i];
			}
		} else if (top2 > hlf) {
			for (int i = 1; i <= top2; i ++) {
				p[i] = a[st2[i]][2] - max(a[st2[i]][1], a[st2[i]][3]);
			} sort(p + 1, p + top2 + 1);
			for (int i = 1; i <= top2 - hlf; i ++) {
				res -= p[i];
			}
		} else if (top3 > hlf) {
			for (int i = 1; i <= top3; i ++) {
				p[i] = a[st3[i]][3] - max(a[st3[i]][1], a[st3[i]][2]);
			} sort(p + 1, p + top3 + 1);
			for (int i = 1; i <= top3 - hlf; i ++) {
				res -= p[i];
			}
		} cout << res << "\n";
	} return 0;
}
