#include <bits/stdc++.h>
using namespace std;
string n;
int t = 0;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> n;
	int l[n.size() + 1];
	for (int i = 0; i < n.size(); i++) {
		if (n[i] >= '0' && n[i] <= '9') {
			if (n[i] == '0') {
				l[t] = 0;
			} else if (n[i] == '1') {
				l[t] = 1;
			} else if (n[i] == '2') {
				l[t] = 2;
			} else if (n[i] == '3') {
				l[t] = 3;
			} else if (n[i] == '4') {
				l[t] = 4;
			} else if (n[i] == '5') {
				l[t] = 5;
			} else if (n[i] == '6') {
				l[t] = 6;
			} else if (n[i] == '7') {
				l[t] = 7;
			} else if (n[i] == '8') {
				l[t] = 8;
			} else if (n[i] == '9') {
				l[t] = 9;
			}
			t++;
		}
	}
	sort(l, l + t - 1, greater<int>());
	for (int i = 0; i < t; i++) {
		cout << l[i];
	}
	return 0;
}
