#include <bits/stdc++.h>
using namespace std;
long long n, m, maxs = -1, als, ans;
long long a[500005];

struct zzz {
	long long begin, end;
} s[500005];

bool p(zzz x, zzz y) {
	if (x.end == y.end)
		return x.begin > y.begin;
	return x.end < y.end;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		long long sum = a[i];
		if (a[i] == m) {
			als++;
			s[als].begin = i;
			s[als].end = i;
			continue;
		}
		for (int j = i + 1; j <= n; j++) {
			if (i >= s[als].begin && i <= s[als].end && j > s[als].end)
				break;
			sum = sum xor a[j];
			if (sum == m) {
				als++;
				s[als].begin = i;
				s[als].end = j;
			}
		}
	}
	sort(s + 1, s + als + 1, p);
	long long start = 0;
	for (int i = 1; i <= als; i++) {
		if (s[i].begin > start) {
			ans++;
			start = s[i].end;
		}
	}
	cout << ans;
	return 0;
}
