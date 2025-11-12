#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100010];
signed main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int ws = a[1];
	sort(a + 1, a + n * m + 1);
	reverse(a + 1, a + n * m + 1);
	int i = 1, j = 1, k = 1;
	bool fk = 0;
	while(a[k] != ws) {
		if(!fk) {
			if(i == n) {
				j++;
				fk = !fk;
			} else {
				i++;
			}
		} else {
			if(i == 1) {
				j++;
				fk = !fk;
			} else {
				i--;
			}
		}
		k++;
	}
	cout << j << ' ' << i << endl;
	return 0;
}