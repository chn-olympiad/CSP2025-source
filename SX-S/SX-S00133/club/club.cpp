#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
long long t, n, ans;
int va, vb, vc, num[4];
map<int, int> mp;

struct sat {
	int a, b, c, ai, bi, ci, cha;
} st[N];

bool cmp(sat x, sat y) {
	return x.cha > y.cha;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		ans = 0;
		va = 0;
		vb = 0;
		vc = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num[1] >> num[2] >> num[3];
			mp[num[1]] = 1;
			mp[num[2]] = 2;
			mp[num[3]] = 3;
			sort(num + 1, num + 4);
			st[i].a = num[3];
			st[i].ai = mp[num[3]];
			st[i].b = num[2];
			st[i].bi = mp[num[2]];
			st[i].cha = num[3] - num[2];
		}
		sort(st + 1, st + n + 1, cmp);
		for (int i = 1; i <= n; i++) {
			if (st[i].ai == 1 && va < n / 2) {
				va++;
				ans += st[i].a;
			} else if (st[i].ai == 2 && vb < n / 2) {
				vb++;
				ans += st[i].a;
			} else if (st[i].ai == 3 && vc < n / 2) {
				vc++;
				ans += st[i].a;
			} else if (st[i].bi == 1 && va < n / 2) {
				va++;
				ans += st[i].b;
			} else if (st[i].bi == 2 && vb < n / 2) {
				vb++;
				ans += st[i].b;
			} else if (st[i].bi == 3 && vc < n / 2) {
				vc++;
				ans += st[i].b;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
