#include<bits/stdc++.h>
using namespace std;
int n, m, a[110], ans = 1, c, r, p;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	for (int i = 2; i <= n * m; i ++){
		cin >> a[i];
		if (a[i] > a[1])ans ++; 
	}
	c = ans / n;
	p = ans % n;
	if (p != 0) c ++;
	else p = n;
	if (c % 2 == 0)r = n - p + 1;
	else r = p;
	cout << c << ' ' << r;
	return 0;
}
