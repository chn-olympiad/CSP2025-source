#include<bits/stdc++.h>
using namespace std;
long long qpow(long long p,long long q){
	long long ans=1;
	while(q){
		if(q%2==1){
			ans*=p;
			ans%=998244353;
		}
		p=p*p%998244353;
		q/=2;
	}
	return ans;
}
long long inv(long long p){
	return qpow(p,998244351);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=0,t,r;
	int a[505];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=m;i<=n;i++){
		t=1;
		r=1;
		for(int j=1;j<=i;j++)t=t*j%998244353;
		for(int j=n-i+1;j<=n;j++)r=r*j%998244353;
		t=inv(t);
		r=r*t%998244353;
		ans+=r;
	}
	cout<<ans%998244353;
	return 0;
}
