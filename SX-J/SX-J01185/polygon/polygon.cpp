#include <bits/stdc++.h>
using namespace std;
int a, n[10000], cnt = 0;

int main() {
	//freopen("polygon.in", "r", stdin);
	//freopen("polygon.out", "w", stdout);
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> n[i];
	}
	sort(n + 1, n + 1 + a);
	for (int  i = 1; i <= a - 2; i++) {
		if (n[i] + n[i + 1] > n[i + 2])
			cnt++;
	}
	cout << cnt;
	return 0;
}
