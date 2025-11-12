#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define IOS ios::sync_with_stdio(false); \
cin.tie(0); \
cout.tie(0);
void fr() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
}
ll n, m, a[105], more = 1, op;
int main() {
	fr();
	IOS
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if (i != 1 && a[i] > a[1]) {
			more++;
		}
	} 
	for (int i = 1; i <= m; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j <= n; j++) {
				op++;
				if (op == more) {
					cout << i << " " << j;
					return 0;
				}
			}
		} else {
			for (int j = n; j >= 1; j--) {
				op++;
				if (op == more) {
					cout << i << " " << j;
					return 0;
				}
			}
		}
	}
//	cout << m << " " << n;
	return 0;
}

