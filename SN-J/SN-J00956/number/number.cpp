#include<bits/stdc++.h>
using namespace std;
	long long n,a[10000005];
int main() {
freopen("number","r",strin);
freopen("number","w",strout);
	cin>>n;
	if(n<10) {
		cout<<n;
		return 0;
	}
	for(long long  i=1; i<=n; i++) {
		a[i]=n%10;
		n/=10;
	}
	sort(a+1,a+1+n);
	for(long long  i=1; i<=n; i++) {
		cout<<a[i]<<" ";
		
	}
}
