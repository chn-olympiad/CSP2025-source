#include <iostream>
#include <cstdio>
using namespace std;

int n, k, a[500005], one, zero;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1;i <= n;i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1) one++;
		else if (a[i] == 0) zero++;
	}
	
	if (k > 1) {
		cout << n;
	}
	if (k == 1) {
		cout << one;
	} 
	if (k == 0) {
		int ans = zero;
		for (int i = 1;i < n;i++) {
			if (a[i] == 1 && a[i+1] == 1) {
				ans++, i++;
			}
		}
		cout << ans;
	}
	return 0;
}
