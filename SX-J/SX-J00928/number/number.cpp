#include <bits/stdc++.h>
using namespace std;
int n ;
int a[1000005];

int main() {
	string s;
	cin >> s >> n;
	for (int i = 0; i <= n; i++) {
		a[i]++;
	}
	if (a[i] == "0" && a[i] <= 9) {
		cout << a[i];
	}
	return 0;
}