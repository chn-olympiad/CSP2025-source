#include <bits/stdc++.h>
using namespace std;
string a;
int a1[1000010];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	for (int i = 0; i < int(a.size()); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			a1[i] = a[i] - 47;
		}
	}
	sort(a1, a1 + 1000010, greater<int>());
	for (int i = 0; i < 1000010; i++) {
		if (a1[i] != 0) {
			cout << a1[i] - 1;
		} else {
			break;
		}
	}
	return 0;
}