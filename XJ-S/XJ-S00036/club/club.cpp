#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long int d, n, i, j, r[100], ans;
struct node {
	long long int x[10], y[10], mx;
}k[N], x[100];
bool cmp(node a, node b) {
	return a.mx > b.mx;
}
bool cmp1(node a, node b) {
	return a.x[1] > b.x[1];
}
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> d;
	while(d --) {
		memset(r, 0, sizeof(r));
		memset(k, 0, sizeof(k));
		ans = 0;
		cin >> n;
		for (i = 1; i <= n; i ++) {
			cin >> x[1].x[1] >> x[2].x[1] >> x[3].x[1];
			x[1].y[1] = 1, x[2].y[1] = 2, x[3].y[1] = 3;
			sort(x + 1, x + 4, cmp1);
			k[i].x[1] = x[1].x[1];
			k[i].x[2] = x[2].x[1];
			k[i].x[3] = x[3].x[1];
			k[i].y[1] = x[1].y[1];
			k[i].y[2] = x[2].y[1];
			k[i].y[3] = x[3].y[1];
			k[i].mx = k[i].x[1];
		}
		sort(k + 1, k + 1 + n, cmp);
		if (n == 2) {
			for (i = 1; i <= 2; i ++) {
				for (j = i + 1; j <= 3; j ++) {
					ans = max(ans, k[1].x[i] + k[2].x[j]);
				}
			}
			for (i = 3; i >= 2; i --) {
				for (j = i - 1; j >= 1; j --) {
					ans = max(ans, k[1].x[i] + k[2].x[j]);
				}
			}
			cout << ans << endl;
		}
		else {
			for (i = 1; i <= n; i ++) {
				for (j = 1; j <= 3; j ++) {
					if (r[k[i].y[j]] + 1 <= (n / 2)) {
						ans += k[i].x[j];
						r[k[i].y[j]] ++;
						break;
					}
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

18
4
13
*/
