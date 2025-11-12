#include <bits/stdc++.h>
using namespace std;
int n, m, a[110];
int temp;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	int len = n * m;
	for (int i = 1; i <= len; ++i) {
		cin >> a[i];
	}
	temp = a[1];
	sort(a + 1, a + len + 1, cmp);
	for (int i = 1; i <= len; ++i) {
		if (a[i] == temp) {
			//n行 m列
			int ans1 = i / n, ans2 = i % n;
			//  列            行
			if (i % n != 0)
				++ans1;
			if (i % n == 0 && ans1 % 2 == 0)
				ans2 = n;
			else if (i % n == 0 && ans1 % 2 == 1)
				ans2 = n;
			if (ans1 % 2 == 1) {
				cout << ans1 << " " << ans2;
				break;
			} else if (ans1 % 2 == 0) {
				cout << ans1 << " " << (n + 1) - ans2;
				break;
			}
		}
	}
	return 0;
}

