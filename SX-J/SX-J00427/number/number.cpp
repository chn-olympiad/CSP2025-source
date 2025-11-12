#include <bits/stdc++.h>
using namespace std;
int a[1010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	for (int i = 1; i <= 10; i++) {
		cin >> a[i];
	}
	sort(a + 10, a + 10 + 1);
	for (int i = 10; i >= 1; i--) {
		cout << a[i];
	}
	return 0;
}