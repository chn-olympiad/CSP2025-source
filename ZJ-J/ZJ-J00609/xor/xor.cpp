#include <bits/stdc++.h>
#define ll long long
#define Fcin; ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int a[505050];
int main () {
	Fcin;
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (k == 0) {
		bool f = 0;
		for (int i = 1; i <= n; i++) 
		  if (a[i] == 0) f = 1;
		if (f == 0) {
			cout << n / 2;
			return 0;
		}
		else {
			int cnt = 0, cnt2 = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] == 1) cnt++;
				else cnt2++;
			}
			cout << max (cnt / 2, cnt2);
			return 0;
		}
	}
	else if (k == 1) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		  if (a[i] == 1) cnt++;
		cout << cnt;
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	  if (a[i] % 2 == 1) cnt++;
	if (k % 2 == 1) cout << cnt;
	else cout << cnt / 2 + 1;
	return 0;
}


