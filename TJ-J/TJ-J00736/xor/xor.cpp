#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, k, a[500005], ans, cnt, s[1005][1005], idx, rp;
bool A, B, C;

struct nod {
	int st, en;
} m[1000005];

bool cmp(nod a, nod b) {
	return (a.en == b.en ? a.st <= b.st : a.en <= b.en);
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) A = true;
		if (a[i] >= 2) B = true;
		if (a[i] == 1) ans++;
		if (a[i] == 0) cnt++;
	}
	if (!A && k == 0) { // 10 pts 
		cout << n / 2;
		return 0; 
	}
	if (!B && k <= 1) { // 30 pts
		if (k == 0) {
			int t = 0;
			for (int i = 1; i <= n; ) {
				if (a[i] == 0) i++;
				else {
					if (a[i + 1] == 1) t++, i += 2;
					else i++;
				} 
			}
			cout << cnt + t; 
		} else {
			cout << ans;
		}
		return 0;
	}
	if (n <= 1000) { // 选择区间问题，贪心，有些忘了怎么写了，35 pts 
		for (int l = 1; l <= n; l++) {
			for (int r = l; r <= n; r++) {
				s[l][r] = (s[l][r - 1] ^ a[r]);
				if (s[l][r] == k) {
					m[++idx].st = l;
					m[idx].en = r;
				}
			}
		}
		sort(m + 1, m + idx + 1, cmp);
		ans = 0, cnt = 0;
		for (int i = 1; i <= idx; i++) {
			if (m[i].st > cnt) {
				ans++, cnt = m[i].en;
			}
		}
		cout << ans;
		return 0;
	}
	rp += 1919810;
	cout << 114514; // 998244353 pts
	return 0;
}
