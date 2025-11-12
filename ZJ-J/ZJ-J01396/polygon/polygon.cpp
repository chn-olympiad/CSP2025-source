#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll P=998244353;
int n;
ll len[5030];
ll ans;
ll SUM;//
int temp[5030];
int l;
inline add1(){
	temp[1]++;
	int i=1;
	while(temp[i]>1){
		temp[i]-=2;
		temp[i+1]++;
		i++;
	}
	l=max(l,i);
}
inline bool check(){
	int flag=0;
	for(int i=1;i<=l;i++){
		if(temp[i]) flag++;
		if(flag>=3) return 1;
	}
	return 0;
}
void solve(){
	ll sum=0,maxn=-1;
	int leni=0;
	int ti=1;
	while(ti<l+1){
		ll t=temp[ti];
		ti++;
		leni++;
		if(!t) continue;
		sum+=len[leni];
		maxn=max(maxn,len[leni]);
	}
	if(maxn*2 < sum){
		ans++;
		ans%=P;
	}
	return;
}
inline ll QuickPow(ll a,ll b){//
	ll ans=1;
	while(b){
		if(b & 1) ans=(ans*a)%P;
		b/=2;
		a=(a*a)%P;
	}
	return ans%P;
}//
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len[i];
		SUM+=len[i];
	}
	
	if(SUM==n){//
		ll ANS=QuickPow(2,n);
		ANS-=((n*(n+1))%P)/2;
		ANS--;
		cout<<ANS;
		return 0;
	}//
	
	while(!temp[n+1]){
		add1();
		if(!check()) continue;
		solve();
	}
//	ll K=1;
//	for(int i=1;i<=n+1;i++) K*=2;
//	for(ll i=0;i<=K;i++){
//		solve(i);
//	}
	cout<<ans%P;
	return 0;
}

