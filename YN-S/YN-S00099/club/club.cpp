#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, c, x, y, z;

struct str {
	int id;
	int cz;
} re1[100100], re2[100100], re3[100100];

long long ss[4];

//int re[4];

bool cmp(str s1, str s2) {
	if (s1.cz <= s2.cz)
		return true;
	return false;
}


int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		x = 0;
		y = 0;
		z = 0;
		memset(re1, 0, sizeof(re1));
		memset(re2, 0, sizeof(re2));
		memset(re3, 0, sizeof(re3));
		memset(ss, 0, sizeof(ss));
		//cout << x << ' ' << y << ' ' << z << '\n';
		for (int i = 1; i <= n; i++) {
			cin >> a >> b >> c;
			if (a >= b && a >= c) {
				x++;
				re1[x].id = i;
				ss[1] += a;
				re1[x].cz = abs(a - max(b, c));
			} else if (b >= a && b >= c) {
				y++;
				re2[y].id = i;
				ss[2] += b;
				re2[y].cz = abs(b - max(a, c));
			} else {
				z++;
				re3[z].id = i;
				ss[3] += c;
				re3[z].cz = abs(c - max(a, b));
			}
		}
		//cout << x << ' ' << y << ' ' << z << '\n';
		if (x <= n / 2 && y <= n / 2 && z <= n / 2)
			cout << ss[1] + ss[2] + ss[3] << '\n';
		else {
			if (x >= y && x >= z) {
				//cout << 1;
				sort(re1 + 1, re1 + x, cmp);
				//cout << 1;
				for (int i = x; i >= 1; i--) {
					//cout << i << endl;
					if (i <= n / 2)
						break;
					ss[1] -= re1[x - i + 1].cz;
				}
			} else if (y >= x && y >= z) {
				sort(re2 + 1, re2 + y, cmp);
				for (int i = y; i >= 1; i--) {
					if (i <= n / 2)
						break;
					ss[2] -= re2[y - i + 1].cz;
					//cout << ss[1] + ss[2] + ss[3] << '\n';
				}
			} else {
				sort(re3 + 1, re3 + z, cmp);
				//for(int i=1; i<=)
				for (int i = z; i >= 1; i--) {
					if (i <= n / 2)
						break;
					ss[3] -= re3[z - i + 1].cz;
				}
			}
			cout << ss[1] + ss[2] + ss[3] << '\n';

		}
	}
	return 0;
}