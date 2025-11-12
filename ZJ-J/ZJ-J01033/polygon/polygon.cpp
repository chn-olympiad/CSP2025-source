#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long f(int x){
	x=min(x,n-x);
	long long sum=1;
	for(int i=n;i>(n-x);i--){
		sum=(sum*i)%998244353;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(a[1]+a[2]>a[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	long long ans=0;
	for(long long i=3;i<=n;i++){
		ans=(ans+f(i))%998244353;
	}
	cout<<ans;
	return 0;
}