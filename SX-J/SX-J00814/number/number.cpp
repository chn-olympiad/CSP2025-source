#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll a[110];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - '0';
		if (num >= 0 && num <= 9) {
			a[num]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
