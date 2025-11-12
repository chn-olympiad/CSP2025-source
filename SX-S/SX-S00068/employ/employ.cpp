#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
}

int n, m, a[505], ae = 1, cnt = 0, c[505], no, p[505];

int main() {
	file();
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%1d", a + i);
		if (!a[i])
			ae = 0;
		else
			cnt++;
	}
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		cin >> c[i];
		if (!c[i])
			no++;
	}
	int jiec = 1;
	for (int i = 1; i <= n; i++)
		jiec = jiec * i % 998244353;
	if (m == n) {
		if (ae && !no)
			cout << jiec;
		else
			cout << 0;
	} else if (m > min(cnt, n - no))
		cout << 0;
	else {
		long long res = 0;
		do {
			int giveup = 0;
			for (int i = 1; i <= n; i++)
				if (!a[i] || giveup >= c[p[i]])
					giveup++;
			if (n - giveup >= m)
				res++;
		} while (next_permutation(p + 1, p + n + 1));
		cout << res;
	}
	return 0;
}
