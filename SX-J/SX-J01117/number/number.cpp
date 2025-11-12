#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+50;
int s[N];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	int l = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			s[l] = a[i] - '0';
			l++;
		}
	}
	sort(s, s + l );
	for (int i = l - 1 ; i >= 0; i--) {
		cout << s[i];
	}

}
