#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N = 1e5 + 10;
int t;

struct {
	int a;
	int b;
	int c;
} q[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t) {
		int n;
		cin >> n;
		int min1[50010], min2[50010], min3[50010], xb1[50010], xb2[50010], xb3[50010];
		int cnta = 0, cntb = 0, cntc = 0;
		int la = 0, lb = 0, lc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> q[i].a >> q[i].b >> q[i].c;
			if (q[i].a > q[i].b && q[i].a > q[i].c ) {
				cnta += q[i].a;
				la++;
				int x = la;
				while (1) {
					if (q[i].a >= min1[x]) {
						break;
					}
					x--;
				}
				for (int j = la; j >= x; j--) {
					min1[j + 1] = min1[j];
					xb1[j + 1] = xb1[j];
				}
				min1[x] = q[i].a;
				xb1[x] = i;
			} else if (q[i].b > q[i].a && q[i].b > q[i].c ) {
				cntb += q[i].b;
				lb++;
				int x = lb;
				while (1) {
					if (q[i].b >= min2[x]) {
						break;
					}
					x--;
				}
				for (int j = lb; j >= x; j--) {
					min2[j + 1] = min2[j];
					xb2[j + 1] = xb2[j];
				}
				min2[x] = q[i].b;
				xb2[x] = i;
			} else if (q[i].c > q[i].a && q[i].c > q[i].b) {
				cntc += q[i].c;
				lc++;
				int x = lc;
				while (1) {
					if (q[i].c >= min3[x]) {
						break;
					}
					x--;
				}
				for (int j = lc; j >= x; j--) {
					min3[j + 1] = min3[j];
					xb3[j + 1] = xb3[j];
				}
				min3[x] = q[i].c;
				xb3[x] = i;
			}
		}
		if (la > n / 2) {
			for (int i = la; i > n / 2; i--) {
				la--;
				cnta -= min1[i];
				if (q[xb1[i]].b >= q[xb1[i]].c && lb + 1 <= n / 2) {
					cntb += q[xb1[i]].b;
					lb++;
				} else {
					cntc += q[xb1[i]].c;
					lc++;
				}
			}
		} else if (lb > n / 2) {
			for (int i = lb; i > n / 2; i--) {
				lb--;
				cntb -= min2[i];
				if (q[xb2[i]].a >= q[xb2[i]].c && la + 1 <= n / 2) {
					cnta += q[xb2[i]].a;
					la++;
				} else {
					cntc += q[xb2[i]].c;
					lc++;
				}
			}
		} else if (lc > n / 2) {
			for (int i = lc; i > n / 2; i--) {
				lc--;
				cntc -= min3[i];
				if (q[xb3[i]].b >= q[xb3[i]].a && lb + 1 <= n / 2) {
					cntb += q[xb3[i]].b;
					lb++;
				} else {
					cnta += q[xb3[i]].a;
					la++;
				}
			}
		}
		cout << cnta + cntb + cntc << endl;
		t--;
	}
	return 0;
}