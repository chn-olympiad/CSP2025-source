#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5005],maxn=-1e9,ans,c[5005];
const ll mod=998244353;
void dg(int x){
	if(x==n+1){
		ll ml=-1e9,sum=0,num=0;
		for(int i=1;i<=n;i++){
			if(c[i]){
				num++;
				ml=a[i];
				sum+=a[i];
			}
		}
		if(num<3)return ;
		if(sum>ml*2)ans=(ans+1)%mod;
		return ;
	}
	for(c[x]=0;c[x]<=1;c[x]++){
		dg(x+1);
	}
}
ll mqm(ll x,ll y,ll modd){
	ll k=x%modd,ret=1;
	while(y>0){
		if(y%2==1){
			ret=(ret*k)%modd;
		}
		k=(k*k)%modd;
		y>>=1;
	}
	return ret;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(maxn!=1){
		dg(1);
		cout<<ans;
		return 0;
	}
	ll sums=mqm(2,n,mod);
	ll jian=(1+n+n*(n-1)/2)%mod;
	sums=(sums+5*mod-jian)%mod;
	cout<<sums;
	return 0;
}
