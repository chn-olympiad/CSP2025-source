#include <bits/stdc++.h>
using namespace std;
int a[100005][4];
//long long b[4];
long long n, max1;
int x1, x2, x3;

int zhao(int flag, int s, int cnt, int b1, int b2, int b3) {


	if (cnt > n) {
		//cout << flag << " " << b1 << " " << b2 << " " << b3 << " " << s << endl;
		if (s > max1) {
			max1 = s;
		}
		return 0;
	}
	//cout << a[cnt][1] << " " << a[cnt][2] << " " << a[cnt][3] << endl;
	//cout << flag << " " << b1 << " " << b2 << " " << b3 << " " << s << endl;
	//cout << a[cnt][flag] << endl;
	/*if (flag == 1 && b1 + 1 <= n / 2) {
		s += a[cnt][flag];
		//cout << b1 << " " << b2 << " " << b3 << " " << s << endl;
	}
	if (flag == 2 && b2 + 1 <= n / 2) {
		s += a[cnt][flag];
	}
	if (flag == 3 && b3 + 1 <= n / 2) {
		s += a[cnt][flag];
	}*/
	s += a[cnt][flag];
	//ตÝน้
	//cout << "#" << b1 << " " << b2 << " " << b3 << " " << endl;
	if (b1 + 1 <= n / 2) {
		zhao(1, s, cnt + 1, b1 + 1, b2, b3);
	}
	if (b2 + 1 <= n / 2) {
		zhao(2, s, cnt + 1, b1, b2 + 1, b3);
	}
	if (b3 + 1 <= n / 2) {
		zhao(3, s, cnt + 1, b1, b2, b3 + 1);
	}

	return 0;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		max1 = -9999999999;
		cin >> n;
		//cout << n;
		for (int j = 1; j <= n; j++) {
			for (int t = 1; t <= 3; t++) {
				cin >> a[j][t];
			}
		}
		zhao(1, 0, 1, 1, 0, 0);
		zhao(2, 0, 1, 0, 1, 0);
		zhao(3, 0, 1, 0, 0, 1);
		//cout << x1 << " " << x2 << " " << x3 << " " << endl;
		cout << max1 << endl;
	}
	return 0;
}
