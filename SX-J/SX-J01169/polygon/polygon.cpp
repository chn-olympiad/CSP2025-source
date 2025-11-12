#include <bits/stdc++.h>
using namespace std;
int a[50005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n == 3) {
		int t = max(a[1], max(a[2], a[3]));
		if ((a[1] + a[2] + a[3]) > t)
			cout << 1;
		else
			cout << 0;
	} else
		cout << 0;
	return 0;
}
