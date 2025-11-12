#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define PI pair<ll,ll> 
const ll MOD=998244353;
const ll N=5e3+3;
const ll M=1e2+2;
const ll NTT=5e2+2;
ll a[N],n;
int mp2[NTT][M*2][M];
ll dp[100000];
ll qpow(ll x,ll k){
	ll res=1,bl=x;
	while(k){
		if(k&1){
			res*=bl;
			res%=MOD;
		}
		bl*=bl;
		bl%=MOD;
		k>>=1;
	}
	return res;
}
ll dfs2(int now,ll sum,ll maxx){
	if(now==n+1){
		if(sum>2*maxx) return 1;
		return 0;
	}
	if(sum>a[n]*2){
		ll res=qpow(2,n-now+1);
		return res;
	}
	if(mp2[now][sum][maxx]!=-1){
		return mp2[now][sum][maxx];
	}
	int res=0;
	res+=dfs2(now+1,sum+a[now],max(maxx,a[now]));// have now
	res+=dfs2(now+1,sum,maxx);// none now
	if(res>MOD) res-=MOD;
	mp2[now][sum][maxx]=res;
	return res;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[n]==1){
		ll sum=qpow(2,n);
		sum=(sum-1+MOD)%MOD;
		sum=(sum-n+MOD)%MOD;
		ll tr=n*(n-1)/2;
		tr%=MOD;
		sum=(sum-tr+MOD)%MOD;
		cout<<sum<<'\n';
		return;
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=a[n]*2;j++){
				for(int k=0;k<=a[n];k++){
					mp2[i][j][k]=-1;
				}
			}
		}
		cout<<dfs2(1,0,0)<<'\n';
		return;
	}
	ll sum=a[1]+a[2];
	ll ans=0;
	dp[0]++;
	dp[a[1]]++;
	dp[a[2]]++;
	dp[sum]++;
	for(ll i=3;i<=n;i++){
		ll res=qpow(2,i-1);
		sum+=a[i];
		sum=min(sum,a[n]*2);
		for(ll j=0;j<=a[i];j++){
			res=(res-dp[j]+MOD)%MOD;
		}
		for(ll j=sum;j>=a[i];j--){
			dp[j]+=dp[j-a[i]];
			dp[j]%=MOD;
		}
		ans+=res;
		ans%=MOD;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	solve();
	return 0;
}
