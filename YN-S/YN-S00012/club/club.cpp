#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
int T, ans = 0;
bool vis[N];

struct node {
	int a, b, c;
	double ans;
} aa[N];

bool cmp(node ax, node ay) {
	if (ax.a > ay.a) {
		return ax.a > ay.a;
	}
	if (ax.b > ay.b) {
		return ax.b > ay.b;
	}
	if (ax.c > ay.c) {
		return ax.c > ay.c;
	}
	return ax.ans > ay.ans;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(aa, 0, sizeof(aa));
		memset(vis, 0, sizeof(vis));
		int n, a1 = 0, b1 = 0, c1 = 0;
		long long sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> aa[i].a >> aa[i].b >> aa[i].c;
			aa[i].ans = (aa[i].a + aa[i].b + aa[i].c) * 1.0 / 3;
		}
		sort(aa + 1, aa + n + 1, cmp);

		for (int i = n; i >= 1; i--) {
			if (max(aa[i].a, max(aa[i].b, aa[i].c)) == aa[i].a && a1 < n / 2) {
				a1++;
				sum += aa[i].a;
			} else 	if (max(aa[i].a, max(aa[i].b, aa[i].c)) == aa[i].b && b1 < n / 2) {
				b1++;
				sum += aa[i].b;
			} else 	if (max(aa[i].a, max(aa[i].b, aa[i].c)) == aa[i].c && c1 < n / 2) {
				c1++;
				sum += aa[i].c;
			} else if (a1 >= n / 2) {
				if (aa[i].b > aa[i].c && b1 < n / 2) {
					b1++;
					sum += aa[i].b;
				} else if (c1 < n / 2) {
					c1++;
					sum += aa[i].c;
				} else {
					b1++;
					sum += aa[i].b;
				}
			} else if (b1 >= n / 2) {
				if (aa[i].a > aa[i].c && a1 < n / 2) {
					a1++;
					sum += aa[i].a;
				} else if (c1 < n / 2) {
					c1++;
					sum += aa[i].c;
				} else {
					a1++;
					sum += aa[i].a;
				}
			} else if (c1 >= n / 2) {
				if (aa[i].b > aa[i].a && b1 < n / 2) {
					b1++;
					sum += aa[i].b;
				} else if (a1 < n / 2) {
					a1++;
					sum += aa[i].a;
				} else {
					b1++;
					sum += aa[i].b;
				}
			}
		}
		cout << sum << endl;

	}


	return 0;
}