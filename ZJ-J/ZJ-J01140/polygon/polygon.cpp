#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5005,mod=998244353;
ll n,a[N],ans,m;
void dfs(int x,int sum,ll maxn){
	if(x>n){
		if(sum>2*maxn) ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,sum+a[x],max(maxn,a[x]));
	dfs(x+1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans%mod<<'\n';
	}else if(m==1){
		for(int i=3;i<n;i++){
			ll s=1,x=1;
			for(int j=0;j<i;j++) s=s*(n-j)%mod,x=x*(j+1)%mod;
			ans=(ans+s/x)%mod;
		}
		cout<<ans+1<<'\n';
	}
	return 0;
}
