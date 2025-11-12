#include <bits/stdc++.h>
bool cmp(int a, int b) {
	return a > b ;
}
int main(){
	freopen("seat.in", "r", stdin) ;
	freopen("seat.out", "w", stdout) ;
	int a[10000], m, n, b ;
	int x = 0 , y = 0 ;
	std::cin >> n >> m ;
	for (int i = 0 ; i < n * m ; i ++) {
		std::cin >> a[i] ;
	}
	b = a[0] ;
	std::sort(a, a + n * m, cmp) ;
	for (int i = 0 ; i < n * m ; i ++) {
		if (a[i] == b) {
			b = i + 1 ;
		}	
	}
	if (b % n == 0) {
		x = b / n ;
		if ((b / n) % 2 == 0) {
			y = 1 ;
		}
		else {
			y = n ;
		}
	}
	else {
		x = b / n + 1 ;
		if ((b / n) % 2 == 0) {
			y = b % n ;
		}
		else {
			y = n - b % n + 1 ;
		}
	}
	std::cout << x<< " " << y ;
	return 0 ;
}
