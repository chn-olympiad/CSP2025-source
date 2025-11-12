#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int a[100];
	int num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		num += a[i];
	}
	cout << num / 2;
	return 0;
	fclose(stdin);
	fclose(stdout);
}