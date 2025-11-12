#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[5005],b[5005];
ll ans=0;
const ll mod=998244353;
ll qpow(ll x,ll y){
	ll sum=1;
	while(y){
		if(y&1) sum=sum*x%mod;
		x=x*x%mod,y>>=1;
	}
	return sum;
}
void check(int len){
	if(len<3) return;
	int sum=0,maxn=0;
	for(int i=1;i<=len;i++){
		sum+=b[i];
		maxn=max(maxn,b[i]);
//		cout<<b[i];
	}
//	cout<<endl;
	if(sum>maxn*2){
		ans++;
//		cout<<"YES"<<endl;
	}
}
void dfs(int x,int len){
	if(x>n){
		check(len);
		return;
	}
	b[len+1]=a[x];
	dfs(x+1,len+1);
	b[len+1]=0;
	dfs(x+1,len);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) fl=0;
	}
	if(fl){
		ll x=n*(n-1)*(n-2),y=6;
		for(int i=3;i<=n;i++){
			ans=(ans+x*qpow(y,mod-2)%mod)%mod;
			x=x*(n-i)%mod;
			y=y*(i+1)%mod;
		}
		cout<<ans;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}