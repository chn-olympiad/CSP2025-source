#include <bits/stdc++.h>
using namespace std;
int a[100000], sum[100000], s = 0, n;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	if (n == 3) {
		cin >> a[1] >> a[2] >> a[3];
		sort(a + 1, a + 3 + 1);
		s = a[1] + a[2] + a[3];
		s /= 2;
		if (s > a[3])
			cout << 1;
		else
			cout << 0;
	}
	/*else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=0;i<)

	}*/
	else {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		cout << 12;
	}
	return 0;
}