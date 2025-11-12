#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int N = 1e5+10;
int a[N];
bool st[N];

int cmp(int aa, int b) {
	return aa > b;
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	memset(st, true, sizeof st);
	int n, k;
	cin >> n >> k;
	int num1 = 0;
	int num0 = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] == 1) {
			num1++;
		}
		if (a[i] == 0) {
			num0++;
		}
	}
	int s = 0;
	if (k == 1) {
		for (int i = 2; i <= n; i++) {
			if (a[i] == 0 && a[i - 1] == 1 && st[i] == true && st[i - 1] == true) {
				st[i] = st[i - 1] = false;
				num1--;
				s++;
			}
			if (a[i] == 1 && a[i - 1] == 0 && st[i] == true && st[i - 1] == true) {
				st[i] = st[i - 1] = false;
				num1--;
				s++;
			}
		}
		cout << s + num1;
		return 0;
	} else if (k == 0) {
		cout << num0 << endl;
		for (int i = 2; i <= n; i++) {
			if (a[i] == 1 && a[i - 1] == 1 && st[i] == true && st[i - 1] == true) {
				s++;
				st[i] = st[i - 1] = false;
			}
		}
		cout << s + num0;
		return 0;
	}
	cout << 1;
	return 0;
}
