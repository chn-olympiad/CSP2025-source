#include <bits/stdc++.h>
using namespace std;
int s;
int cnt, a[105], b[105];

int main() {
	//freopen("number.in", "r", "stdin");
	//freopen("number.out", "w", "stdout");
	cin >> s;
	int w = s;
	if (s / 10 == 0) {
		cout << s;
		return 0;
	} else {
		for (int i = 1; i <= s; i++) {
			if (s != 0) {
				a[i] = s % 10;
				s /= 10;
				cnt++;
			} else {
				break;
			}
		}
		for (int i = 1; i <= w; i++) {
			if (a[i] >= 0 && a[i] <= 9) {
				b[i] = a[i];
			}
		}
		for (int i = 1; i <= w; i++) {
			if (b[i + 1] != 0) {
				if (b[i] > b[i + 1] ) {
					swap(b[i + 1], b[i]);
				}
			}
		}
		for (int i = 0; i <= cnt; i++) {
			cout << b[i];
		}
	}

	return 0;
}