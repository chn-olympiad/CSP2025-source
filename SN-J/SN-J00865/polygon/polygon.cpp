//SN-J00865 程越萱 西安滨河学校 
#include <bits/stdc++.h>
using namespace std;
long long n, a[5005], b[5005], cnt;
int main () {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i]+b[i-1];
	}
	sort (a+1, a+1+n);
	for (long long i = 1; i <= n-2; i++) {
		for (long long j = i+2; j <= n; j++) {
			long long t = a[j];
			if (b[j]-b[i-1] > t*2) {
				cout << i << ' ' << j << '\n';
				cnt++;
			}
		}
	}
	cout << cnt%998244353;
	return 0;
}
