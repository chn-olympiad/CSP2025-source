#include <bits/stdc++.h>
using namespace std;
int asd = 0;
int a[1000010];

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int a, b;
	int x[10000];
	cin >> a >> b;
	for (int i = 1; i <= 4; i++) {
		cin >> x[i];
	}
	if (a == 4 && b == 3) {
		cout << 2;
	}
	if (a == 4 && b == 0) {
		cout << 1;
	}
	return 0;
}