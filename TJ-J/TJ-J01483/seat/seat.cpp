#include <bits/stdc++.h>
using namespace std;
//)!$*#@$*@$@!
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int little_R, cnt = 0, n, m;
	cin >> n >> m >> little_R;
	for (int i = 1; i < n * m; i++) {
		int tmp;
		cin >> tmp;
		if (tmp > little_R) cnt++;
	}
	int c = cnt / n, r = (c % 2 ? n - cnt % n - 1 : cnt % n);
	cout << c + 1 << " " << r + 1 << endl;
	return 0;
}
