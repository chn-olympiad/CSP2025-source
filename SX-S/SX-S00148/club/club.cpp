#include <bits/stdc++.h>
using namespace std;
long long T;
const int N = 1e5+10;

struct st {
	int m1;
	int m2;
	int m3;
};

bool cmp(st x, st y) {
	return x.m1 > y.m1;
}

bool cmp1(st x, st y) {
	return x.m2 > y.m2;
}

bool cmp2(int x, int y) {
	return x > y;
}

bool cmp3(st x, st y) {
	if (x.m1 == x.m2 && y.m1 == y.m2)
		return y.m1 > x.m1;
	return abs(x.m1 - x.m2) > abs(y.m1 - y.m2);
}
st a[N];
int  c1[N], c2[N], c3[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		long long rl1, rl2, n, s = 0, f = 0, k = 0;
		memset(a, 0, sizeof(a));
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		memset(c3, 0, sizeof(c3));
		cin >> n;
		rl1 = 0;
		rl2 = 0;

		for (int i = 1; i <= n; i++) {
			cin >> a[i].m1 >> a[i].m2 >> a[i].m3;
		}
		for (int i = 1; i <= n; i++) {
			if (a[i].m3 == 0) {
				if (a[i].m2 == 0) {
					f = 1;
				} else if (a[i].m2 != 0) {
					f = 2;
					break;
				}
			} else {
				f = 0;
				break;
			}
		}
		if (f == 1) {
			sort(a + 1, a + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				s = s + a[i].m1;
			}
			cout << s << "\n";
		}
//		if (f == 2) {
//			sort(a + 1, a + n + 1, cmp3);
//			for (int i = 1; i <= n; i++) {
//				if (a[i].m1 < a[i].m2 && rl2 < n / 2) {
//					c2[++rl2] = a[i].m2;
//				} else if (a[i].m1 > a[i].m2 && rl1 < n / 2) {
//					c1[++rl1] = a[i].m1;
//				} else if (rl1 >= n / 2 ) {
//					c2[++rl2] = max(a[i].m1, a[i].m2);
//				} else if (rl2 >= n / 2) {
//					c1[++rl1] = max(a[i].m1, a[i].m2);
//				}
//			}
////		cout << "rl1=" << rl1 << "\n";
////		cout << "rl2=" << rl2 << "\n";
//			sort(c2 + 1, c2 + n + 1, cmp2);
//			sort(c1 + 1, c1 + n + 1, cmp2);
//
////		for (int i = 1; i <= n; i++) {
////			cout << c1[i] << ' ';
////			k++;
////			if (k == 10) {
////				cout << "\n";
////				k = 0;
////			}
////
////		}
////
////		cout << "\n";
////		cout << "\n";
////
////		for (int i = 1; i <= n; i++) {
////			cout << c2[i] << ' ';
////			k++;
////			if (k == 10) {
////				cout << "\n";
////				k = 0;
////
////			}
////		}
////		cout << "\n";
////		cout << "\n";
//			for (int i = 1; i <= n; i++) {
//				if (c2[i] != 0)
//					c3[i] = c2[i];
//			}
//			for (int i = 1; i <= n; i++) {
//				if (c1[i] != 0)
//					c3[n / 2 + i] = c1[i];
//			}
//			sort(c3 + 1, c3 + n + 1, cmp2);
////		for (int i = 1; i <= n; i++) {
////			cout << c3[i] << ' ';
////			k++;
////			if (k == 10) {
////				cout << "\n";
////				k = 0;
////			}
////		}
////
////		cout << "\n";
////		cout << "\n";
//			for (int i = 1; i <= n ; i++) {
//				s = s + c3[i];
//			}
//			cout << s << "\n";
//		}
	}
	return 0;
}
