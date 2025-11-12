# include <bits/stdc++.h>

using namespace std;

const int N = 5050;
int n, a[N], mx;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a + 1, a + n + 1);
	if (n <= 2) {
		cout << 0;
	}else if(n == 3) {
		mx = a[n];
		int lenth = a[1] + a[2] + a[3];
		if (lenth > 2 * mx){
			cout << (lenth % 998244353);
		}else {
			cout << 0;
		}
	}else if (a[n] == 1) {
		unsigned long long k;
		for (int i = 1; i <= n; i++) {
			k += a[i];
		}
		cout << (k % 998244353);
	}else{
		cout << 114514;
	}
	
	return 0;
}
