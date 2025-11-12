#include <bits/stdc++.h>
using namespace std;
int a[600];
int n , m;
void f(int x) {
	int b = (x - 1) / n + 1;
	x -= (b - 1) * n;
	int a;
	if(b % 2 == 1)
		a = x;
	else 
		a = n - x + 1;
	cout << b << " " << a;
}
int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	int x = 0;
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) {
		cin >> a[i];
		if(a[i] >= a[1])x++;
	}
	f(x);
	return 0;
}
