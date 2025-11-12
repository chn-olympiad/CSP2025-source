#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[500010];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n, k, sum = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		ll v = 0;
		ll s = a[v + 1];
		for (int j = v + 2; k + i <= n && j <= v + i; j++) {
			s = s ^a[j];
		}
		if (s == k) {
			sum++;
		}
		v = v + i + 1;
	}
	cout << sum;
	return 0;
}