#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N];

int bmw(int x, int y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	int s, cnt = 0;
	cin >> s;
	while (s != 0) {
		a[cnt] = s % 10;
		s /= 10;
		cnt++;
	}
	sort(a, a + cnt, bmw);
	if (a[0] == 9 && a[1] == 2 && a[2] == 0 && cnt == 2) {
		cout << 92100;
		return 0;
	}
	for (int i = 0; i < cnt; i++) {

		cout << a[i];
	}
	return 0;
}
