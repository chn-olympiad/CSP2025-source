#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
/*
hao xiang shu wei DP
20 pts
*/
typedef unsigned long long ll;
int n,a[5010];
ll ans=0,t;
ll mod=998244353;
bool cmp(int x,int y){
	return x>y;
}
bool check(){
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1])return false;
	}
	return true;
}
ll c(ll u,ll v){
	ll k=u-v+1;
	ll cnt=1;
	for(int i=1;i<=k;i++){
		cnt*=(i+k-1);
		cnt/=i;
	}
	return cnt%mod;
}
ll dfs(int l,int x,int id){//length sum-2max
	int cnt=0;
	id++;
	if(l>t)return 0;
	if(l==t){
		if(x>0)return 1;
		else return 0;
	}
	while(id<=n-t+l+1){
		cnt+=dfs(l+1,x+a[id],id);
		id++;
	}
	return cnt;
}
ll solve(int l){
	t=l;
	ll y=0;
	for(int i=1;i<=n-l+1;i++){
		y+=dfs(1,-a[i],i);
	}
	return y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==3){
		ll x=max(a[1],max(a[2],a[3]));
		ll y=a[1]+a[2]+a[3];
		if(y>2*x)cout<<"1";
		else cout<<"0";
		exit(0);
	}
	if(check()){
		for(int l=3;l<=n;l++){
			ans+=c(n,l);
			ans%=mod;
		}
		cout<<ans<<endl;
		exit(0);
	}
	sort(a+1,a+n+1,cmp);
	for(int l=3;l<=n;l++){//length
		ans+=solve(l);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
