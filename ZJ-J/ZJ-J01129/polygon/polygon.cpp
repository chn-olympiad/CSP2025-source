#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const int mod = 998244353;
int n , a[N];
int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	if(n < 3){
		cout << 0;
		return 0;
	}
	if(n == 3){
		if(a[1] + a[2] > a[3] && a[1] + a[3] > a[2] && a[2] + a[3] > a[1]) cout << 1;
	}
	
	return 0;
}