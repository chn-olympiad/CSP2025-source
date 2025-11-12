#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

string a[100005], s;

bool cmp(string x, string y) {
	return x > y;
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);

	cin >> s;
	int c = s.size();
	int n = 1;
	for (int i = 0; i < c; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			a[n] = s[i];
			n++;
		}
	}
	sort(a + 1, a + n, cmp);
	for (int i = 1; i <= n ; i++) {
		cout << a[i];
	}

	return 0;
}
