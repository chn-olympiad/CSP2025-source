#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t;
int n, a[100010][5];
int f[2][110][110][110];
struct node {
	int a1, a2, a3;
} ppp[100010];
bool cmp(node aaa, node bbb) {
	return aaa.a1 > bbb.a1;
}
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			ppp[i].a1 = a[i][1];
			ppp[i].a2 = a[i][2];
			ppp[i].a3 = a[i][3];
		}
		if (n >= 200) {
			sort(ppp + 1, ppp + n + 1, cmp);
			int ans = 0;
			for (int i = 1; i <= n / 2; i++) {
				ans += a[i][1];
			}
			cout << ans;
			continue;
		}
		for (int x = 0; x <= n / 2; x++) {
			for (int y = 0; y <= n / 2; y++) {
				for (int z = 0; z <= n / 2; z++) {
					f[0][x][y][z] = 0;
					f[1][x][y][z] = 0;
				}
			}
		}
		f[1][1][0][0] = a[1][1];
		f[1][0][1][0] = a[1][2];
		f[1][0][0][1] = a[1][3];
		int ans = 0;
		for (int i = 2; i <= n; i++) {
			for (int x = 0; x <= n / 2; x++) {
				for (int y = 0; y <= n / 2; y++) {
					for (int z = 0; z <= n / 2; z++) {
//						cout << "S";
						if (x >= 1) {
							f[i % 2][x][y][z] = max(f[i % 2][x][y][z], f[1 - i % 2][x - 1][y][z] + a[i][1]);
//							cout << "A";
						}
						if (y >= 1) {
							f[i % 2][x][y][z] = max(f[i % 2][x][y][z], f[1 - i % 2][x][y - 1][z] + a[i][2]);
//							cout << "B";
						}
						if (z >= 1) {
							f[i % 2][x][y][z] = max(f[i % 2][x][y][z], f[1 - i % 2][x][y][z - 1] + a[i][3]);
//							cout << "C";
						}
						ans = max(ans, f[i % 2][x][y][z]);
					}
				}
			}
		}
		cout << ans << "\n";
//		cout << "\n";
//		for (int i = 1; i <= n; i++) {
//			for (int x = 0; x <= n / 2 + 1; x++) {
//				for (int y = 0; y <= n / 2 + 1; y++) {
//					for (int z = 0; z <= n / 2 + 1; z++) {
//						cout << f[i][x][y][z] << " ";
//					}
//					cout << "\n";
//				}
//			}
//		}
	}
	return 0;
}
