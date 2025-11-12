#include <bits/stdc++.h>
using namespace std;
int n, m, c[505];
char s[505];
bool key[505];

int main() {
	freopen("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s + 1;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		if (c[i] == 0)
			n--;
	}
	int sum = 0;
	long long  ans = 1;
	for (int i = 0; i <= (n - 1); i++) {//for every desk
		for (int j = 1; j <= n; ++j) { //choose person
//			if c[i]
//			}
			if (c[i] <= sum) {

			}
//			printf("%ld*%d\n", ans, n - i);
			ans = ans * (n - i);

		}
	}

	//A test point all s=1
	printf("%lld", ans);
	return 0;
}
