#include <bits/stdc++.h>
using namespace std;

struct node {
	int a, b, c;
} m[100005];
vector<node>ma, mb, mc;

int sum;
bool cmpa(node xx, node yy) {
	int xxx, yyy;
	if (xx.b != 0) {
		xxx = xx.b;
	} else {
		xxx = xx.c;
	}
	if (yy.b != 0) {
		yyy = yy.b;
	} else {
		yyy = yy.c;
	}
	return xx.a - xxx > yy.a - yyy;
}

bool cmpb(node xx, node yy) {
	int xxx, yyy;
	if (xx. a != 0) {
		xxx = xx.a;
	} else {
		xxx = xx.c;
	}
	if (yy.a != 0) {
		yyy = yy.a;
	} else {
		yyy = yy.c;
	}
	return xx.b - xxx > yy.b - yyy;
}

bool cmpc(node xx, node yy) {
	int xxx, yyy;
	if (xx.b != 0) {
		xxx = xx.b;
	} else {
		xxx = xx.a;
	}
	if (yy.b != 0) {
		yyy = yy.b;
	} else {
		yyy = yy.a;
	}
	return xx.c - xxx > yy.c - yyy;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		sum = 0;
		ma.clear(), mb.clear(), mc.clear();
		cin >> n;
		int aa = 0, bb = 0, cc = 0;
		int o = n / 2;
		int cnta = 0, cntb = 0, cntc = 0;
		for (int i = 1; i <= n; i++) {
			cin >> m[i].a >> m[i].b >> m[i].c;
			int k = min(m[i].a, min(m[i].b, m[i].c));
			m[i].a -= k, m[i].b -= k, m[i].c -= k;
			sum += k;
			if (m[i].a >= m[i].b && m[i].a >= m[i].c) {
				ma.push_back(m[i]);
				aa++;
			} else if (m[i].b >= m[i].a && m[i].b >= m[i].c) {
				mb.push_back(m[i]);
				bb++;
			} else if (m[i].c >= m[i].a && m[i].c >= m[i].b) {
				mc.push_back(m[i]);
				cc++;
			}
		}

		sort(ma.begin(), ma.end(), cmpa);
		sort(mb.begin(), mb.end(), cmpb);
		sort(mc.begin(), mc.end(), cmpc);

		for (int i = 0; i < min(aa, o); i++) {
			sum += ma[i].a;
			ma[i].a = 0, ma[i].b = 0, ma[i].c = 0;
		}
		for (int i = 0; i < min(bb, o); i++) {
			sum += mb[i].b;
			mb[i].a = 0, mb[i].b = 0, mb[i].c = 0;
		}
		for (int i = 0; i < min(cc, o); i++) {
			sum += mc[i].c;
			mc[i].a = 0, mc[i].b = 0, mc[i].c = 0;
		}

		for (int i = 0; i < aa; i++) {
			sum += max(ma[i].b, ma[i].c);
		}
		for (int i = 0; i < bb; i++) {
			sum += max(mb[i].a, mb[i].c);
		}
		for (int i = 0; i < cc; i++) {
			sum += max(mc[i].b, mc[i].a);
		}

		cout << sum << '\n';
	}
	return 0;
}