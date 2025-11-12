#include <bits/stdc++.h>
using namespace std;
long long n, k, ans, a[500010], b[500010];
long long m=1;
int main(){
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	cin >> n  >> k;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	for(int i=1; i<=n; i++){
		long long c;
		c=a[i-1]^a[i];
		b[i]=b[i]+c;
		
	}
	while(m<=n){
		for(int i=1; i<=n-m+1; i++){
			if(b[i+m-1]-b[i-1]==k){
				ans++;
			}
		}
		m++;
	}
	cout << ans;
	return 0;
}
