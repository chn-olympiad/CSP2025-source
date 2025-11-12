#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=505,mod=998244353;
ll n,m,a[N],b[N],ans,pw[N],dp[20][20][1<<18];
//前i个题录取j个人人的状态为st 
char c[N];
bool vis[N];
vector<ll> G[N];
void dfs(int t){
	if(t==n+1){
		ll t=0;
		for(int i=1;i<=n;i++){
			if(c[i]=='0' || t>=a[b[i]]) t++;
		}
		if(n-t>=m) ans++;
		ans%=mod;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			b[t]=i;
			dfs(t+1);
			vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=pw[i-1]*i%mod;
	bool falg=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]=='0') falg=1;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10){
		dfs(1);
		cout<<ans;
	}else if(n<=18){
		for(int i=0;i<(1<<n);i++) G[__builtin_popcount(i)].push_back(i);
		dp[0][0][0]=1;
		for(int i=1;i<=n;i++){
			for(int k=0;k<i;k++){
				for(int j:G[i-1]){
					for(int x=1;x<=n;x++){
						if(c[i]=='0' || i-1-k>=a[i]) dp[i][k][j|(1<<x-1)]=(dp[i][k][j|(1<<x-1)]+dp[i-1][k][j])%mod;
						else dp[i][k+1][j|(1<<x-1)]=(dp[i][k+1][j|(1<<x-1)]+dp[i-1][k][j])%mod;
					}
				}
			}
		}
		for(int i=m;i<=n;i++){
			ans=(dp[n][i][(1<<n)-1]+ans)%mod;
		}
		cout<<ans;
	}else if(falg==0){
		cout<<pw[n];
	}else if(m==0 && falg==1){
		cout<<0;
	}
	return 0;
}
