//huangyi 2025.11.1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 100;
ll n, T;
ll sum = 0;
ll cnta = 0, cntb = 0, cntc = 0;

struct node {
	ll a, b, c;
	double p;
	ll mxa, mxb, mxc;
} e[N];

bool cmp(node x, node y) {
	if (x.mxa != y.mxa) {
		return double(x.mxa - x.p) > double(y.mxa - y.p);
	} else if (x.mxb != y.mxb) {
		return double(x.mxb - x.p) > double(y.mxb - y.p);
	} else {
		return double(x.mxc - x.p) > double(y.mxc - y.p);
	}
}

void kcs007nb(node &x) {
	ll s[5] = {x.a, x.b, x.c};
	sort(s, s + 3);
	x.mxa = s[2];
	x.mxb = s[1];
	x.mxc = s[0];
}

int kp(int x, node aa) {
	if (aa.a == x && aa.b != x && aa.c != x) {
		return 1;
	}
	if (aa.b == x && aa.a != x && aa.c != x) {
		return 2;
	}
	if (aa.c == x && aa.b != x && aa.a != x) {
		return 3;
	}
	return 4;
}

bool met(ll id, ll i) {
	if (id == 1 && cnta < n / 2) {
		cnta++;
		sum += e[i].a;
		return 1;
	} else if (id == 2 && cntb < n / 2) {
		cntb++;
		sum += e[i].b;
		return 1;
	} else if (id == 3 && cntc < n / 2) {
		cntc++;
		sum += e[i].c;
		return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> e[i].a >> e[i].b >> e[i].c;
			e[i].p = (e[i].a + e[i].b + e[i].c) * 1.0 / 3;
//			cout << e[i].p << ' ';
			kcs007nb(e[i]);
		}
		sum = cnta = cntb = cntc = 0;
		sort(e + 1, e + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (e[i].mxa == e[i].mxb) {
				sum += e[i].mxa;
				continue;
			}
			int id = kp(e[i].mxa, e[i]);
			if (met(id, i))
				continue;
			id = kp(e[i].mxb, e[i]);
			if (id == 4) {
				sum += e[i].mxb;
				continue;
			} else if (met(id, i))
				continue;

			id = kp(e[i].mxc, e[i]);
			if (id == 4) {
				sum += e[i].mxc;
				continue;
			} else if (met(id, i))
				continue;
		}
		cout << sum << "\n";
	}
	return 0;
}
