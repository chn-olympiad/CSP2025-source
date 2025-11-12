#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=5e3+10,mod=998244353;
ll n;
ll a[N];
ll ans;
void dfs(ll d,ll sum,ll mx,ll flag){
	if(sum>2*mx&&flag){
		ans++;
		ans%=mod;
	}
	if(d>n)return ;
	dfs(d+1,sum+a[d],a[d],1);
	dfs(d+1,sum,mx,0);
}
void solve1(){
	dfs(1,0,0,0);
	cout<<ans;
	return ;
}
vector<ll>prime;
ll mz[N];
bool pd[N];
void ols(){
	pd[1]=1;
	for(ll i=1;i<=5000;i++){
		if(!pd[i])prime.push_back(i);
		for(ll j=0;j<prime.size();j++){
			ll v=prime[j];
			if(i*v>5000)break;
			pd[i*v]=1;
			mz[i*v]=v;
			if(i%v==0)break;
		}
	}
}
ll cnt[N];
void fj(ll x,ll fl){
	while(x!=1){
		cnt[mz[x]]+=fl;
		x/=mz[x];
	}
}
void solve2(){
	ols();
	for(ll i=2;i<=5000;i++){
		if(mz[i]==0)mz[i]=i;
	}
//	for(ll i=1;i<=100;i++){
//		cout<<mz[i]<<" ";
//	}
//	for(ll i=0;i<prime.size();i++){
//		cout<<prime[i]<<" ";
//	}
	fj(n,1),fj(n-1,1),fj(n-2,1);
	fj(1,-1),fj(2,-1),fj(3,-1);
	ll s=n-2,x=3;
	for(ll i=0;i<=n-3;i++){
		ll num=1;
		for(ll j=0;j<prime.size();j++){
//			cout<<prime[j]<<":"<<cnt[prime[j]]<<" ";
			for(ll k=1;k<=cnt[prime[j]];k++){
				num=num*prime[j]%mod;
			}
		}
//		cout<<endl;
		ans+=num;
		ans%=mod;
		s--,x++;
		if(s==0)break;
		fj(s,1),fj(x,-1);
	}
	cout<<ans;
	return ;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}
