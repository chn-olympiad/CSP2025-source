#include <bits/stdc++.h>
using namespace std;
double n, k, a[114514];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (k = 0) {
			a[i] = 1;
			cout << a[i];
		}else if(k<=1){
			a[i]=k/n;
		}else if(k<=225){
			a[i]=(k*n)/2;
		}else{
			a[i]=k*n;
		}
	}

	return 0;
}