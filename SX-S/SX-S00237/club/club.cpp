#include <bits/stdc++.h>
using namespace std;
int T;
int n, suma, sumb, sumc, ans;

class node {
	public:
		int a, b, c;
};
node k[100010];

bool cmp(node xx, node yy) {
	if (xx.a != yy.a)
		return xx.a > yy.a;
	else if (xx.b != yy.b)
		return xx.b > yy.b;
	return xx.c > yy.c;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		suma = 0, sumb = 0, sumc = 0, ans = 0;
		cin >> n;
		int temp = n / 2;
		bool  flag = true;
		for (int i = 1; i <= n; ++i) {
			cin >> k[i].a >> k[i].b >> k[i].c;
			if (k[i].b != k[i].c || k[i].b != 0 || k[i].c != 0)
				flag = false;
		}
		sort(k + 1, k + n + 1, cmp);
		if (flag == true) {
			for (int i = 1; i <= n; ++i) {
				if (suma + 1 < temp) {
					++suma;
					ans += k[i].a;
				}
			}
		} else {
			for (int i = 1; i <= n; ++i) {
				if (k[i].a > k[i].b && suma + 1 <= temp) {
					suma++;
					ans += k[i].a;
				} else if (k[i].a < k[i].b && sumb + 1 <= temp) {
					sumb++;
					ans += k[i].b;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}