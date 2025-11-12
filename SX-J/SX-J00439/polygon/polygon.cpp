#include <bits/stdc++.h>
using namespace std;
int a, n[5005];

long long ans(int l, int h) {
	long long s = 0;
	//cout << l;
	if (l > 0) {
		if (n[l] < h)
			s++;
		h += n[l];
	}
	if (l == a)
		return s;
	else {
		for (int i = l + 1; i <= a; i++)
			s += ans(i, h);
		return s;
	}
}

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	cin >> a;
	for (int i = 1; i <= a; i++)
		cin >> n[i];
	cout << ans(0, 0) % 998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
