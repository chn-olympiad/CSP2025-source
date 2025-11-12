#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m, r, l, x, ans = 1,	s[105] = {'0'};//n和m：行列；r：总人数；l：临时变量无意义；x：小明的成绩；s：桶排序；ans：名次

	cin >> n >> m;
	r = n * m;
	cin >> x;
	s[x] = 2;
	for (int i = 2; i <= r; i++) {
		cin >> l;
		s[l] = 1;
	}
	for (int i = 100; i >= 1; i--) {
		if (s[i] == 1)
			ans++;
		if (s[i] == 2)
			break;
	}
	if ((ans / n) % 2 == 0) {
		cout << ((ans - 1) / n) + 1 << ' ' << ans - (((ans - 1) / n)*n);
	} else {
		cout << ((ans - 1) / n) + 1 << ' ' << n - ((ans - 1) - ((ans / n)*n));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
