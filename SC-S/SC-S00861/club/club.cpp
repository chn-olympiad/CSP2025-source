#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+10;
int t;
int n;
int d[N][3], d1[N];
int mx[N], a = 0, b = 0, c = 0, x = 0, y = 0, z = 0, ret = 0;
int m[3][N];
int sum = 0;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int q = n / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &d[i][1], &d[i][2], &d[i][3]); //i表示第几人;1,2,3表示去哪个社团
			m[1][i] = d[i][1];
			m[2][i] = d[i][2];
			m[3][i] = d[i][3];
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			mx[i] = max(d[i][1], max(d[i][2], d[i][3]));
			cnt += mx[i];
			if (mx[i] == d[i][1]) a++;
			if (mx[i] == d[i][2]) b++;
			if (mx[i] == d[i][3]) c++;
		}
		if (a <= q && b <= q && c <= q) {
			printf("%d\n", cnt);
			continue;
		}
		if (n == 2) {
			sum = max(d[1][1] + d[2][2], max(d[1][1] + d[2][3], max(d[1][2] + d[2][1], d[1][2] + d[2][3])));
			sum = max(sum, max(d[1][3] + d[2][1], d[1][3] + d[2][2]));
			printf("%d\n", sum);

		}
		if (n == 4) {
			sum = max(d[1][1] + d[2][1] + d[3][2] + d[4][2], max(d[1][1] + d[2][1] + d[3][2] + d[4][3], max(d[1][1] + d[2][1] + d[3][3] + d[4][2], d[1][1] + d[2][1] + d[3][3] + d[4][3])));
			sum = max(sum, max(d[1][1] + d[2][2] + d[3][1] + d[4][2], max(d[1][1] + d[2][2] + d[3][1] + d[4][3], max(d[1][1] + d[2][3] + d[3][1] + d[4][2], d[1][1] + d[2][3] + d[3][1] + d[4][3]))));
			sum = max(sum, max(d[1][2] + d[2][1] + d[3][1] + d[4][2], max(d[1][2] + d[2][1] + d[3][1] + d[4][3], max(d[1][3] + d[2][1] + d[3][1] + d[4][2], d[1][3] + d[2][1] + d[3][1] + d[4][3]))));
			printf("%d\n", sum);
		}
		if (b > q) {
			for (int i = 1; i <= n; i++) {
				d1[i] = d[i][2];
			}
			sort(d1 + 1, d1 + n + 1);
			for (int i = n; i >= q + 1; i--) {
				sum += d1[i];
			}
			int f = d1[q + 1];
			for (int i = 1; i <= n; i++) {
				if (d[i][2] < f) {
					sum += max(d[i][1], d[i][3]);
				}
			}
		} else if (a > q) {
			for (int i = 1; i <= n; i++) {
				d1[i] = d[i][1];
			}
			sort(d1 + 1, d1 + n + 1);
			for (int i = n; i >= q + 1; i--) {
				sum += d1[i];
			}
			int f = d1[q + 1];
			for (int i = 1; i <= n; i++) {
				if (d[i][1] < f) {
					sum += max(d[i][3], d[i][2]);
				}
			}
		} else if (c > q) {
			for (int i = 1; i <= n; i++) {
				d1[i] = d[i][3];
			}
			sort(d1 + 1, d1 + n + 1);
			for (int i = n; i >= q - 1; i--) {
				sum += d1[i];
			}
			int f = d1[q + 1];
			for (int i = 1; i <= n; i++) {
				if (d[i][3] < f) {
					sum += max(d[i][1], d[i][2]);
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
}