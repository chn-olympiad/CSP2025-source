#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	long long l1 = a * b, l5 = 1;
	long long s[l1 + 3];
	long long s2[l1 + 3] = {0};
	for (int i = 1; i <= l1; i++) {
		cin >> s[i];
	}
	long long l3 = s[1];
	long long s3[a + 3][b + 3] = {0};
	sort(s + 1, s + l1 + 1);
	for (int i = l1; i >= 1; i--) {
		s2[l5] = s[i];
		l5++;
	}
	int n = 1;
	for (int j = 1; j <= a; j++) {
		if (j % 2 != 0) {
			for (int i = 1; i <= b; i++) {
				s3[i][j] = s2[n];
				n++;
			}
		}
		if (j % 2 == 0) {
			for (int i = b; i >= 1; i--) {
				s3[i][j] = s2[n];
				n++;
			}

		}
	}
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (s3[i][j] == l3) {
				cout << j << " " << i;
				return 0;
			}
		}
	}
	return 0;
}
