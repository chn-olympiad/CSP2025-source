#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
const ll N = 1e5+5;

struct per {
	int bumen;
	ll deg;
};//最大、次大、第三大的部门；//前三个最大的满意度；

struct memb {
	per b[3];

	bool f = 0;
} a1[N];

bool cmp(per x, per y) {
	return x.deg > y.deg;
}

bool cmp1(memb x, memb y) {
	return x.b[0].deg > y.b[0].deg;
}

bool cmp2(memb x, memb y) {
	return x.b[1].deg > y.b[1].deg;
}

int main() {
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a1, 0, sizeof(a1));
		for (int i = 1; i <= n; i++) {
			cin >> a1[i].b[0].deg >> a1[i].b[1].deg >> a1[i].b[2].deg;
			a1[i].b[0].bumen = 0;
			a1[i].b[1].bumen = 1;
			a1[i].b[2].bumen = 2;
		}
		ll nc[3] = {0, 0, 0}, ans = 0;
		for (int i = 1; i <= n; i++) {
			sort(a1[i].b, a1[i].b + 3, cmp);
		}
		sort(a1 + 1, a1 + n + 1, cmp1);
		bool f = 0;
		for (int i = 1; i <= n; i++) {
			if (nc[0] >= n / 2 && f == 0) {
				f = 1;
				sort(a1 + i - 1, a1 + n, cmp2);
			}
			if (nc[a1[i].b[0].bumen] < n / 2) {
				ans += a1[i].b[0].deg;
//				cout << a1[i].b[0].bumen << ' ' << a1[i].b[0].deg << endl;
				nc[a1[i].b[0].bumen]++;
				//			a1[i].f=1;
			} else if (nc[a1[i].b[1].bumen] < n / 2) {
				ans += a1[i].b[1].deg;
				nc[a1[i].b[1].bumen]++;

//				cout << a1[i].b[1].bumen << ' ' << a1[i].b[1].deg << endl;
			} else if (nc[a1[i].b[2].bumen] < n / 2) {
				ans += a1[i].b[2].deg;
				nc[a1[i].b[2].bumen]++;

//				cout << a1[i].b[2].bumen << ' ' << a1[i].b[2].deg << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
/*
