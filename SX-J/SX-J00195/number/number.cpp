#include <bits/stdc++.h>
using namespace std;
string s;
string a;

bool cmp(int x, int y) {
	return x > y;
}
string maxx;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	int lens = s.size();
	for (int i = 0; i <= lens - 1 ; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[i] = s[i];
		}
	}
	for (int i = 0; i <= lens - 1; i++) {
		for (int j = 0; j <= lens - 1 ; j++) {
			if (maxx[i] <= a[j]) {
				maxx[i] = a[j];
			}
		}
		if (maxx[i] >= '0' && maxx[i] <= '9') {
			cout << maxx[i] ;
			a[i] = -2;
			maxx[i] = -1;
		}
	}
	return 0;
}
