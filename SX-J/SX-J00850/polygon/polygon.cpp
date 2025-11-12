#include <bits/stdc++.h>
using namespace std;
int n, l[5005], l2[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> l[i];
	}
	sort(l + 1, L + n + 1);
	for (int i = 1; i <= n; i++)
		l2[i] = l[i] * 2;
	return 0;
}
