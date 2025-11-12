#include <bits/stdc++.h>
using namespace std;
int n, m;
bool A;
bool book[505];
int num[505];
long long ans;
int c[505];
string s;

void dfs(int x) {
	if (x < n) {
		//	for(int j = 1;j<=n)
		int sum1 = 0, sum2 = 0;;
		for (int j = 1; j <= n; j++) {
			if (s[j - 1] == 1) {
				sum1++;
			} else {
				if (c[num[j]] > sum1) {
					sum2++;
				}
			}
		}
		if (sum2 >= m) {
			ans++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (book[i])
			continue;
		num[i] = x;
		book[i] = 1;
		dfs(x + 1);
		book[i] = 0;
	}
}

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '1')
			A = 1;
	}
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	if (!A) {
		cout << 0;
	} else if (m == 1) {
		//	cout << 99999;
		int cnt = 0;
		int pl = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') {
				pl = i;
				break;
			}
		}
		//cout << pl;
		for (int i = 1; i <= n; i++) {
			if (c[i] > pl)
				cnt++;
		}
		ans = 1;
		for (int i = 1; i <= n - 1; i++) {
			ans *= i;
			ans %= 998244353;
		}
		ans *= cnt;
		ans %= 998244353;
		cout << ans;
	} else if (n == m) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				cout << 0;
				return 0;
			}
		}
		ans = 1;
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= 998244353;
		}
		cout << ans;
	} else {
		dfs(1);
		cout << ans;
	}
	return 0;
}
