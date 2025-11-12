#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],p;
long long f(long long x){
	if(x==1) return 2;
	if(x%2==0){
		long long y=f(x/2)%998244353;
		return y*y%998244353;
	}
	else{
		long long y=f(x/2)%998244353;
		return y*y*2%998244353;
	}
}
long long dfs(long long l,long long sum,long long mx){
	if(l>n){
		if(sum>2*mx) return 1;
		else return 0;
	}
	if(sum>2*p) return f(n+1-l)%998244353;
	return (dfs(l+1,sum+a[l],max(mx,a[l]))%998244353+dfs(l+1,sum,mx)%998244353)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i],p=max(p,a[i]);
	if(p!=1) cout<<dfs(1,0,0)%998244353;
	else cout<<(f(n)+998244353-1-n-n*(n-1)/2)%998244353;
	return 0;
}