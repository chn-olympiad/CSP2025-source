#include <bits/stdc++.h>
using namespace std;
char b;
int a[1000100], i = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	while (cin >> b) {
		if (b >= '0' && b <= '9') {
			a[i] = b - '0';
			i++;
		}
	}
	sort(a, a + i + 1);
	for (int j = i; j > 0; j--) {
		cout << a[j];
	}
	return 0;
}