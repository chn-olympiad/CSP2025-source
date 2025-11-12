#include <bits/stdc++.h>
using namespace std;
string a;

long long num[918] = {};
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	long long ulen = a.size();
	for (int i = 0; i < ulen; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			num[a[i] - '0']++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= num[i]; j++) {
			printf("%d", i);
		}
	}
	return 0;
}
