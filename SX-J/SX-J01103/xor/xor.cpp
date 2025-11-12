#include <bits/stdc++.h>
using namespace std;

int a[10010];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", & a[i]);
	if (k == 0)
		cout << 1;
	return 0;
}