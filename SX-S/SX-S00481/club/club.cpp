#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll T;
ll n;
ll q[100010][3];
ll s1, s2, s3;

struct CXK {
	ll a;
	ll b;
	ll z;
	ll c;
} x[100010];

bool cmp(CXK e, CXK w) {
	return e.z > w.z;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		s1 = s2 = s3 = 0;
		cin >> n;
		for (ll i = 1; i <= n; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
			q[i][0] = x[i].a;
			q[i][1] = x[i].b;
			q[i][2] = x[i].c;
			sort(q[i], q[i] + 3);
			x[i].z = q[i][2] - q[i][1];
		}
		sort(x + 1, x + n + 1, cmp);
		ll sum = 0;
		for (ll i = 1; i <= n; i++) {
			q[i][0] = x[i].a;
			q[i][1] = x[i].b;
			q[i][2] = x[i].c;
			sort(q[i], q[i] + 3);
			bool f = 0;
			if (q[i][2] == x[i].a) {
				if (s1 >= n / 2) {
					f = 1;
				} else {
					sum += q[i][2];
					s1++;
				}
			} else if (q[i][2] == x[i].b) {
				if (s2 >= n / 2) {
					f = 1;
				} else {
					sum += q[i][2];
					s2++;
				}
			} else if (q[i][2] == x[i].c) {
				if (s3 >= n / 2) {
					f = 1;
				} else {
					sum += q[i][2];
					s3++;
				}
			}
			if (f) {
				sum += q[i][1];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
