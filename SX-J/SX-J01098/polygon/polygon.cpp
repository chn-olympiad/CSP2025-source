#include <bits/stdc++.h>
using namespace std;
int s[5005];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	int up = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		up += a;
		s[i] = up;
	}
	cout << up / 2;
	return 0;
}
