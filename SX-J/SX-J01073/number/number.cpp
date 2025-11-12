#include <bits/stdc++.h>
using namespace std;
string a;
int b[100000];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int e = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {

			b[e] = a[i] - 48;
			e++;
		}
	}
	sort(b, b + e );
	for (int i = e - 1; i >= 0; i--) {
		cout << b[i];
	}
	return 0;
}
