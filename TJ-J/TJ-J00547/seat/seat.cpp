#include<bits/stdc++.h>
using namespace std;
bool a[101];
long long  n ,m, x, xr;
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	long long k = n * m, f;
	cin >> f ;
	x = f;
	a[x]++;
	for(long long i = 1; i < k; i++){
		cin >> f;
		a[f] = true;
	}
	for(long long i = 100; i > 0; i--){
		if(a[i]){
			xr++;
			if(i == x){
				break;
			}
		}
	}
	long long xo = ceil(1.0 * xr / n), yo;
	if(xo % 2 == 0){
		yo = m - xr % m + 1;
	}
	else{
		yo = xr % m;
		if(yo == 0) {
			yo = m;
		}
	}
	cout << xo << ' ' << yo << endl;
	return 0;
}
