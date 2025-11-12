#include <iostream>
#include <algorithm>
#include <cstring>
#include <string.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;

	int s[105];
	for (int i = 1; i <= m * n; i++) {
		cin >> s[i];
	}
	int a = s[1];
	for (int i = 1; i <= m * n; i++) {
		for (int j = 1; j <= m * n; j++) {
			if (s[j] > s[j + 1]) {
				swap(s[j], s[j + 1]);
			}
		}
	}
	int b;
	for (int i = 1; i <= m * n; i++) {
		if (s[i] == a) {
			b = i;
		}
	}
	int c = b / 4 + 1, r;
	if (c % 2 == 0) {
		r = n - b % 4 + 1;
	} else {
		r = b % 4;
	}
	cout << c << r;
	return 0;
}
