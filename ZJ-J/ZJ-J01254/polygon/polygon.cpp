#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define pb push_back
using namespace std;
const ll N = 5e3+10,mod = 998244353;
ll n,a[N],inv[N],jc[N];
pair<ll,vector<pair<ll,ll> > > dp[1010][1010];
ll ksm(ll x,ll k){
	ll res=1;
	while(k){
		if(k&1)	res=res*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return res;
}
ll C(int x,int y){
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void solve2(){
	int ans=0;
	jc[0]=inv[0]=1;
	for(int i = 1;i <= n;i ++){
		jc[i]=jc[i-1]*i%mod;
		inv[i]=ksm(jc[i],mod-2);
	}
	for(int i = 3;i <= n;i ++){
		for(int j = 3;j <= i;j ++){
			ans=(ans+C(i,j))%mod;
		}
	}
	cout << ans << '\n';
}
void solve4(){
	ll ans=0;
	for(int i = 3;i <= n;i ++){
		for(int j = 1;j < i;j ++){
			for(int k = j+1;k < i;k ++){
				int maxa=max(a[i],max(a[j],a[k])),sum=a[i]+a[j]+a[k];
				if(sum>2*maxa){
					dp[i][3].fi++;
					dp[i][3].fi%=mod;
				}
				dp[i][3].se.pb({sum,maxa});
			}
		}
	}
	for(int i = 4;i <= n;i ++){
		for(int j = 4;j <= i;j ++){
			for(int k = j-1;k < i;k ++){
				for(auto it : dp[k][j-1].se){
					int sum=it.fi+a[i],maxa=max(it.se,a[i]);
					if(sum>2*maxa){
						dp[i][j].fi++;
						dp[i][j].fi%=mod;
					}
					dp[i][j].se.pb({sum,maxa});
				}
			}
		}
	}
	for(int i = 3;i <= n;i ++){
		for(int j = 3;j <= i;j ++){
			ans+=dp[i][j].fi;
			ans%=mod;
		}
	}
	cout << ans << "\n";
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i ++)	cin >> a[i];
	bool flag=1;
	for(int i = 1;i <= n;i ++){
		if(a[i]!=1){
			flag=0;
			break;
		}
	}
	if(flag){
		solve2();
	}else{
		solve4();
	}
	return 0;
}