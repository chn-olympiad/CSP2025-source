#include <bits/stdc++.h>
using namespace std;
int n, a, b, c;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	cin >> a >> b >> c;
	if (n >= 3 && a + b + c > 2 * max(a, max(b, c))) cout << 1;
	else cout << 0;
	return 0;
}
