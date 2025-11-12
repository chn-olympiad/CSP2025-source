#include<bits/stdc++.h>
using namespace std;
int b[1145];
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >> a;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			b[a[i] - '0'] ++;
		}
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 1; j <= b[i]; j++) {
			cout << i;
		}
	}
	
	
	
	return 0;
}
