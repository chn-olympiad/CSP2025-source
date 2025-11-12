#include<bits/stdc++.h>
using namespace std;
int a[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int m, n, i, R, ans;
	cin>>n>>m>>R;
	a[R]++;
	for (int l = 1; l < n*m; l++) {
		cin>>i;
		a[i]++;
	}
	for (int l = 100; l >= R; l--) {
		ans+=a[l];
	}
	int c, r;
	if (ans % n) {
		c = ans/n+1;
		if (c%2) 
			r = ans % n;
		else r = n+1 - ans % n;
	}
	else {
		c = ans/n;
		if (c%2) 
			r = n;
		else r = 1;
	}
	cout<<c<<' '<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
