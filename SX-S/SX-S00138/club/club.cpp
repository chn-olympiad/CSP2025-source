#include <bits/stdc++.h>
#define ll long long
#define f_1(i,a,b) for(ll i=a;i<=b;i++)
#define f_0(i,a,b) for(ll i=a;i>=b;i--)
using namespace std;

ll read() {
	ll n = 0, f = 1;
	char x;
	x = getchar();
	while (x > '9' || x < '0') {
		if (x == '-')
			f = -1;
		x = getchar();
	}
	while (x >= '0' && x <= '9') {
		n = (n << 1) + (n << 3) + (x ^ 48);
		x = getchar();
	}
	return n * f;
}
ll T, n, ass[100010][5], s1[100010], s2[100010], s3[100010], ans, v1, v2, v3, vm;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		memset(ass, 0, sizeof ass);
		memset(s1, 0, sizeof s1);
		memset(s2, 0, sizeof s2);
		memset(s3, 0, sizeof s3);
		ans = 0;
		v1 = 0;
		v2 = 0;
		v3 = 0;
		vm = 0;
		cin >> n;
		f_1(i, 1, n) {
			ass[i][1] = read();
			ass[i][2] = read();
			ass[i][3] = read();
			ass[i][4] = ass[i][1] + ass[i][2] + ass[i][3];
			ass[i][0] = max(ass[i][1], max(ass[i][2], ass[i][3]));
			ans += ass[i][0];
			if (ass[i][0] == ass[i][1])
				v1++, s1[v1] = ass[i][0] - (ass[i][4] - ass[i][0] - min(ass[i][1], min(ass[i][2], ass[i][3])));
			else if (ass[i][0] == ass[i][2])
				v2++, s2[v2] = ass[i][0] - (ass[i][4] - ass[i][0] - min(ass[i][1], min(ass[i][2], ass[i][3])));
			else if (ass[i][0] == ass[i][3])
				v3++, s3[v3] = ass[i][0] - (ass[i][4] - ass[i][0] - min(ass[i][1], min(ass[i][2], ass[i][3])));
		}
		vm = max(v1, max(v2, v3));
		if (vm == v1) {
			sort(s1 + 1, s1 + vm + 1);
			f_1(i, 1, vm - n / 2) ans -= s1[i];
		} else if (vm == v2) {
			sort(s2 + 1, s2 + vm + 1);
			f_1(i, 1, vm - n / 2) ans -= s2[i];
		} else if (vm == v3) {
			sort(s3 + 1, s3 + vm + 1);
			f_1(i, 1, vm - n / 2) ans -= s3[i];
		}
		cout << ans << endl;
	}
	return 0;
}