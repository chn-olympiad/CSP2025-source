#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a, b, c, t = 0;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	cin >> a >> b >> c;
	if (a + b > c)
		t++;
	if (a + c > b)
		t++;
	if (b + c > a)
		t++;
	cout << t;
	return 0;
}
