#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c;
};
node  a[100005], b[100005], c[100005];

bool cmpa(node x, node y) {
	return min(x.a - x.b, x.a - x.c) > min(y.a - y.b, y.a - y.c);
}

bool cmpb(node x, node y) {
	return min(x.b - x.a, x.b - x.c) > min(y.b - y.a, y.b - y.c);
}

bool cmpc(node x, node y) {
	return min(x.c - x.b, x.c - x.a) > min(y.c - y.b, y.c - y.a);
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++) {
		int n, cnta = 1, cntb = 1, cntc = 1, sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int aa[1], bb[1], cc[1];
			scanf("%d%d%d", aa, bb, cc);
			if (aa[0] == max(aa[0], max(bb[0], cc[0]))) {
				a[cnta].a = aa[0], a[cnta].b = bb[0], a[cnta].c = cc[0];
				cnta++;
			} else if (bb[0] == max(aa[0], max(bb[0], cc[0]))) {
				b[cntb].a = aa[0], b[cntb].b = bb[0], b[cntb].c = cc[0];
				cntb++;
			} else {
				c[cntc].a = aa[0], c[cntc].b = bb[0], c[cntc].c = cc[0];
				cntc++;
			}
		}
		sort(a + 1, a + cnta, cmpa);
		sort(b + 1, b + cntb, cmpb);
		sort(c + 1, c + cntc, cmpc);
		for (int i = 1; i <= min(n / 2, cnta - 1); i++) {
			sum += a[i].a;
		}
		for (int i = n / 2 + 1; i <= cnta - 1; i++) {
			sum += max(a[i].b, a[i].c);
		}
		for (int i = 1; i <= min(n / 2, cntb - 1); i++) {
			sum += b[i].b;
		}
		for (int i = n / 2 + 1; i <= cntb - 1; i++) {
			sum += max(b[i].a, b[i].c);
		}
		for (int i = 1; i <= min(n / 2, cntc - 1); i++) {
			sum += c[i].c;
		}
		for (int i = n / 2 + 1; i <= cntc - 1; i++) {
			sum += max(c[i].a, c[i].b);
		}
		cout << sum << endl;
	}
	return 0;
}
