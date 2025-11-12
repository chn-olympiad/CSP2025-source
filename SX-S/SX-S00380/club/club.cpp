#include <bits/stdc++.h>
using namespace std;
int T, sum, n;
const int N = 1e5+5;
int a[N], b[N], c[N];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 2) {
			for (int i = 0; i < n; i++) {
				cin >> a[i] >> b[i] >> c[i];
			}
			cout << max(max(max(max(max(a[0] + b[1], a[0] + c[1]), b[0] + c[1]), b[0] + a[1]), c[0] + a[1]), c[0] + b[1]) << endl;
		}
	}
	return 0;
}
//?是人我吃
//不是说很简单么。？