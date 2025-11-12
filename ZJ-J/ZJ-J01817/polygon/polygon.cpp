#include<bits/stdc++.h>
using namespace std;
long long n,a[5001],ans;
void dfs(long long k,long long p,long long maxn,long long q){
	if(k==0){
		if(p>2*maxn) ans++;
		ans%=998244353; 
		return;
	}
	for(long long i=q;i<=n-k+1;i++){
		dfs(k-1,p+a[i],max(maxn,a[i]),i+1);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool flag=1;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		long long cnt=(n*(n-1))/(1*2);
		for(long long i=3;i<=n;i++){
			cnt*=(n-i+1)%998244353;
			cnt/=i;
			cnt%=998244353;
			ans+=cnt;
			ans%=998244353;
		}
		cout<<ans%998244353;
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=3;i<=n;i++){
		dfs(i,0,0,1);
	}
	cout<<ans%998244353;
}
/*
3 3
94 95 96 97 98 99 100 93 92
*/
