#include <bits/stdc++.h>
using namespace std;
int a[1010];


bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int cnt = 0;
	for (int i = 1; i <= 1000; i++) {
		cin >> a[i];
		if (a[i] != 0) {
			cnt++;
		}
	}
	sort(a + 1, a + 1011, cmp);
	for (int i = 1; i <= cnt; i++) {
		cout << a[i];
	}
	return 0;
}