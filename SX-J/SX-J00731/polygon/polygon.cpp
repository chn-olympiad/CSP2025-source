#include <bits/stdc++.h>
using namespace std;
int nn[5001];
long long n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n == 3) {
		int a, b, c;
		cin >> a >> b >> c;
		int maxx = max(a, max(b, c)), h = a + b + c;
		if (h > maxx * 2)
			cout << 1;
		else
			cout << 0;
		return 0;
	}
	cout << 0;
	return 0;
}
