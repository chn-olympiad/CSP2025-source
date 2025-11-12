#include <bits/stdc++.h>
using namespace std;
int n, m, a[103], k = 1;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++){
		cin >> a[i];
	}
	for (int i = 2; i <= n * m; i++){
		if (a[i] > a[1]){
			k++;
		}
	}
	int t = k / n, f = k % n;
	if (f == 0){
		if (t % 2 == 1){
			cout << t << ' ' << n;
		}else{
			cout << t << ' ' << 1;
		}
	}else{
		if (t % 2 == 1){
			cout << t + 1 << ' ' << n - f + 1;
		}else{
			cout << t + 1 << ' ' << f;
		}
	}
	return 0;
}
