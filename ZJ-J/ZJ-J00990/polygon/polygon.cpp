#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int const N=5e3+5;
LL mod=998244353;
LL len[N];
int n;
void dfs(int x,LL total,LL maxn,int&ans){
	if(x==n+1){
		if(maxn*2<total)
			ans=(ans+1)%mod;
		return;
	}
	dfs(x+1,total+len[x],max(maxn,len[x]),ans);
	dfs(x+1,total,maxn,ans);
}
LL fast_pow(LL a,LL b){
	LL res=1ll;
	do{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}while(b>>=1);
	return res;
}
LL dp[N*N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int total=0;
	for(int i=1;i<=n;i++){
		cin>>len[i];
		total+=len[i];
	}
	if(n<=20){ // case1-10
		int ans=0;
		dfs(1,0,0,ans);
		cout<<ans;
		return 0;
	}
	sort(len+1,len+n+1);
	if(len[n]==1){ // case 15-20
		cout<<fast_pow(2,n);
		return 0;
	}
	if(len[n]<=500){ // case 11-14
		dp[0]=1;
		LL ans=0;
		for(int i=1;i<=n;i++){
			for(int j=len[i]+1;j<=total;j++)
				ans=(ans+dp[j])%mod;
			for(int j=total;j>=len[i];j--)
				dp[j]=(dp[j]+dp[j-len[i]])%mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}