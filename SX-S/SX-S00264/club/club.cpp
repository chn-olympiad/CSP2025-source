#include <bits/stdc++.h>
using namespace std;

struct node {
	int id;
	int x;
} c1[100005], c2[100005], c3[100005];
int t, n, cnt, sum;
int a[100005][4];
bool vis[4];

bool cmp(node x, node y) {
	return x.x > y.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				if (j == 1)	{
					c1[++cnt].x = a[i][j];
//					c1[cnt].id = i;
				}
//				else if (j == 2)	{
//					c2[cnt].x = a[i][j];
//					c2[cnt].id = i;
//				} else if (j == 3)	{
//					c3[cnt].x = a[i][j];
//					c3[cnt].id = i;
//				}
			}
		}
		if (n == 2) {
			cout << max(a[1][1] + a[2][2], max(a[1][1] + a[2][3], max(a[1][2] + a[2][1], max(a[1][2] + a[2][3],
			                                   max(a[1][3] + a[2][1], a[1][3] + a[2][2]))))) << endl;
			continue;
		}
		sort(c1 + 1, c1 + 1 + cnt, cmp);
//		sort(c2 + 1, c2 + 1 + cnt, cmp);
//		sort(c3 + 1, c3 + 1 + cnt, cmp);
//		for (int i = 1; i <= cnt; i++) {
//			cout <<1<<' '<<i<<' '<< c1[i].id << ' ' << c1[i].x << endl;
//			cout <<1<<' '<<i<<' '<< c2[i].id << ' ' << c2[i].x << endl;
//			cout <<1<<' '<<i<<' '<< c3[i].id << ' ' << c3[i].x << endl;
//		}
		for (int i = 1; i <= n / 2; i++) {
			sum += c1[i].x;
		}
		cout << sum << endl;
		sum = 0;
		cnt = 0;
	}
	return 0;
}

