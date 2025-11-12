#include<bits/stdc++.h>
#define int long long
#define For(i,l,r) for(int i=(l);i<=(r);++i)
using namespace std;
int n,a[5010];
int ans=0,mod=998244353;
void dfs(int x,int sum,int len,bool flag){
	if(x>n||len>n) return ;
	if(flag&&len>=3&&sum>2*a[x]) ++ans,ans%=mod;
	dfs(x+1,sum+a[x+1],len+1,1);
	dfs(x+1,sum,len,0);
}
int qpow(int a,int b){
	if(b==0) return 1;
	if(b&1) return qpow(a,b/2)%mod*qpow(a,b/2)%mod*a%mod;
	else return qpow(a,b/2)%mod*qpow(a,b/2)%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	For(i,1,n) cin>>a[i];
	//cheat score!
	bool flag=1;
	For(i,1,n) if(a[i]!=1){flag=0; break;}
	if(flag){
		ans=qpow(2,n)-n-1-n*(n-1)/2;
	}else{
		sort(a+1,a+1+n);
		dfs(0,0,0,0);
	}
	cout<<ans;
	return 0;
}
