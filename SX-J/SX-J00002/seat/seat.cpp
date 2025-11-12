#include <bits/stdc++.h>
using namespace std;
int n, m, a[105], i,c,r;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (i = 1; i <= (n * m); i++) {
		cin >> a[i];	
	}
	if(i==1){
			c=1;
			r=1;
			cout<<c<<r;
	}
	return 0;
}