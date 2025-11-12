#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[5005], rsum = 0;
void area( int x, int sum, long long maxn ){
	if( x > n ){
		return ;
	}
	if( sum > maxn * 2 && a[x] == 0 ){
		rsum++;
		rsum %= mod;
	}
	area(x+1, sum, maxn);
	maxn = max(maxn, a[x]);
	area(x+1, sum+a[x], maxn);
	return ;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for( int i = 0; i < n; i++ ){
    	cin >> a[i];
	}
	area(0, 0, 0);
	cout << rsum % mod;
    return 0;
}
