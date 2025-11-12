#include <bits/stdc++.h>
using namespace std;
int a, b, c;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> a >> b >> c;
	int s = a + b + c;
	int ans = 0;
	if (s > a * 2)
		ans++;
	if (s > b * 2)
		ans++;
	if (s > c * 2)
		ans++;
	cout << ans;
	return 0;
}
