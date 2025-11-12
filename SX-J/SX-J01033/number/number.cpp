#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
string a;
ll b[1000000];

int main() {
	fast;
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> a;
	int as = a.size();
	int w = 0;
	int p = 0;
	for (int i = 0; i < as; i++) {
		if (a[i] >= '0' && a[i] <= '9') {
			if (a[i] != '0') {
				p = 1;
			}
			b[w] = a[i] - '0';
			w++;
		}
	}
	if (p == 0) {
		cout << "0";
		return 0;
	}
	sort(b, b + w);
	for (int i = w - 1; i >= 0; i--) {
		cout << b[i];
	}
	return 0;
}
