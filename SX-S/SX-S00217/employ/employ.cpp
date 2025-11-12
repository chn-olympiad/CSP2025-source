#include <bits/stdc++.h>
using namespace std;
int c[100010], t[100010];
bool l[100010];

int main() {
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	long long n, m, x = l;
	string a;
	cin >> n >> m >> a;
	for (int i = 1; i < n; i++) {
		t[i] = a[i] - '0';
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		if (c[i] == 0) {
			n--;
		}
	}
	for (int i = 0; i <= n; i++) {
		x = n * (n - 1) / 2;
	}
	cout << x % 99824353 << endl;
	return 0;
}
