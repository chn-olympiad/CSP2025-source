#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
ll t[15];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	for (ll i = 0; i <= 10; i++)
		t[i] = 0;
	for (ll i = 0; i < s.size(); i++)
		if (s[i] >= '0' && s[i] <= '9')
			t[s[i] - '0']++;
	for (ll i = 9; i >= 0; i--)
		for (ll j = 1; j <= t[i]; j++)
			cout << i;
	cout << "\n";
	return 0;
}