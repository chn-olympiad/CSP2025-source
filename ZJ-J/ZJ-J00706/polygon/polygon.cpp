#include <bits/stdc++.h>
using namespace std;
int n , a[1000001] , maxn = 0 , f = 0;
long long sum = 1;
int main(){
	freopen("polygon.in" , "r" , stdin );
	freopen("polygon.out" , "w" , stdout );
	cin >> n;
	for ( int i = 1; i <= n; i++ ){
		cin >> a[i];
		maxn = max(a[i] , maxn);
		if ( a[i] != 1 )	f = 1;
	}	
	if ( n == 3 && a[1] + a[2] + a[3] > maxn * 2 ){
		cout << 1;
		return 0;
	}else{
		cout << 0;
		return 0;
	}if ( f == 0 ){
		for ( int i = n-3; i >= 1; i-- ){
			sum += (i * ( i + 3 )) % 998244353;
		}
	}
	cout << sum << endl;
	return 0;
}
