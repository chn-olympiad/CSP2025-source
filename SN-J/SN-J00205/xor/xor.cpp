#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k;
int a[N];
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	int fa = 1, fb = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) fa = 0;
		if (a[i] > 1) fb = 0;
	}
	if (fa == 1) {
		cout << n;
	} else if (fb == 1) {
		int cnta = 0, cntb = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == 1) {
				cnta++;
			} else cntb++;
		}
		if (k == 1) cout << cnta;
		else cout << cnta / 2 + cntb;
	}
	return 0;
}

