#include<bits/stdc++.h> // 刘伊陆 SN-j00077 曲江第一学校 
using namespace std;
long long n, m, f, zb, a[1010], b[1010], l, h;
int main() {
	freopen("seat.in" , "r" , stdin);
	freopen("seat.out" , "w" , stdout);
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++) {
		cin >> b[i];
	}
	f = b[1];
	sort(b + 1 , b + n * m + 1);
	for (int i = 1; i <= n * m; i++){
		a[i] = b[n * m - i + 1];
	}
	for (int i = 1; i <= n * m ; i++){
		if(f == a[i]){
			zb = i;
			break;
		}
	}
	l = (zb + n - 1) / n;
	h = zb % n;
	if(h == 0) h = n;
	if (l % 2 == 1){
		cout << l << " " << h;
	}else{
		cout << l << " " <<  n - h + 1;
	}
	return 0;
}
