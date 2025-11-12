#include <bits/stdc++.h>
using namespace std;

struct stu {
	int a1, a2, a3, mu;
};
const int maxn = 1e5 + 10;
stu s[maxn];
int hg[maxn];

bool cmp(stu s1, stu s2) {
	if (s1.mu > s2.mu)
		return true;
	else
		return false;
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while (t--) {
		int n, maxm = -1, ans = 0, flagc = 1;
		cin >> n;
		int k = n / 2;
		for (int i = 1; i <= n; i++) {
			cin >> s[i].a1 >> s[i].a2 >> s[i].a3;
			if (s[i].a2 != 0 || s[i].a3 != 0)
				flagc = 0;
			s[i].mu = max(s[i].a1, max(s[i].a2, s[i].a3));
			hg[s[i].a1]++;
			maxm = max(maxm, s[i].a1);
		}
		if (flagc == 1) {
			for (int j = maxm;; j--) {
				if (k > hg[j]) {
					ans += hg[j] * j;
					k -= hg[j];
				} else if (k > 0) {
					ans += j * k;
					k = 0;
					break;
				}
			}
			cout << ans << "\n";
			continue;
		}

		sort(s + 1, s + n + 1, cmp);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for (int i = 1; i <= n; i++) {
			if (s[i].mu == s[i].a1 && cnt1 < k) {
				cnt1++;
				ans += s[i].mu;
			} else if (s[i].mu == s[i].a2 && cnt2 < k) {
				cnt2++;
				ans += s[i].mu;
			} else if (s[i].mu == s[i].a3 && cnt3 < k) {
				cnt3++;
				ans += s[i].mu;
			} else if (s[i].mu == s[i].a3 && cnt3 >= k) {
				if (s[i].a1 >= s[i].a2 && cnt1 < k) {
					cnt1++;
					ans += s[i].a1;
					continue;
				}
				if (cnt2 < k) {
					cnt2++;
					ans += s[i].a2;
				}

			} else if (s[i].mu == s[i].a2 && cnt2 >= k) {
				if (s[i].a1 >= s[i].a3 && cnt1 < k) {
					cnt1++;
					ans += s[i].a1;
					continue;
				}
				if (cnt3 < k) {
					cnt3++;
					ans += s[i].a3;
				}
			} else if (s[i].mu == s[i].a1 && cnt1 >= k) {
				if (s[i].a3 >= s[i].a2 && cnt3 < k) {
					cnt3++;
					ans += s[i].a3;
					continue;
				}
				if (cnt2 < k) {
					cnt2++;
					ans += s[i].a2;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}