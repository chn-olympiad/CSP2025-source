#include <bits/stdc++.h>
using namespace std;
long long a[15][15];
int b[105];

int main() {
	//freopen("seat.in", "r", stdin);
	//freopen("seat.out", "w", stdout);
	int n, m;
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n * m; i++) {

		cin >> b[i];

	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 100) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 99) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 98) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 97) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 96) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 95) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 94) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 93) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 92) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 91) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 90) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 89) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 88) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 87) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 86) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 85) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 84) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 83) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 82) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 81) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 80) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 79) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 78) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 77) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 76) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 75) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 74) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 73) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 72) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 71) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 70) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 69) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 68) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 67) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 66) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 65) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 64) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 63) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 62) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 61) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 60) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 59) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 58) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 57) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 56) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 55) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 54) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 53) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 52) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 51) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 50) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 49) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 48) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 47) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 46) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 45) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 44) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 43) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 42) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 41) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 40) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 39) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 38) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 37) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 36) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 35) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 34) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 33) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 32) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 31) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 30) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 29) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 28) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 27) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 26) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 25) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 24) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 23) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 22) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 21) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 20) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 19) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 18) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 17) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 16) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 15) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 14) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 13) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 12) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 11) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 10) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 9) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 8) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 7) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 6) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 5) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 4) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 3) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 2) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	for (int i = 0; i < n * m; i++) {
		if (b[i] == 1) {
			ans++;
			if (b[0] == b[i]) {
				if (ans % n == 0) {
					cout << ans / n << " ";
					if (ans / n == 2 || ans / n == 4 || ans / n == 6 || ans / n == 8 || ans / n == 10)
						cout << 1;
					else
						cout << n;
				} else {
					cout << ans / n + 1 << " ";
					if (ans / n + 1 == 2 || ans / n + 1 == 4 || ans / n + 1 == 6 || ans / n + 1 == 8 || ans / n + 1 == 10)
						cout << n - ans % n + 1 << " ";
					else
						cout << ans % n;
				}
			}
		}
	}
	return 0;
}
