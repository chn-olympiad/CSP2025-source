#include<bits/stdc++.h>

using namespace std;

int a[10] { 0 };

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (char i : s) {
		if ('0' <= i && i <= '9') {
			a[i - '0']++;
		}
	}
	for(int i = 9; i > -1; i --) {
		while (a[i]) {
			a[i]--;
			cout << i;
		}
	}
}
