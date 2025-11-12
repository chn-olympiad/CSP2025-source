#include<bits/stdc++.h>
using namespace std;
long long n,a[5007],sum=0,mod=998244353;
long long cf(int n){
	long long aa=n,cnt=1;
	while(aa--){
		cnt=cnt*2;
		cnt=cnt%mod;
	}
	return cnt%mod;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		long long aaa=(mod+cf(n)-1-n-(n*(n-1)/2))%mod;
		cout<<aaa;
		return 0;
	}
	for(int s=1;s<(1<<n);++s){
		long long mx=0,cnt=0,sl=0;
		for(int i=1;i<=n;++i){
			if(s&(1<<(i-1))){
				++sl;
				cnt+=a[i];
				mx=max(mx,a[i]);
			}
		}
		if(sl>=3&&cnt>2*mx){
			++sum;
		}
		sum=sum%mod;
	}
	cout<<sum;
	return 0;
}
