#include <bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6+10;

int a[N];

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	int ch = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[ch] = (int)s[i] - 48;
			ch++;
		}
	}
	sort(a, a + 1 + ch);
	for (int i = ch; i >= 1 ; i--) {
		cout << a[i];
	}

	/*
	string s;
	cin >> s;
	int weishu = -1;
	for (int i = 0; i < s.size(); i++) {
		int num;
		if (s[i] >= '0' && s[i] <= '9') {
			weishu++;
			num = (int)s[i] - 48;
			a[num]++;
		}
	}
	long long number = 0;
	for (int i = 9; i > 0;) {
		if (a[i] > 0) {
			number += i * pow(10, weishu);
			weishu--;
			a[i]--;
		} else {
			i--;
		}
	}
	cout << number;
	*/
	return 0;
}
