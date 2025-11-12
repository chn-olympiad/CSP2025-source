#include <bits/stdc++.h>
using namespace std;
long long q, n, ans;

struct ymz {
	int b1q;
	int b1h;
	int b1;
	int b2;
	int b2q;
	int b2h;
} a[200010];
string s1, s2;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);
	cin >> n >> q;
	for (int j = 0; j < n; j++) {
		cin >> s1 >> s2;
		if (s1 == s2)
			continue;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == 'b') {
				a[j].b1 = i;
				a[j].b1q = i - 1;
				a[j].b1h = s1.length() - i;
				break;
			}

		}
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] == 'b') {
				a[j].b2 = i;
				a[j].b2q = i - 1;
				a[j].b2h = s2.length() - i;
				break;
			}
		}
	}
	for (int j = 0; j < q; j++) {
		ans = 0;
		cin >> s1 >> s2;
		int x, y;
		for (int i = 0; i < s1.length(); i++) {
			if (s1[i] == 'b') {
				x = i;
				break;
			}

		}
		for (int i = 0; i < s2.length(); i++) {
			if (s2[i] == 'b') {
				y = i;
				break;
			}

		}
		for (int i = 0; i < n; i++) {
			if (x >= a[i].b1 && y >= a[i].b2) {
				if (s2.length() - y >= a[i].b2h && s1.length() - x >= a[i].b1h) {
					if (y - x == a[i].b2 - a[i].b1) {
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
