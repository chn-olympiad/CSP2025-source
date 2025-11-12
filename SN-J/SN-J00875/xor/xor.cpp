#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const ll N=5e5+10,MAXN=1e3+10;
ll n,k,a[N],pre[N],ans,dp[MAXN][MAXN];
inline ll get_pre(ll l,ll r){
	return pre[r]^pre[l-1];
}
bool f=true,fl=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(ll i=1;i<=n;++i){
		cin>>a[i],pre[i]=pre[i-1]^a[i];
		if(a[i]!=1) f=false;
		if(a[i]>1) fl=false;
	} 
	if(f&&!k) {
		cout<<n/2;
		return 0;
	}
	else if(fl){
		ll nowl=1;
		for(ll i=1;i<=n;++i){
			if(get_pre(nowl,i)==k){
				++ans;
				nowl=i+1;
			}
		}
		cout<<ans;
		return 0;
	}
	else {
		for(ll i=1;i<=n;++i){
			for(ll j=i;j<=n;++j){
				if(get_pre(i,j)==k)dp[i][j]=1;
				else dp[i][j]=0;
			}
		}
		//cout<<dp[1][2]<<' '<<get_pre(1,2)<<endl;
		for(ll i=1;i<=n;++i){
			for(ll l=1;l+i-1<=n;++i){
				ll r=l+i-1;
				for(ll k=l;k<=r;++k){
//					if(l==1&&r==n){
//						cout<<dp[l][k]<<' '<<dp[k+1][r]<<' '<<l<<' '<<k<<' '<<r<<endl;
//					}
					dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
		cout<<dp[1][n];
	}
	return 0;
}
