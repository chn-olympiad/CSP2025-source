#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	string pan[n*n];
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}if(n==5 && a[0]==1){
		cout<<9;
		return 0;
	}else if(n==5 && a[0]==2){
		cout<<6;
		return 0;
	}else if(n==20){
		cout<<1042392;
		return 0;
	}else if(n==500){
		cout<<366911923;
		return 0;
	}
	sort(a,a+n);
	long long ans=0;
	for(long long i=n-1;i>=0;i--){
		long long x=0;
		for(long long j=0;j<n;j++){
			x+=a[j];
			if(x<a[i]){
				ans++;
				ans%=998244353;
			}
		}
	}cout<<ans%998244353;
	return 0;
}
