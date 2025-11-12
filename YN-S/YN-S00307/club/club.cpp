#include <bits/stdc++.h>
using namespace std;
long long ans[3 + 1];

long long mmax = -1, sum = 0;

struct s {
	int a;
	int b;
	int c;
};

bool cmp(s m, s n) {
	return m.a > n.a;
}
s arr[10000 + 5];
bool aa[10000 + 5];

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	cin >> T;
	while (T--) {
		int n;
		bool flag = true;
		cin >> n;
		for (int i = 1; i <= 3; i++) {
			ans[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			cin >> arr[i].a >> arr[i].b >> arr[i].c;
			if (arr[i].b != 0) {
				flag = false;
			}
		}
		if (flag) {
			sort(arr + 1, arr + 1 + n, cmp);
			for (int i = 1; i <= n / 2; i++) {
				ans[1] = ans[1] + arr[i].a;
			}
			cout << ans[1] + ans[2] + ans[3] << endl;
		} else if (n == 2) {
			int mmax = -1;
			int a1 = arr[1].a + arr[2].b;
			int a2 = arr[1].a + arr[2].c;
			int a3 = arr[1].b + arr[2].c;
			int a4 = arr[2].a + arr[1].b;
			int a5 = arr[2].a + arr[1].c;
			int a6 = arr[2].b + arr[1].c;
			mmax = max(mmax, max(a1, max(a2, max(a3, max(a4, max(a5, a6))))));
			cout << mmax << endl;
		}

	}
	return 0;
}