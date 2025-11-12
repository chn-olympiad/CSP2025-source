#include <bits/stdc++.h>
using namespace std;
int t,  num[10], n, w, sum1, sum2, sum3, k[10086], x[10086], y[10086], f[10086], g[10086], h[10086], o[10086], p[10086],
    q[10086];

struct node {
	int a;
	int b;
	int c;

} d[10086];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;

	for (int j = 1; j <= t; j++) {
		sum1 = 0;
		sum2 = 0;
		sum3 = 0;
		cin >> n;
		w = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> d[i].a >> d[i].b >> d[i].c;
			o[i] = d[i].a;
			p[i] = d[i].b;
			q[i] = d[i].c;
		}

		for (int i = 1; i <= n; i++) {
			k[i] = o[i] - p[i];
			x[i] = o[i] - q[i];
			y[i] = p[i] - o[i];
			f[i] = p[i] - q[i];
			g[i] = q[i] - o[i];
			h[i] = q[i] - p[i];

		}
		for (int i = 1; i <= n; i++) {

			if (o[i]  > p[i] && o[i] > q[i] && sum1 <= w) {
				num[j] += o[i];
				sum1++;
			} else if (p[i] > o[i] && p[i] > q[i] && sum2 <= w) {
				num[j] += p[i];
				sum2++;
			} else if (q[i] > o[i] && q[i] > p[i]) {
				num[j] += q[i];
				sum3++;
			} else if (o[i]  > p[i] && o[i] > q[i] && sum1 > w) {
				if (k[i] > x[i]) {
					num[j] += q[i];
					sum3++;
				} else {
					num[j] += p[i];
					sum2++;
				}
			} else if (p[i]  > o[i] && p[i] > q[i] && sum2 > w) {
				if (y[i] > f[i]) {
					num[j] += q[i];
					sum3++;
				} else {
					num[j] += o[i];
					sum1++;
				}
			} else {
				if (g[i] > h[i]) {
					num[j] += p[i];

					sum2++;

				} else {
					num[j] += o[i];
					sum1++;
				}
			}
		}

	}
	for (int i = 1; i <= t; i++) {
		cout << num[i] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}