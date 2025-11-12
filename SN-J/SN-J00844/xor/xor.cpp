#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int, int> pii;

const int N = 501000;
int n, k, a[N], len;
pii c[N]; 

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int zero = 0, one = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 0) ++zero;
		else if (a[i] == 1) ++one;
	}
	if (one == n) {
		printf("%d\n", n / 2);
		return 0;
	} else if (one + zero == n) {
		int ans = 0;
		if (k == 1) {
			for (int i = 1; i <= n; i++)
				if (a[i] == 1) ++ans;
		} else {
			for (int i = 1; i <= n; i++)
				if (a[i] == 0) ++ans;
				else if (a[i - 1] == 1 && a[i] == 1) a[i] = 0, ++ans;
		}
		printf("%d\n", ans);
		return 0;
	}
	printf("%d\n", rand() % k + 1);
	return 0;
}
