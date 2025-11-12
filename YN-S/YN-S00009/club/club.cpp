//by hty
//CSP-S T1 2025-11-01 14:10
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int T;
int hty1[N], hty2[N], hty3[N];
int max1, max2, max3;
struct dio {
	bool falg;
	int num;
} b[3];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		int n = 0, sum = 0;
		cin >> n;
		int ans = n / 2;
		for (int i = 0; i < n; i++) {
			cin >> hty1[i] >> hty2[i] >> hty3[i];
		}
		sort(hty1, hty1 + n, cmp);
		sort(hty2, hty2 + n, cmp);
		sort(hty3, hty3 + n, cmp);
		for (int i = 0; i < n; i++) {
			max1 = max(hty1[i], max1);
			max2 = max(hty2[i], max2);
			max3 = max(hty3[i], max3);
		}
		sum += max1;
		b[1].num++;
		sum += max2;
		b[2].num++;
		sum += max3;
		b[3].num++;
		for (int i = 0; i < n; i++) {
			if (b[1].num == ans) {
				b[1].falg = true;
			}
			if (b[1].num == ans) {
				b[1].falg = true;
			}
			if (b[1].num == ans) {
				b[1].falg = true;
			}
		}
		cout << sum << endl;
	}
	return 0;
}