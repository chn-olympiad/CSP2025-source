#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6+10;
string x;
int s[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> x;
	for (int i = 0; i <= x.size() - 1; i++) {
		if (x[i] >= 'a' && x[i] <= 'z') {
			x[i] -= 'a';
		}
		x[i] -= '0';
	}
	for (int i = 0; i <= x.size() - 1; i++) {
		s[i] = x[i];
	}
	sort(s, s + x.size(), greater<int>());
	for (int i = 0; i <= x.size() - 1; i++) {
		if (s[i] >= 96 || s[i] < 0)
			continue;
		else
			cout << s[i];
	}
	return 0;
}