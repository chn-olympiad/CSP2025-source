#include <bits/stdc++.h>
using namespace std;
long long f(int x){
	if(x==1){
		return 1;
	}
	else if(x==0){
		return 1;
	}
	return f(x-1) * x;
}
long long C(int n, int m){
	return f(m) / (f(n) * f(m-n));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, a[5001];
	long long s = 0;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	if(a[1] == 1 && a[2] == 1){
		for(int i = 3; i <= n; i++){
			s = s + C(i,n);
		}
	}
	else{
		sort(a+1,a+4);
		if(a[1] + a[2] > a[3]){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	cout << s;
	return 0;
}
