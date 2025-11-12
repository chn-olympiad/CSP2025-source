#include<bits/stdc++.h>
using namespace std;
const int N=5012;
const long long mod=998244353;
int n,a[N];
int f(int bs){
	long long num=1;
	for(int i=1;i<=bs;i++){
		num*=(num*(n-i))%mod;
		num%=mod;
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool f1=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f1=0;
	}
	if(n==3){
		int maxx=max(a[1],max(a[2],a[3]));maxx*=2;
		int num=a[1]+a[2]+a[3];
		if(num>maxx)cout<<"1";
		else cout<<"0";
		return 0;
	}
	if(f1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=f(i);ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
} 
