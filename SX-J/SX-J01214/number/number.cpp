#include <bits/stdc++.h>
using namespace std;
long long b[1000010];

int cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int j = 1;
	int s = a.size();
	for (int i = 0; i <= s; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[j] = a[i] - '0';
			j++;
		}
	}
	sort(b + 1, b + j + 1, cmp);
	for (int i = 1; i < j; i++) {
		cout << b[i];
	}
	return 0;
}
