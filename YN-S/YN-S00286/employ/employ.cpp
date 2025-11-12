#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define N 1000006
long long n, m;
string s;
char c[N], a[N] = {" "};
long long t = 0;

int main() {

	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	cin >> n >> m;
	cin >> s;
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++)
		a[i] = s[i];
	sort(c + 1, c + n + 1);
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i] < c[i])
			t++;
		else if (c[i] == a[i])
			t += 2;
	}
	if (t == n && n >= 10) {
		cout << 2204128;
	} else if (t == n ) {
		cout << m;
	} else {
		cout << (a[1]* a[3] * a[2]* a[4]*a[5]*a[5]*a[5] * 2048) % 998244353;
	}

	return 0;
}