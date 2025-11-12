#include <bits/stdc++.h>
using namespace std;
int T, n, like[10010][4], biao[10010][4];
int m[10010][4], k[10], bigggm, killl;

int main() {
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> like[i][1] >> like[i][2] >> like[i][3];
		}
		for (int o = 1; o <= 3; o++) {
			for (int i = 1; i <= n / 2; i++) {
				for (int j = 1; j <= n; j++) {
					bigggm = m[i][o];
					m[i][o] = max(m[i - 1][o] + like[j][o], m[i][o]);
					if (bigggm != m[i][o]) {
						killl = j;
					}
				}
				like[killl][o] = 0;
			}
			k[T] += m[n / 2][o];
			killl = 0;
			for (int i = 1; i <= n; i++) {
				m[i][1] = 0;
				m[i][2] = 0;
				m[i][3] = 0;
				bigggm = 0;
			}
		}
		for (int i = 1; i <= n; i++) {
			like[i][1] = 0;
			like[i][2] = 0;
			like[i][3] = 0;
		}
		cout << k[T];
	}
	return 0;
}