#include <bits/stdc++.h>
using namespace std;
long long n, m, a1, c = 1, r = 1, ans = 0, sum, a[105];
bool flag = 0;

bool cmp(long long _a, long long _b) {
	return _a > _b
	       ;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m >> a1;
	sum = n * m;
	for (int i = 1; i < sum; i++)
		cin >> a[i];
	sort(a + 1, a + sum, cmp);
	while (ans < sum) {
		ans++;
		if (a[ans] < a1) {
			cout << c << " " << r;
			return 0;
		}
		if (flag == 0) {
			if (r == n)
				flag = 1, c++;
			else
				r++;
		} else {
			if (r == 1)
				flag = 0, c++;
			else
				r--;
		}
	}
	return 0;
}
