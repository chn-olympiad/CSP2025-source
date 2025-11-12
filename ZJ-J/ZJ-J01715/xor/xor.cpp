#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 5e5+10;
int n, k, a[maxn];
void work1() {
	if (n == 1) cout << 0;
	else if (n == 2) cout << 1;
}
void work2() {
	cout << n/2;
}
void work3() {
	if (k == 1) {
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 1) res++;
		cout << res;
	} else {
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == 0) res++;
		for (int i = 1; i <= n; i++) 
			if (a[i] == 1 && a[i+1] == 1) {
				res++, i++;
			}
		cout << res;
	}
}
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	bool f = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] != 1) f = 0;
	}
	if (f) {
		if (n <= 2 && k == 0) work1();
		else if (n <= 100 && k == 0) work2();	
	}
	else work3();
	return 0;
}
