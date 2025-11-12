#include <bits/stdc++.h>
using namespace std;
int a1[10000000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	int d = 0;
	cin >> a;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			a1[i] = a[i] - 48;
			d++;
		}
	}
	int c = a.size();
	sort(a1, a1 + d + 1);
	for (int i = d; i > 0; i--) {
		cout << a1[i];
	}
	return 0;
}
