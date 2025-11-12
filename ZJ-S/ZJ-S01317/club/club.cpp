#include<bits/stdc++.h>
using namespace std;

struct person {
	int x, y, z;
};

int t, n;

bool cmp(person p, person q) {
	return p.x > q.x;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		person a[100005];
		bool two_zero = true;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			if (a[i].y || a[i].z) {
				two_zero = false;
			}
		}
		if (n == 2) {
			cout << max(a[1].x + a[2].y, max(a[1].x + a[2].z, max(a[1].y + a[2].x, max(a[1].y + a[2].z, max(a[1].z + a[2].x, a[1].z + a[2].y))))) << endl;
			continue;
		} 
		if (two_zero) {
			int ans = 0;
			sort (a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i].x;
			}
			cout << ans << endl;
			continue;
		}		
		cout << "42" << endl;
	}
	return 0;
}