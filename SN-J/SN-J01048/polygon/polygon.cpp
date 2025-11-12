#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5005,mod=998244353;
ll n,a[maxn];
bool flagt=1;
ll f(int l,int r){
	ll ty=1;
	for(int i=l;i<=r;i++){
		ty*=i;
	}
	return ty;
}
ll c(int n,int m){
	if(m*2>=n){
		m=n-m;
	}
	ll yu=f(n-m+1,n),io=f(1,m);
	return (yu/io)%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flagt=0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])cout<<1<<endl;
		else cout<<0;
	}else if(flagt==1){
		ll tot=0;
		for(int i=3;i<=n;i++){
			tot+=c(n,i);
			tot%=mod;
		}
		cout<<tot<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
}
