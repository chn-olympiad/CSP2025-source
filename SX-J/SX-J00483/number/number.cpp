#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000010], n;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int s = a.size();
	for (int i = 0; i < s; i ++) {
		if (int(a[i]) >= 48 && int(a[i]) <= 57) {
			b[n] = int(a[i]) - 48;
			n ++;
		}
	}
	sort(b, b + n);
	for (int i = n - 1; i >= 0; i --) {
		printf("%d", b[i]);
	}
	return 0;
}
