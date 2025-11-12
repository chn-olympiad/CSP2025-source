#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a[5005],sum,b;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		sort(a + 1,a + n + 1);
	}
	b = a[n] + a[n];
	if(n == 3){
		if(a[n - 2] + a[n - 1] > a[n] || a[n - 1] + a[n] > a[n - 2] || a[n - 2] + a[n] > a[n - 1]){
			cout << 1 << endl;
			return 0;
		}
		else{
			cout << 0 << endl;
			return 0;
		}
	}
	for(int i = 3;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(a[j] + a[j + 1] > a[j + 2] || a[j] + a[j + 2] > a[j + 1] || a[j + 1] + a[j + 2] > a[j]){
				sum += 1;
			}
		}
	}
	cout << sum % 998244353 << endl;
	return 0;
}
