#include <iostream>
#include <algorithm>
using namespace std;

struct TMD {
	int a, b, c;
	bool ans = false;
};

bool amp(TMD a, TMD b) {
	return a.a > b.a;
}

bool cmp(TMD a, TMD b) {
	return a.c > b.c;
}

bool bmp(TMD a, TMD b) {
	return a.b > b.b;
}
int T;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		TMD x[5];
		int sum = 0, aaa = n / 2, bbb = n / 2, ccc = n / 2;
		for (long long i = 1; i <= n; i++) {
			cin >> x[i].a >> x[i].b >> x[i].c;
		}
		if (n == 2) {
			if (x[1].a - max(x[1].b, x[1].c) < x[2].a) {
				cout << max(x[1].b, x[1].c) + x[2].a << endl;
				continue;
			} else if (x[1].b - max(x[1].a, x[1].c) < x[2].b) {
				cout << max(x[1].a, x[1].c) + x[2].b << endl;
				continue;
			} else if (x[1].c - max(x[1].a, x[1].b) < x[2].c) {
				cout << max(x[1].a, x[1].b) + x[2].c << endl;
				continue;
			}
		}

		sort(x + 1, x + n + 1, cmp);
		//cout << x[1].c << endl;
		for (long long i = 1; i <= n; i++) {
			if (x[i].c > max(x[i].b, x[i].a) && x[i].ans == false && ccc > 0) {
				ccc--;
				sum += x[i].c;
				//cout << "c" << " " << x[i].c;
				x[i].ans = true;
			}
		}
		sort(x + 1, x + n + 1, bmp);
		//cout << x[1].b << endl;
		for (long long i = 1; i <= n; i++) {
			if (x[i].b > max(x[i].c, x[i].a) && x[i].ans == false && bbb > 0) {
				bbb--;
				sum += x[i].b;
				//cout << "b" << " " << x[i].b;
				x[i].ans = true;
			}
		}
		sort(x + 1, x + n + 1, amp);
		for (long long i = 1; i <= n; i++) {
			if (x[i].a > max(x[i].c, x[i].b) && x[i].ans == false && aaa > 0) {
				aaa--;
				sum += x[i].a;
				//cout << "a" << " " << x[i].a;
				x[i].ans = true;
			}
		}
		for (long long i = 1; i <= n; i++) {
			if (x[i].ans == false) {
				if ((max(x[i].a, max(x[i].b, x[i].c)) == x[i].a) && aaa > 0) {
					sum += x[i].a;
					aaa--;
				} else if ((max(x[i].a, max(x[i].b, x[i].c)) == x[i].b) && bbb > 0) {
					sum += x[i].b;
					bbb--;
				} else if ((max(x[i].a, max(x[i].b, x[i].c)) == x[i].c) && ccc > 0) {
					sum += x[i].c;
					ccc--;
				} else if (aaa == 0 && bbb > 0 && ccc > 0 && x[i].b > x[i].c) {
					sum += x[i].b;
					bbb--;
				} else if (aaa == 0 && bbb > 0 && ccc > 0 && x[i].b < x[i].c) {
					sum += x[i].c;
					ccc--;
				} else if (bbb == 0 && aaa > 0 && ccc > 0 && x[i].a < x[i].c) {
					sum += x[i].c;
					ccc--;
				} else if (bbb == 0 && aaa > 0 && ccc > 0 && x[i].a > x[i].c) {
					sum += x[i].a;
					aaa--;
				} else if (ccc == 0 && aaa > 0 && bbb > 0 && x[i].a > x[i].b) {
					sum += x[i].a;
					aaa--;
				} else if (ccc == 0 && aaa > 0 && bbb > 0 && x[i].a < x[i].b) {
					sum += x[i].b;
					aaa--;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}