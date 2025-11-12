#include <bits/stdc++.h>
#define ll long long
#define st string
using namespace std;
st s;
ll a[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	ll n = s.size(), t = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - '0']++;
		}
	}
	for (int i = 10; i >= 0; i--) {
		for (int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	return 0;
}
