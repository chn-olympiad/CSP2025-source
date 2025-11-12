#include <bits/stdc++.h>
using namespace std;
int n, m, c, r;
int a[105], s[105];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> a[i];
	}
	int q=a[1];
	sort(a,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		s[i]=a[i];
	}
	c=q/n;
	if(c>)
	return 0;
}


