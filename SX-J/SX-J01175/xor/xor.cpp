#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, x;
string arr[500005], k, now[500005];
bool book[500005];
bool teA = 1;

string ttt(int m) {
	if (!m)
		return "0";
	string s = "";
	char c;
	while (m) {
		c = (m % 2 + '0');
		s = c + s;
		m /= 2;
	}
	return s;
}

string newxor(string a, string b) {
	if (a == b)
		return "0";
	string ans = "";
	char c;
	bool qian = 1;
	int ai;
	if (a.size() > b.size()) {
		swap(a, b);
	}
	for (size_t i = 0; i < b.size(); i++) {
		ai = i - b.size() + a.size();
		if (ai < 0) {
			c = (b[i] == '1') + '0';
		} else {
			c = (b[i] != a[ai]) + '0';
		}
		if (c == '0' && qian) {
			continue;
		} else {
			qian = 0;
			ans += c;
		}
	}
	return ans;
}

bool check(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (book[i] == 1) {
			return false;
		}
	}
	return true;
}

int cnt() {
	int lastans = 0;
	for (int i = 1; i <= n; i++) {
		now[i] = arr[i];
		if (now[i] == k) {
			lastans++;
			book[i] = 1;
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			now[j] = newxor(arr[j - i + 1], now[j]);
			if (now[j] == k && check(j - i + 1, j)) {
				lastans++;
				for (int o = j - i + 1; o <= j; o++) {
					book[o] = 1;
				}
			}
		}
	}
	return lastans;
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> x;
	k = ttt(x);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x != 1)
			teA = 0;
		arr[i] = ttt(x);
	}
	if (teA) {
		cout << n / 2;
		return 0;
	}
	cout << cnt();
	return 0;
}
