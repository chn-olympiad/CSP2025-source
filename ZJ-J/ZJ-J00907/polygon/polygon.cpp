#include<bits/stdc++.h>
using namespace std;
long long c(long long x,long long y){
	long long anss=1;
	for(int i=x;i>x-y;i--){
		anss*=i;
	}
	for(int i=1;i<=y;i++){
		anss/=i;
	}
	return anss;
}
int a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long n,ans=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=3;i<=n;i++){
		ans+=c(n,i);
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
