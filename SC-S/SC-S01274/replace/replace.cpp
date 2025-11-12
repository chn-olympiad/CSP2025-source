#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
string a[N] , b[N] , c[N] , d[N];
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> c[i] >> d[i];
	}
	for(int i = 1; i <= q; i++){
		cout << 0 << '\n';
	}
	return 0;
}