//记得解除freopen的注释
#include <bits/stdc++.h>
using namespace std;
int n, m, R;	//行i列j
int a[105][105], c[105];

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m ;
	for (int i = 1; i <= n; i ++) {
		cin >> R >> c[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sort(a + 1, a + 1 + n);
			if (R == 100 or (n == 1 and m == 1)) {
				cout << 1 << " " << 1;
			} else if (n == 1) {
				if (m == 2) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					}
				}
				if (m == 3) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					}
				}
				if (m == 4) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					}
				}
				if (m == 5) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					} else if (R == c[5]) {
						cout << 1 << " " << 5;
					}
				}
				if (m == 6) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					} else if (R == c[5]) {
						cout << 1 << " " << 5;
					} else if (R == c[6]) {
						cout << 1 << " " << 6;
					}
				}
				if (m == 7) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					} else if (R == c[5]) {
						cout << 1 << " " << 5;
					} else if (R == c[6]) {
						cout << 1 << " " << 6;
					} else if (R == c[7]) {
						cout << 1 << " " << 7;
					}
				}
				if (m == 8) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					} else if (R == c[5]) {
						cout << 1 << " " << 5;
					} else if (R == c[6]) {
						cout << 1 << " " << 6;
					} else if (R == c[7]) {
						cout << 1 << " " << 7;
					} else if (R == c[8]) {
						cout << 1 << " " << 8;
					}
				}
				if (m == 9) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					} else if (R == c[5]) {
						cout << 1 << " " << 5;
					} else if (R == c[6]) {
						cout << 1 << " " << 6;
					} else if (R == c[7]) {
						cout << 1 << " " << 7;
					} else if (R == c[8]) {
						cout << 1 << " " << 8;
					} else if (R == c[9]) {
						cout << 1 << " " << 9;
					}
				}
				if (m == 10) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 2;
					} else if (R == c[3]) {
						cout << 1 << " " << 3;
					} else if (R == c[4]) {
						cout << 1 << " " << 4;
					} else if (R == c[5]) {
						cout << 1 << " " << 5;
					} else if (R == c[6]) {
						cout << 1 << " " << 6;
					} else if (R == c[7]) {
						cout << 1 << " " << 7;
					} else if (R == c[8]) {
						cout << 1 << " " << 8;
					} else if (R == c[9]) {
						cout << 1 << " " << 9;
					} else if (R == c[10]) {
						cout << 1 << " " << 10;
					}
				}
			} else if (n == 2) {
				if (m == 1) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					}
				}
				if (m == 2) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					}
				}
				if (m == 3) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					}
				}
				if (m == 4) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					} else if (R == c[7]) {
						cout << 2 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					}
				}
				if (m == 5) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					} else if (R == c[7]) {
						cout << 2 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					} else if (R == c[9]) {
						cout << 1 << " " << 5;
					} else if (R == c[10]) {
						cout << 2 << " " << 5;
					}
				}
				if (m == 6) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					} else if (R == c[7]) {
						cout << 2 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					} else if (R == c[9]) {
						cout << 1 << " " << 5;
					} else if (R == c[10]) {
						cout << 2 << " " << 5;
					} else if (R == c[11]) {
						cout << 2 << " " << 6;
					} else if (R == c[12]) {
						cout << 1 << " " << 6;
					}
				}
				if (m == 7) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					} else if (R == c[7]) {
						cout << 2 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					} else if (R == c[9]) {
						cout << 1 << " " << 5;
					} else if (R == c[10]) {
						cout << 2 << " " << 5;
					} else if (R == c[11]) {
						cout << 2 << " " << 6;
					} else if (R == c[12]) {
						cout << 1 << " " << 6;
					} else if (R == c[13]) {
						cout << 1 << " " << 7;
					} else if (R == c[14]) {
						cout << 2 << " " << 7;
					}
				}
				if (m == 8) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					} else if (R == c[7]) {
						cout << 2 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					} else if (R == c[9]) {
						cout << 1 << " " << 5;
					} else if (R == c[10]) {
						cout << 2 << " " << 5;
					} else if (R == c[11]) {
						cout << 2 << " " << 6;
					} else if (R == c[12]) {
						cout << 1 << " " << 6;
					} else if (R == c[13]) {
						cout << 1 << " " << 7;
					} else if (R == c[14]) {
						cout << 2 << " " << 7;
					} else if (R == c[15]) {
						cout << 1 << " " << 8;
					} else if (R == c[16]) {
						cout << 1 << " " << 8;
					}
				}
				if (m == 9) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 2 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 2 << " " << 3;
					} else if (R == c[7]) {
						cout << 2 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					} else if (R == c[9]) {
						cout << 1 << " " << 5;
					} else if (R == c[10]) {
						cout << 2 << " " << 5;
					} else if (R == c[11]) {
						cout << 2 << " " << 6;
					} else if (R == c[12]) {
						cout << 1 << " " << 6;
					} else if (R == c[13]) {
						cout << 1 << " " << 7;
					} else if (R == c[14]) {
						cout << 2 << " " << 7;
					} else if (R == c[15]) {
						cout << 2 << " " << 8;
					} else if (R == c[16]) {
						cout << 1 << " " << 8;
					} else if (R == c[17]) {
						cout << 1 << " " << 9;
					} else if (R == c[18]) {
						cout << 2 << " " << 9;
					}
				}
				if (m == 10) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 1 << " " << 1;
					} else if (R == c[3]) {
						cout << 1 << " " << 2;
					} else if (R == c[4]) {
						cout << 1 << " " << 2;
					} else if (R == c[5]) {
						cout << 1 << " " << 3;
					} else if (R == c[6]) {
						cout << 1 << " " << 3;
					} else if (R == c[7]) {
						cout << 1 << " " << 4;
					} else if (R == c[8]) {
						cout << 1 << " " << 4;
					} else if (R == c[9]) {
						cout << 1 << " " << 5;
					} else if (R == c[10]) {
						cout << 1 << " " << 5;
					} else if (R == c[11]) {
						cout << 1 << " " << 6;
					} else if (R == c[12]) {
						cout << 1 << " " << 6;
					} else if (R == c[13]) {
						cout << 1 << " " << 7;
					} else if (R == c[14]) {
						cout << 1 << " " << 7;
					} else if (R == c[15]) {
						cout << 1 << " " << 8;
					} else if (R == c[16]) {
						cout << 1 << " " << 8;
					} else if (R == c[17]) {
						cout << 1 << " " << 9;
					} else if (R == c[18]) {
						cout << 1 << " " << 9;
					} else if (R == c[19]) {
						cout << 1 << " " << 10;
					} else if (R == c[20]) {
						cout << 1 << " " << 10;
					}
				}

			} else if (n == 3) {
				if (m == 1) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					}
				}
				if (m == 2) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					}
				}
				if (m == 3) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					}
				}
				if (m == 4) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					}
				}
				if (m == 5) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					} else if (R == c[13]) {
						cout << 1 << " " << 5;
					} else if (R == c[14]) {
						cout << 2 << " " << 5;
					} else if (R == c[15]) {
						cout << 3 << " " << 5;
					}
				}
				if (m == 6) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					} else if (R == c[13]) {
						cout << 1 << " " << 5;
					} else if (R == c[14]) {
						cout << 2 << " " << 5;
					} else if (R == c[15]) {
						cout << 3 << " " << 5;
					} else if (R == c[16]) {
						cout << 3 << " " << 6;
					} else if (R == c[17]) {
						cout << 2 << " " << 6;
					} else if (R == c[18]) {
						cout << 1 << " " << 6;
					}
				}
				if (m == 7) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					} else if (R == c[13]) {
						cout << 1 << " " << 5;
					} else if (R == c[14]) {
						cout << 2 << " " << 5;
					} else if (R == c[15]) {
						cout << 3 << " " << 5;
					} else if (R == c[16]) {
						cout << 3 << " " << 6;
					} else if (R == c[17]) {
						cout << 2 << " " << 6;
					} else if (R == c[18]) {
						cout << 1 << " " << 6;
					} else if (R == c[19]) {
						cout << 1 << " " << 7;
					} else if (R == c[20]) {
						cout << 2 << " " << 7;
					} else if (R == c[21]) {
						cout << 3 << " " << 7;
					}
				}
				if (m == 8) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					} else if (R == c[13]) {
						cout << 1 << " " << 5;
					} else if (R == c[14]) {
						cout << 2 << " " << 5;
					} else if (R == c[15]) {
						cout << 3 << " " << 5;
					} else if (R == c[16]) {
						cout << 3 << " " << 6;
					} else if (R == c[17]) {
						cout << 2 << " " << 6;
					} else if (R == c[18]) {
						cout << 1 << " " << 6;
					} else if (R == c[19]) {
						cout << 1 << " " << 7;
					} else if (R == c[20]) {
						cout << 2 << " " << 7;
					} else if (R == c[21]) {
						cout << 3 << " " << 7;
					} else if (R == c[22]) {
						cout << 3 << " " << 8;
					} else if (R == c[23]) {
						cout << 2 << " " << 8;
					} else if (R == c[24]) {
						cout << 1 << " " << 8;
					}
				}
				if (m == 9) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					} else if (R == c[13]) {
						cout << 1 << " " << 5;
					} else if (R == c[14]) {
						cout << 2 << " " << 5;
					} else if (R == c[15]) {
						cout << 3 << " " << 5;
					} else if (R == c[16]) {
						cout << 3 << " " << 6;
					} else if (R == c[17]) {
						cout << 2 << " " << 6;
					} else if (R == c[18]) {
						cout << 1 << " " << 6;
					} else if (R == c[19]) {
						cout << 1 << " " << 7;
					} else if (R == c[20]) {
						cout << 2 << " " << 7;
					} else if (R == c[21]) {
						cout << 3 << " " << 7;
					} else if (R == c[22]) {
						cout << 3 << " " << 8;
					} else if (R == c[23]) {
						cout << 2 << " " << 8;
					} else if (R == c[24]) {
						cout << 1 << " " << 8;
					} else if (R == c[25]) {
						cout << 1 << " " << 9;
					} else if (R == c[26]) {
						cout << 2 << " " << 9;
					} else if (R == c[27]) {
						cout << 3 << " " << 9;
					}
				}
				if (m == 10) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 3 << " " << 2;
					} else if (R == c[5]) {
						cout << 2 << " " << 2;
					} else if (R == c[6]) {
						cout << 1 << " " << 2;
					} else if (R == c[7]) {
						cout << 1 << " " << 3;
					} else if (R == c[8]) {
						cout << 2 << " " << 3;
					} else if (R == c[9]) {
						cout << 3 << " " << 3;
					} else if (R == c[10]) {
						cout << 3 << " " << 4;
					} else if (R == c[11]) {
						cout << 2 << " " << 4;
					} else if (R == c[12]) {
						cout << 1 << " " << 4;
					} else if (R == c[13]) {
						cout << 1 << " " << 5;
					} else if (R == c[14]) {
						cout << 2 << " " << 5;
					} else if (R == c[15]) {
						cout << 3 << " " << 5;
					} else if (R == c[16]) {
						cout << 3 << " " << 6;
					} else if (R == c[17]) {
						cout << 2 << " " << 6;
					} else if (R == c[18]) {
						cout << 1 << " " << 6;
					} else if (R == c[19]) {
						cout << 1 << " " << 7;
					} else if (R == c[20]) {
						cout << 2 << " " << 7;
					} else if (R == c[21]) {
						cout << 3 << " " << 7;
					} else if (R == c[22]) {
						cout << 3 << " " << 8;
					} else if (R == c[23]) {
						cout << 2 << " " << 8;
					} else if (R == c[24]) {
						cout << 1 << " " << 8;
					} else if (R == c[25]) {
						cout << 1 << " " << 9;
					} else if (R == c[26]) {
						cout << 2 << " " << 9;
					} else if (R == c[27]) {
						cout << 3 << " " << 9;
					} else if (R == c[28]) {
						cout << 3 << " " << 10;
					} else if (R == c[29]) {
						cout << 2 << " " << 10;
					} else if (R == c[30]) {
						cout << 1 << " " << 10;
					}
				}

			} else if (n == 4) {
				if (m == 1) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 4 << " " << 1;
					}
				}
				if (m == 2) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;
					} else if (R == c[3]) {
						cout << 3 << " " << 1;
					} else if (R == c[4]) {
						cout << 4 << " " << 1;
					} else if (R == c[5]) {
						cout << 4 << " " << 2;
					} else if (R == c[6]) {
						cout << 3 << " " << 2;
					} else if (R ==  c[7]) {
						cout << 2 << " " << 2;
					} else if (R == c[8]) {
						cout << 1 << " " << 2;
					}
				}
			} else if (m == 3) {
				if (R == c[1]) {
					cout << 1 << " " << 1;
				} else if (R == c[2]) {
					cout << 2 << " " << 1;
				} else if (R == c[3]) {
					cout << 3 << " " << 1;
				} else if (R == c[4]) {
					cout << 4 << " " << 1;
				} else if (R == c[5]) {
					cout << 4 << " " << 2;
				} else if (R == c[6]) {
					cout << 3 << " " << 2;
				} else if (R == c[7]) {
					cout << 2 << " " << 2;
				} else if (R == c[8]) {
					cout << 1 << " " << 2;
				} else if (R == c[9]) {
					cout << 1 << " " << 3;
				} else if (R == c[10]) {
					cout << 2 << " " << 3;
				} else if (R == c[11]) {
					cout << 3 << " " << 3;
				} else if (R == c[12]) {
					cout << 4 << " " << 3;
				}
			} else if (m == 4) {
				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 4 << " " << 2;

				} else if (R == c[6]) {
					cout << 3 << " " << 2;

				} else if (R == c[7]) {
					cout << 2 << " " << 2;

				} else if (R == c[8]) {
					cout << 1 << " " << 2;

				} else if (R == c[9]) {
					cout << 1 << " " << 3;

				} else if (R == c[10]) {
					cout << 2 << " " << 3;

				} else if (R == c[11]) {
					cout << 3 << " " << 3;

				} else if (R == c[12]) {
					cout << 4 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 4;

				} else if (R == c[14]) {
					cout << 3 << " " << 4;

				} else if (R == c[15]) {
					cout << 2 << " " << 4;

				} else if (R == c[16]) {
					cout << 1 << " " << 4;
				} else if (m == 5) {
					if (R == c[1]) {
						cout << 1 << " " << 1;
					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 4 << " " << 2;

					} else if (R == c[6]) {
						cout << 3 << " " << 2;

					} else if (R == c[7]) {
						cout << 2 << " " << 2;

					} else if (R == c[8]) {
						cout << 1 << " " << 2;

					} else if (R == c[9]) {
						cout << 1 << " " << 3;

					} else if (R == c[10]) {
						cout << 2 << " " << 3;

					} else if (R == c[11]) {
						cout << 3 << " " << 3;

					} else if (R == c[12]) {
						cout << 4 << " " << 3;

					} else if (R == c[13]) {
						cout << 4 << " " << 4;

					} else if (R == c[14]) {
						cout << 3 << " " << 4;

					} else if (R == c[15]) {
						cout << 2 << " " << 4;

					} else if (R == c[16]) {
						cout << 1 << " " << 4;

					} else if (R == c[17]) {
						cout << 1 << " " << 5;

					} else if (R == c[18]) {
						cout << 2 << " " << 5;

					} else if (R == c[19]) {
						cout << 3 << " " << 5;

					} else if (R == c[20]) {
						cout << 4 << " " << 5;
					}
				} else if (m == 6) {

					if (R == c[1]) {
						cout << 1 << " " << 1;

					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 4 << " " << 2;

					} else if (R == c[6]) {
						cout << 3 << " " << 2;

					} else if (R == c[7]) {
						cout << 2 << " " << 2;

					} else if (R == c[8]) {
						cout << 1 << " " << 2;

					} else if (R == c[9]) {
						cout << 1 << " " << 3;

					} else if (R == c[10]) {
						cout << 2 << " " << 3;

					} else if (R == c[11]) {
						cout << 3 << " " << 3;

					} else if (R == c[12]) {
						cout << 4 << " " << 3;

					} else if (R == c[13]) {
						cout << 4 << " " << 4;

					} else if (R == c[14]) {
						cout << 3 << " " << 4;

					} else if (R == c[15]) {
						cout << 2 << " " << 4;

					} else if (R == c[16]) {
						cout << 1 << " " << 4;

					} else if (R == c[17]) {
						cout << 1 << " " << 5;

					} else if (R == c[18]) {
						cout << 2 << " " << 5;

					} else if (R == c[19]) {
						cout << 3 << " " << 5;

					} else if (R == c[20]) {
						cout << 4 << " " << 5;

					} else if (R == c[21]) {
						cout << 4 << " " << 6;

					} else if (R == c[22]) {
						cout << 3 << " " << 6;

					} else if (R == c[23]) {
						cout << 2 << " " << 6;

					} else if (R == c[24]) {
						cout << 1 << " " << 6;
					}

				} else if (m == 7) {

					if (R == c[1]) {
						cout << 1 << " " << 1;

					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 4 << " " << 2;

					} else if (R == c[6]) {
						cout << 3 << " " << 2;

					} else if (R == c[7]) {
						cout << 2 << " " << 2;

					} else if (R == c[8]) {
						cout << 1 << " " << 2;

					} else if (R == c[9]) {
						cout << 1 << " " << 3;

					} else if (R == c[10]) {
						cout << 2 << " " << 3;

					} else if (R == c[11]) {
						cout << 3 << " " << 3;

					} else if (R == c[12]) {
						cout << 4 << " " << 3;

					} else if (R == c[13]) {
						cout << 4 << " " << 4;

					} else if (R == c[14]) {
						cout << 3 << " " << 4;

					} else if (R == c[15]) {
						cout << 2 << " " << 4;

					} else if (R == c[16]) {
						cout << 1 << " " << 4;

					} else if (R == c[17]) {
						cout << 1 << " " << 5;

					} else if (R == c[18]) {
						cout << 2 << " " << 5;

					} else if (R == c[19]) {
						cout << 3 << " " << 5;

					} else if (R == c[20]) {
						cout << 4 << " " << 5;

					} else if (R == c[21]) {
						cout << 4 << " " << 6;

					} else if (R == c[22]) {
						cout << 3 << " " << 6;

					} else if (R == c[23]) {
						cout << 2 << " " << 6;

					} else if (R == c[24]) {
						cout << 1 << " " << 6;

					} else if (R == c[25]) {
						cout << 1 << " " << 7;

					} else if (R == c[26]) {
						cout << 2 << " " << 7;

					} else if (R == c[27]) {
						cout << 3 << " " << 7;

					} else if (R == c[28]) {
						cout << 4 << " " << 7;
					}
				} else if (m == 8) {

					if (R == c[1]) {
						cout << 1 << " " << 1;

					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 4 << " " << 2;

					} else if (R == c[6]) {
						cout << 3 << " " << 2;

					} else if (R == c[7]) {
						cout << 2 << " " << 2;

					} else if (R == c[8]) {
						cout << 1 << " " << 2;

					} else if (R == c[9]) {
						cout << 1 << " " << 3;

					} else if (R == c[10]) {
						cout << 2 << " " << 3;

					} else if (R == c[11]) {
						cout << 3 << " " << 3;

					} else if (R == c[12]) {
						cout << 4 << " " << 3;

					} else if (R == c[13]) {
						cout << 4 << " " << 4;

					} else if (R == c[14]) {
						cout << 3 << " " << 4;

					} else if (R == c[15]) {
						cout << 2 << " " << 4;

					} else if (R == c[16]) {
						cout << 1 << " " << 4;

					} else if (R == c[17]) {
						cout << 1 << " " << 5;

					} else if (R == c[18]) {
						cout << 2 << " " << 5;

					} else if (R == c[19]) {
						cout << 3 << " " << 5;

					} else if (R == c[20]) {
						cout << 4 << " " << 5;

					} else if (R == c[21]) {
						cout << 4 << " " << 6;

					} else if (R == c[22]) {
						cout << 3 << " " << 6;

					} else if (R == c[23]) {
						cout << 2 << " " << 6;

					} else if (R == c[24]) {
						cout << 1 << " " << 6;

					} else if (R == c[25]) {
						cout << 1 << " " << 7;

					} else if (R == c[26]) {
						cout << 2 << " " << 7;

					} else if (R == c[27]) {
						cout << 3 << " " << 7;

					} else if (R == c[28]) {
						cout << 4 << " " << 7;

					} else if (R == c[29]) {
						cout << 4 << " " << 8;

					} else if (R == c[30]) {
						cout << 3 << " " << 8;

					} else if (R == c[31]) {
						cout << 2 << " " << 8;

					} else if (R == c[32]) {
						cout << 1 << " " << 8;
					}

				} else if (m == 9) {

					if (R == c[1]) {
						cout << 1 << " " << 1;

					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 4 << " " << 2;

					} else if (R == c[6]) {
						cout << 3 << " " << 2;

					} else if (R == c[7]) {
						cout << 2 << " " << 2;

					} else if (R == c[8]) {
						cout << 1 << " " << 2;

					} else if (R == c[9]) {
						cout << 1 << " " << 3;

					} else if (R == c[10]) {
						cout << 2 << " " << 3;

					} else if (R == c[11]) {
						cout << 3 << " " << 3;

					} else if (R == c[12]) {
						cout << 4 << " " << 3;

					} else if (R == c[13]) {
						cout << 4 << " " << 4;

					} else if (R == c[14]) {
						cout << 3 << " " << 4;

					} else if (R == c[15]) {
						cout << 2 << " " << 4;

					} else if (R == c[16]) {
						cout << 1 << " " << 4;

					} else if (R == c[17]) {
						cout << 1 << " " << 5;

					} else if (R == c[18]) {
						cout << 2 << " " << 5;

					} else if (R == c[19]) {
						cout << 3 << " " << 5;

					} else if (R == c[20]) {
						cout << 4 << " " << 5;

					} else if (R == c[21]) {
						cout << 4 << " " << 6;

					} else if (R == c[22]) {
						cout << 3 << " " << 6;

					} else if (R == c[23]) {
						cout << 2 << " " << 6;

					} else if (R == c[24]) {
						cout << 1 << " " << 6;

					} else if (R == c[25]) {
						cout << 1 << " " << 7;

					} else if (R == c[26]) {
						cout << 2 << " " << 7;

					} else if (R == c[27]) {
						cout << 3 << " " << 7;

					} else if (R == c[28]) {
						cout << 4 << " " << 7;

					} else if (R == c[29]) {
						cout << 4 << " " << 8;

					} else if (R == c[30]) {
						cout << 3 << " " << 8;

					} else if (R == c[31]) {
						cout << 2 << " " << 8;

					} else if (R == c[32]) {
						cout << 1 << " " << 8;

					} else if (R == c[33]) {
						cout << 1 << " " << 9;

					} else if (R == c[34]) {
						cout << 2 << " " << 9;

					} else if (R == c[35]) {
						cout << 3 << " " << 9;

					} else if (R == c[36]) {
						cout << 4 << " " << 9;
					}

				} else if (m == 10) {

					if (R == c[1]) {
						cout << 1 << " " << 1;

					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 4 << " " << 2;

					} else if (R == c[6]) {
						cout << 3 << " " << 2;

					} else if (R == c[7]) {
						cout << 2 << " " << 2;

					} else if (R == c[8]) {
						cout << 1 << " " << 2;

					} else if (R == c[9]) {
						cout << 1 << " " << 3;

					} else if (R == c[10]) {
						cout << 2 << " " << 3;

					} else if (R == c[11]) {
						cout << 3 << " " << 3;

					} else if (R == c[12]) {
						cout << 4 << " " << 3;

					} else if (R == c[13]) {
						cout << 4 << " " << 4;

					} else if (R == c[14]) {
						cout << 3 << " " << 4;

					} else if (R == c[15]) {
						cout << 2 << " " << 4;

					} else if (R == c[16]) {
						cout << 1 << " " << 4;

					} else if (R == c[17]) {
						cout << 1 << " " << 5;

					} else if (R == c[18]) {
						cout << 2 << " " << 5;

					} else if (R == c[19]) {
						cout << 3 << " " << 5;

					} else if (R == c[20]) {
						cout << 4 << " " << 5;

					} else if (R == c[21]) {
						cout << 4 << " " << 6;

					} else if (R == c[22]) {
						cout << 3 << " " << 6;

					} else if (R == c[23]) {
						cout << 2 << " " << 6;

					} else if (R == c[24]) {
						cout << 1 << " " << 6;

					} else if (R == c[25]) {
						cout << 1 << " " << 7;

					} else if (R == c[26]) {
						cout << 2 << " " << 7;

					} else if (R == c[27]) {
						cout << 3 << " " << 7;

					} else if (R == c[28]) {
						cout << 4 << " " << 7;

					} else if (R == c[29]) {
						cout << 4 << " " << 8;

					} else if (R == c[30]) {
						cout << 3 << " " << 8;

					} else if (R == c[31]) {
						cout << 2 << " " << 8;

					} else if (R == c[32]) {
						cout << 1 << " " << 8;

					} else if (R == c[33]) {
						cout << 1 << " " << 9;

					} else if (R == c[34]) {
						cout << 2 << " " << 9;

					} else if (R == c[35]) {
						cout << 3 << " " << 9;

					} else if (R == c[36]) {
						cout << 4 << " " << 9;

					} else if (R == c[37]) {
						cout << 4 << " " << 10;

					} else if (R == c[38]) {
						cout << 3 << " " << 10;

					} else if (R == c[39]) {
						cout << 2 << " " << 10;

					} else if (R == c[40]) {
						cout << 1 << " " << 10;
					}

				} else if (n == 4) {

					if (m == 1) {
						if (R == c[1]) {
							cout << 1 << " " << 1;
						} else if (R == c[2]) {
							cout << 2 << " " << 1;
						} else if (R == c[3]) {
							cout << 3 << " " << 1;
						} else if (R == c[4]) {
							cout << 4 << " " << 1;
						} else if (R == c[5]) {
							cout << 5 << " " << 1;
						}
					}

					if (m == 2) {
						if (R == c[1]) {
							cout << 1 << " " << 1;
						} else if (R == c[2]) {
							cout << 2 << " " << 1;
						} else if (R == c[3]) {
							cout << 3 << " " << 1;
						} else if (R == c[4]) {
							cout << 4 << " " << 1;
						} else if (R == c[5]) {
							cout << 5 << " " << 1;
						}
						if (R == c[6]) {
							cout << 5 << " " << 2;
						} else if (R == c[7]) {
							cout << 4 << " " << 2;
						} else if (R == c[8]) {
							cout << 3 << " " << 2;
						} else if (R == c[9]) {
							cout << 2 << " " << 2;
						} else if (R == c[10]) {
							cout << 1 << " " << 2;
						}
					}
				}

				if (m == 3) {

					if (R == c[1]) {
						cout << 1 << " " << 1;

					} else if (R == c[2]) {
						cout << 2 << " " << 1;

					} else if (R == c[3]) {
						cout << 3 << " " << 1;

					} else if (R == c[4]) {
						cout << 4 << " " << 1;

					} else if (R == c[5]) {
						cout << 5 << " " << 1;

					} else if (R == c[6]) {
						cout << 5 << " " << 2;

					} else if (R == c[7]) {
						cout << 4 << " " << 2;

					} else if (R == c[8]) {
						cout << 3 << " " << 2;

					} else if (R == c[9]) {
						cout << 2 << " " << 2;

					} else if (R == c[10]) {
						cout << 1 << " " << 2;

					} else if (R == c[11]) {
						cout << 1 << " " << 3;

					} else if (R == c[12]) {
						cout << 2 << " " << 3;

					} else if (R == c[13]) {
						cout << 3 << " " << 3;

					} else if (R == c[14]) {
						cout << 4 << " " << 3;

					} else if (R == c[15]) {
						cout << 5 << " " << 3;
					}
				}
			} else if (m == 4) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;
				}
			} else if (m == 5) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;

				} else if (R == c[21]) {
					cout << 1 << " " << 5;

				} else if (R == c[22]) {
					cout << 2 << " " << 5;

				} else if (R == c[23]) {
					cout << 3 << " " << 5;

				} else if (R == c[24]) {
					cout << 4 << " " << 5;

				} else if (R == c[25]) {
					cout << 5 << " " << 5;
				}
			} else if (m == 6) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;

				} else if (R == c[21]) {
					cout << 1 << " " << 5;

				} else if (R == c[22]) {
					cout << 2 << " " << 5;

				} else if (R == c[23]) {
					cout << 3 << " " << 5;

				} else if (R == c[24]) {
					cout << 4 << " " << 5;

				} else if (R == c[25]) {
					cout << 5 << " " << 5;

				} else if (R == c[26]) {
					cout << 5 << " " << 6;

				} else if (R == c[27]) {
					cout << 4 << " " << 6;

				} else if (R == c[28]) {
					cout << 3 << " " << 6;

				} else if (R == c[29]) {
					cout << 2 << " " << 6;

				} else if (R == c[30]) {
					cout << 1 << " " << 6;
				}
			} else if (m == 7) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;

				} else if (R == c[21]) {
					cout << 1 << " " << 5;

				} else if (R == c[22]) {
					cout << 2 << " " << 5;

				} else if (R == c[23]) {
					cout << 3 << " " << 5;

				} else if (R == c[24]) {
					cout << 4 << " " << 5;

				} else if (R == c[25]) {
					cout << 5 << " " << 5;

				} else if (R == c[26]) {
					cout << 5 << " " << 6;

				} else if (R == c[27]) {
					cout << 4 << " " << 6;

				} else if (R == c[28]) {
					cout << 3 << " " << 6;

				} else if (R == c[29]) {
					cout << 2 << " " << 6;

				} else if (R == c[30]) {
					cout << 1 << " " << 6;

				} else if (R == c[31]) {
					cout << 1 << " " << 7;

				} else if (R == c[32]) {
					cout << 2 << " " << 7;

				} else if (R == c[33]) {
					cout << 3 << " " << 7;

				} else if (R == c[34]) {
					cout << 4 << " " << 7;

				} else if (R == c[35]) {
					cout << 5 << " " << 7;
				}

			} else if (m == 8) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;

				} else if (R == c[21]) {
					cout << 1 << " " << 5;

				} else if (R == c[22]) {
					cout << 2 << " " << 5;

				} else if (R == c[23]) {
					cout << 3 << " " << 5;

				} else if (R == c[24]) {
					cout << 4 << " " << 5;

				} else if (R == c[25]) {
					cout << 5 << " " << 5;

				} else if (R == c[26]) {
					cout << 5 << " " << 6;

				} else if (R == c[27]) {
					cout << 4 << " " << 6;

				} else if (R == c[28]) {
					cout << 3 << " " << 6;

				} else if (R == c[29]) {
					cout << 2 << " " << 6;

				} else if (R == c[30]) {
					cout << 1 << " " << 6;

				} else if (R == c[31]) {
					cout << 1 << " " << 7;

				} else if (R == c[32]) {
					cout << 2 << " " << 7;

				} else if (R == c[33]) {
					cout << 3 << " " << 7;

				} else if (R == c[34]) {
					cout << 4 << " " << 7;

				} else if (R == c[35]) {
					cout << 5 << " " << 7;

				} else if (R == c[36]) {
					cout << 5 << " " << 8;

				} else if (R == c[37]) {
					cout << 4 << " " << 8;

				} else if (R == c[38]) {
					cout << 3 << " " << 8;

				} else if (R == c[39]) {
					cout << 2 << " " << 8;

				} else if (R == c[40]) {
					cout << 1 << " " << 8;
				}

			} else if (m == 9) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;

				} else if (R == c[21]) {
					cout << 1 << " " << 5;

				} else if (R == c[22]) {
					cout << 2 << " " << 5;

				} else if (R == c[23]) {
					cout << 3 << " " << 5;

				} else if (R == c[24]) {
					cout << 4 << " " << 5;

				} else if (R == c[25]) {
					cout << 5 << " " << 5;

				} else if (R == c[26]) {
					cout << 5 << " " << 6;

				} else if (R == c[27]) {
					cout << 4 << " " << 6;

				} else if (R == c[28]) {
					cout << 3 << " " << 6;

				} else if (R == c[29]) {
					cout << 2 << " " << 6;

				} else if (R == c[30]) {
					cout << 1 << " " << 6;

				} else if (R == c[31]) {
					cout << 1 << " " << 7;

				} else if (R == c[32]) {
					cout << 2 << " " << 7;

				} else if (R == c[33]) {
					cout << 3 << " " << 7;

				} else if (R == c[34]) {
					cout << 4 << " " << 7;

				} else if (R == c[35]) {
					cout << 5 << " " << 7;

				} else if (R == c[36]) {
					cout << 5 << " " << 8;

				} else if (R == c[37]) {
					cout << 4 << " " << 8;

				} else if (R == c[38]) {
					cout << 3 << " " << 8;

				} else if (R == c[39]) {
					cout << 2 << " " << 8;

				} else if (R == c[40]) {
					cout << 1 << " " << 8;

				} else if (R == c[41]) {
					cout << 1 << " " << 9;

				} else if (R == c[42]) {
					cout << 2 << " " << 9;

				} else if (R == c[43]) {
					cout << 3 << " " << 9;

				} else if (R == c[44]) {
					cout << 4 << " " << 9;

				} else if (R == c[45]) {
					cout << 5 << " " << 9;
				}

			} else if (m == 9) {

				if (R == c[1]) {
					cout << 1 << " " << 1;

				} else if (R == c[2]) {
					cout << 2 << " " << 1;

				} else if (R == c[3]) {
					cout << 3 << " " << 1;

				} else if (R == c[4]) {
					cout << 4 << " " << 1;

				} else if (R == c[5]) {
					cout << 5 << " " << 1;

				} else if (R == c[6]) {
					cout << 5 << " " << 2;

				} else if (R == c[7]) {
					cout << 4 << " " << 2;

				} else if (R == c[8]) {
					cout << 3 << " " << 2;

				} else if (R == c[9]) {
					cout << 2 << " " << 2;

				} else if (R == c[10]) {
					cout << 1 << " " << 2;

				} else if (R == c[11]) {
					cout << 1 << " " << 3;

				} else if (R == c[12]) {
					cout << 2 << " " << 3;

				} else if (R == c[13]) {
					cout << 3 << " " << 3;

				} else if (R == c[14]) {
					cout << 4 << " " << 3;

				} else if (R == c[15]) {
					cout << 5 << " " << 3;

				} else if (R == c[16]) {
					cout << 5 << " " << 4;

				} else if (R == c[17]) {
					cout << 4 << " " << 4;

				} else if (R == c[18]) {
					cout << 3 << " " << 4;

				} else if (R == c[19]) {
					cout << 2 << " " << 4;

				} else if (R == c[20]) {
					cout << 1 << " " << 4;

				} else if (R == c[21]) {
					cout << 1 << " " << 5;

				} else if (R == c[22]) {
					cout << 2 << " " << 5;

				} else if (R == c[23]) {
					cout << 3 << " " << 5;

				} else if (R == c[24]) {
					cout << 4 << " " << 5;

				} else if (R == c[25]) {
					cout << 5 << " " << 5;

				} else if (R == c[26]) {
					cout << 5 << " " << 6;

				} else if (R == c[27]) {
					cout << 4 << " " << 6;

				} else if (R == c[28]) {
					cout << 3 << " " << 6;

				} else if (R == c[29]) {
					cout << 2 << " " << 6;

				} else if (R == c[30]) {
					cout << 1 << " " << 6;

				} else if (R == c[31]) {
					cout << 1 << " " << 7;

				} else if (R == c[32]) {
					cout << 2 << " " << 7;

				} else if (R == c[33]) {
					cout << 3 << " " << 7;

				} else if (R == c[34]) {
					cout << 4 << " " << 7;

				} else if (R == c[35]) {
					cout << 5 << " " << 7;

				} else if (R == c[36]) {
					cout << 5 << " " << 8;

				} else if (R == c[37]) {
					cout << 4 << " " << 8;

				} else if (R == c[38]) {
					cout << 3 << " " << 8;

				} else if (R == c[39]) {
					cout << 2 << " " << 8;

				} else if (R == c[40]) {
					cout << 1 << " " << 8;

				} else if (R == c[41]) {
					cout << 1 << " " << 9;

				} else if (R == c[42]) {
					cout << 2 << " " << 9;

				} else if (R == c[43]) {
					cout << 3 << " " << 9;

				} else if (R == c[44]) {
					cout << 4 << " " << 9;

				} else if (R == c[45]) {
					cout << 5 << " " << 9;

				} else if (R == c[46]) {
					cout << 5 << " " << 10;

				} else if (R == c[47]) {
					cout << 4 << " " << 10;

				} else if (R == c[48]) {
					cout << 3 << " " << 10;

				} else if (R == c[49]) {
					cout << 2 << " " << 10;

				} else if (R == c[40]) {
					cout << 1 << " " << 10;
				}
			}
		}
	}

	return 0;
}


