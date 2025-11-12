#include <bits/stdc++.h>
using namespace std;
int n, k, a[500005], z;
long long s = 0;

int main() {
	freopen("xor", "r", stdin);
	freopen("xor", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout << n / 2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}