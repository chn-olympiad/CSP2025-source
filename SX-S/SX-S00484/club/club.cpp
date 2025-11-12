#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 1e5+10;
const int INF = 1e9+10;
int a[N][5];
int b1[N];
int num1[N];

int cmp(int aa, int bb) {
	return aa > bb;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int num = 0;
		int n;
		cin >> n;
		int ok1 = 0, ok3 = 0;
		int sss = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 3; j++) {
				cin >> a[i][j];

			}
			if (a[i][3] != 0) {
				sss = 1;
			}
			b1[i] = a[i][2];
			if (a[i][1] != 0) {
				ok1 = 1;
			}
			if (a[i][3] != 0) {
				ok3 = 1;
			}
		}
		//–‘÷ A
		if (ok1 == 0 && ok3 == 0) {
			sort(b1 + 1, b1 + n + 1, cmp);
			for (int i = 1; i <= n / 2; i++) {
				num += b1[i];
			}
			cout << num;
			continue;
		}
		//n=2
		if (n == 2) {
			int q1 = a[1][1] + a[2][2];
			int q2 = a[1][1] + a[2][3];
			int q3 = a[1][2] + a[2][1];
			int q4 = a[1][2] + a[2][3];
			int q5 = a[1][3] + a[2][1];
			int q6 = a[1][3] + a[2][2];
			int mx1 = 0;
			mx1 = max(mx1, q1);
			mx1 = max(mx1, q2);
			mx1 = max(mx1, q3);
			mx1 = max(mx1, q4);
			mx1 = max(mx1, q5);
			mx1 = max(mx1, q6);
			cout << mx1;
			continue;
		}

		//B

		int qq1 = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 2; j++) {
				for (int q = i + 1; q <= n; q++) {
					for (int w = 1; w <= 2; w++) {
						num1[qq1] = a[i][j] + a[q][w];
					}
				}
			}
		}
		sort(num1 + 1, num1 + qq1, cmp);
		cout << num1[1] + num1[2];
		continue;



	}
	return 0;
}
