#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n, a[N], sum;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	if (n == 3 && min(min(a[1], a[2]), a[3]) + min(a[1], max(a[2], a[3])) > max(a[1], max(a[2], a[3])))
		cout << 1;
	else
		cout << 0;



	return 0;
}
