#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, a[N], sum, mymax = -1;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		mymax = max(mymax, a[i]);
	}
	if (sum > mymax * 2)
		cout << 1;
	else
		cout << 0;

	return 0;
}
