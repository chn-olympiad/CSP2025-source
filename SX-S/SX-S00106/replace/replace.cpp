#include <bits/stdc++.h>
using namespace std;
long long n, m, ans;
int a[10086], b[10086], c[10086], d[10086];
string s1, s2, s4, s[10086], s3[10086], s5;
bool f = true;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> s[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> s3[i];
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j += 2) {
			s1 = s[j];
			s2 = s3[j];
			s4 = s[j + 1];
			s5 = s3[j + 1];
			a[s1[j]]++;
			b[s2[j]]++;
			c[s4[j]]++;
			d[s5[j]]++;
		}

		for (int j = 1; j <= n; j++) {
			if (a[j] != b[j] && c[j] != d[j]) {
				cout << 0 << endl;
				f = false;
				break;
			} else if (a[j] != b[j] || c[j] != d[j]) {
				ans++;
				f = false;
				break;
			}
		}
		if (f)
			ans += 2;
		cout << ans << endl;
		ans = 0;
		s1 = "";
		s2 = "";
		s4 = "";
		s5 = "";
		f = true;
	}
	return 0;
}

