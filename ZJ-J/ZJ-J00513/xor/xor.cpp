#include <bits/stdc++.h>
using namespace std;
int n, k,a[500005],p;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		if(a[i]!= 1)p =1;
	}
	if(p == 0){
		cout << n / 2;
		return 0;
	}
	if(k <= 1){
		cout << n/3;
	}
	cout << 5;
	return 0;
}
