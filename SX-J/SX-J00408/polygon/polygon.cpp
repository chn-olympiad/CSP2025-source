#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fr(i,a,b) for(int i=a;i<=b;i++)
int a[5];

signed main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	fr(i, 1, 3) {
		cin >> a[i];
	}
	if (a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[3] + a[2] > a[1])
		cout << 1;
	else
		cout << 0;
	return 0;
}
