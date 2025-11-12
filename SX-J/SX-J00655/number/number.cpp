#include <bits/stdc++.h>
using namespace std;
string s;
char ch[1000];
int a[1000], n;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		s[i] = ch[i];
	}
	for (int i = 0; i < n; i++) {
		if (32 <= int(ch[i]) <= 54) {
			ch[i] = a[i];
		}
	}
	cout << a[1000];
	return 0;
}
