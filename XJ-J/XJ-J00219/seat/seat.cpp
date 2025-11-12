#include<bits/stdc++.h>
using namespace std;
long long int i, a[105], n, m, x, y;
int main () {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (i = 1; i <= n * m; i ++) {
		cin >> a[i];
		if (i == 1)
			x = a[i];
	}
	i = 1; 
	while (a[i] == i) {
		i ++;
	}
	if(i > n * m) {
		cout << m << " " << n;
	}
	else {
		cout << 1 << " " << 1;
	}
	return 0;
}
