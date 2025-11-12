#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],s,ans,b[5001],m;
bool cmp(long long x,long long y){
	return x>y;
}
long long c(long long q){
	q=max(q,n-q);
	long long res=1,rres=1;
	for(int i=q+1;i<=n;i++){
		res*=i;
	}
	for(int i=1;i<=n-q;i++){
		rres*=i;
	}
	return (res/rres)%998244353;
}
void solve(){
	for(int i=3;i<=n;i++){
		ans=(ans+c(i))%998244353;
	}
}
void dfs(long long x,long long l,long long z){
	if(l==1){
		long long res=0;
		for(int i=x+1;i<=n;i++){
			if(a[i]>z) res++;
			else break;
		}
		ans=(ans+res)%998244353;
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,l-1,z-a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(m==1){
		solve();
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			for(int l=1;j+l<=n;l++){
				dfs(j,l,a[i]-a[j]);
			}
		}
	}
	cout<<ans;
	return 0;
}

