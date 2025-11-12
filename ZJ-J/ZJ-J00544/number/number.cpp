#include <bits/stdc++.h>

using namespace std;

string s;
int a[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[s[i] - 48]++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < a[i]; j++) cout << i;
	}
	
	return 0;
}
