#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
using namespace std;
int n, a, b, c;

int main() {
	fast;
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	cin >> a >> b >> c;
	if (a + b > c && a + c > b && b + c > a) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
