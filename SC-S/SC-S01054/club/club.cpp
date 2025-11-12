#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[N][N];
long long b[N];
long long c[N];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long cnt = 0;
		long long cnt1 = 0;
		long long sum = 0;
		for (int i = 0;i < n;i++) {
			int a1,a2,a3;
			cin >> a1 >> a2 >> a3;
			a[i + 1][1] = a1;
			a[i + 1][2] = a2;
			a[i + 1][3] = a3;
			if (a3 == 0) {
				cnt++;
			} else if (a1 = 0 && a3 == 0) {
				cnt1++;
			}
		}
		int x = n / 2;
		int y = x;
		if (cnt == n) {
			for (int i = 1;i <= n;i++) {
				b[i] = a[i][1];
				c[i] = a[i][2];
			}
			while(x--) {
				int ma = 0;
				int ma1 = 0;
				int num,num1;
				for (int i = 1;i <= n;i++) {
					if (b[i] > ma) {
						ma = b[i];
						num = i;
					}else if (c[i] > ma1) {
						ma1 = c[i];
						num1 = i;
					}
				}
				b[num] = 0;
				b[num1] = 0;
				sum += ma;
				sum += ma1;
			}
		}else if (cnt1 == n) {
			for (int i = 1;i <= n;i++) {
				b[i] = a[i][2];
			}
			while (x--) {
				int ma = 0;
				int num;
				for (int i = 1;i <= n;i++) {
					if (b[i] > ma) {
						ma = b[i];
						int num = i;
					}
				}
				b[num] = 0;
				sum += ma;
			}
		}else {
			if (n == 2) {
				int ma = 0;
				int ma1 = 0;
				int ma2 = 0;
				int num1,num2;
				for (int j = 1;j <= 3;j++) {
					if (a[1][j] > ma) {
						ma = a[1][j];
						num1 = j;
					}
					if (a[2][j] > ma1) {
						ma1 = a[2][j];
						num2 = j;
					}
				}
				if (num1 != num2) {
					sum = ma + ma1;
				}else {
					for (int j = 1;j <= 3;j++) {
						if (a[1][j] > ma2) {
							ma2 = a[1][j];
						} else if (a[2][j] > ma2) {
							ma2 = a[2][j];
						}
					}
					int w = max(ma,ma1);
					sum = w + ma2;
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}