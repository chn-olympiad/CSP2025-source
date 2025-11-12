#include <bits/stdc++.h>
using namespace std;
int t, n;
const int N = 1e5+10;
int a[N];

struct node {
	int a1, a2, a3;
} sum, num;

int fun(int a, int b, int c) {
	if ((a >= b && a >= c) && sum.a1 <= n / 2) {
		sum.a1++;
		return a;
	} else if (( b > a && b > c) && sum.a2 <= n / 2) {
		sum.a2++;
		return b;
	} else if ((c > a && c > b) && sum.a3 <= n / 2) {
		sum.a3++;
		return c;
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> num.a1 >> num.a2 >> num.a3;
			a[i] = fun(num.a1, num.a2, num.a3);

		}
		int ma = 0;
		for (int i = 1; i <= n; i++) {
			ma += a[i];
		}
		for (int i = 1; i <= n; i++) {
			a[i] = 0;
		}
		cout << ma << endl;
		sum.a1 = 0;
		sum.a2 = 0;
		sum.a3 = 0;

	}
	return 0;
}