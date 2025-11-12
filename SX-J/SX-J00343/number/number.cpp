#include <bits/stdc++.h>
using namespace std;
#define ll long long
string c;

int a[1000010];

bool cmp(ll a, ll b) {
	return a > b;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ll k = 0;
	cin >> c;
	for (int i = 0; i < c.size(); i++) {
		if (c[i] >= '0' && c[i] <= '9') {
			k++;
			a[k] = c[i] - '0';
		}
	}
	sort(a + 1, a + k + 1, cmp);
	for (int i = 1; i <= k; i++) {
		cout << a[i];
	}
	return 0;
}