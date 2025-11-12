#include <bits/stdc++.h>
using namespace std;
long long n;
int a[20];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	cout <<	n*n;
	return 0;
}
