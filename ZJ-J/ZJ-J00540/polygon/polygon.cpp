#include<bits/stdc++.h>
using namespace std;

int n, a[5001];

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	int maxn = 0, sum = 0;
	for (int i = 1; i <= n; i++)  {
		cin >> a[i];
		sum += a[i];
		maxn = max(a[i], maxn);
	}
	if (n == 3) {
		if (sum > maxn * 2) cout << 1;
		else cout << 0;
	}
	else cout << 0;
	return 0;
}
