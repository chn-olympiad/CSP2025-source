#include <bits/stdc++.h>

using namespace std;

const int N = 500011;
int n, k, a[N], s[N];
pair<int, int> p[N];

inline bool cmp(const pair<int, int> &x, const pair<int, int> &y) {
	if (x.first != y.first)
		return x.first < y.first;
	return x.second < y.second;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (n <= 100) {	
		int pos = 0;
		for (int l = 1; l <= n; l++)
			for (int r = l; r <= n; r++) {
				int v = 0;
				for (int i = l; i <= r; i++)
					v ^= a[i];
				if (v == k) {
					pos++;
					p[pos].first = l, p[pos].second = r;
				}
			}
		
		sort(p + 1, p + pos + 1, cmp);
		int ans = 0, x = 0;
		for (int i = 1; i <= pos; i++)
			if (p[i].first > x) {
				x = p[i].second;
				++ans;
			}
		printf("%d\n", ans);
		return 0;
	}
	memset(s, 0, sizeof(s));
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] ^ a[i];
	int pos = 0;
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			int y = s[r] ^ s[l - 1];
			if (y != k)
				continue;
			pos++;
			p[pos].first = l, p[pos].second = r;
		}
	}
	sort(p + 1, p + pos + 1, cmp);
	int x = 0;
	long long ans = 0;
	for (int i = 1; i <= pos; i++)
		if (p[i].first > x) {
			ans++;
			x = p[i].second;
		}
	printf("%d\n", ans);
	return 0;
}
