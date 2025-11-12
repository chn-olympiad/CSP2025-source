#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const ll N=1e5+10,mod=998244353;
ll n,a[N],C[N][10],ans;
bool f=true;
ll fp(ll a,ll b){
	ll ret=1;
	while(b){
		if(b&1) ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}
void init(){
	for(ll i=1;i<=n;++i) C[i][1]=i;
	for(ll i=1;i<=2;++i) C[i][i]=1;
	for(ll i=3;i<=n;++i){
		C[i][2]=(C[i-1][2]+C[i-1][1])%mod;
	}
}
void dfs(ll now,ll sum,ll mx,ll cnt){
	if(now>n){
		if(sum>2*mx&&cnt>=3)ans=(ans+1)%mod;
		return;
	}
	dfs(now+1,sum+a[now],max(mx,a[now]),cnt+1);
	dfs(now+1,sum,mx,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]>1)f=false;
	} 
	if(f){
		ll cnt=0;
		for(ll i=1;i<=n;++i) if(a[i])++cnt;
		if(cnt<3){
			cout<<0;
			return 0;
		}
		init();
		cout<<(fp(2,cnt)-C[cnt][1]-C[cnt][2]-1)%mod;//2^n-(n,2)-(n,1)-(n,0)
	}
	else{
		dfs(1,0,-1,0);
		cout<<ans;
	}
}
