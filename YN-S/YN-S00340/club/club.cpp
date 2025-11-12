#include <bits/stdc++.h>
using namespace std;
const int m = 1e5 + 10;
int v[m], d[m], j[m];

struct c {
	int a, b, c;
} s[m];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long t, cnt, sum = 0, it = 0, xl = 0, o, p, z, g = 0;
	cin >> t;
	while (t--) {
		int n, z = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i].a >> s[i].b >> s[i].c;
			if (s[i].a >= s[i].b && s[i].a >= s[i].c)
				v[i] = s[i].a, sum++;
			if (s[i].b >= s[i].a && s[i].b >= s[i].c)
				d[i] = s[i].b, it++;
			if (s[i].c >= s[i].a && s[i].c >= s[i].b)
				j[i] = s[i].c, xl++;
			if (sum > n / 2) {
				sort(v, v + n);
				for (int i = n; i > n - 2; i++) {
					cin >> v[i];
					o += v[i];
					if ( s[i].b >= s[i].c)
						d[i] = s[i].b, it++;
					if ( s[i].c >= s[i].b)
						j[i] = s[i].c, xl++;
				}
			}
			if (it > n / 2) {
				sort(d, d + n);
				for (int i = n; i > n - 2; i++) {
					cin >> d[i];
					p += d[i];
					if ( s[i].a >= s[i].c)
						d[i] = s[i].a, sum++;
					if ( s[i].c >= s[i].a)
						j[i] = s[i].c, xl++;
				}
			}
			if (xl > n / 2) {
				sort(j, j + n);
				for (int i = n; i > n - 2; i++) {
					cin >> j[i];
					z += j[i];
					if ( s[i].b >= s[i].a)
						d[i] = s[i].b, it++;
					if ( s[i].a >= s[i].b)
						j[i] = s[i].a, sum++;
				}
			}


		}
		g = o + p + z;
		cout << g % (10 ^ n) << endl;
	}


	return 0;
}