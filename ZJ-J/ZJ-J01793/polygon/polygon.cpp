#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=6000;
const ll mod=998244353;
ll n,a[N],ans,sum,maxn;
bool f,vis[N];
ll solve(){
	ll c=1,d=1;
	if(n%2){
		c=(n-1)/2;
		d=(n*(n-2))/3;
	}else{
		if((n-1)%3==0){
			c=(n-1)/3;
			d=(n*(n-2))/2;
		}else{
			c=n-1;
			d=(n*(n-2))/6;
		}
	}
	ans=(c*d)%mod;
	return ans;
}
void polygon(int t,int e,int w){
	if(t==e){
		ll q=0,mm=0;
		for(ll i=1;i<=n;i++){
			if(vis[a[i]]){
				mm=max(mm,a[i]);
				q+=a[i];
				//cout<<a[i]<<' '; 
			}
		}
		if(q>2*mm)ans=(ans+1)%mod;
		//cout<<'\n';
		return; 
	}
	for(int i=w;i<=n;i++){
		if(!vis[a[i]]){
			vis[a[i]]=1;
			int k=t+1;
			polygon(k,e,i);
			vis[a[i]]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i]; 
		maxn=max(maxn,a[i]);
		if(a[i]!=1)f=1;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>(2*maxn))
			ans=1;
	}else if(!f)ans=solve();
	else{
		for(int i=3;i<=n;i++)
			polygon(0,i,1);
	}
	cout<<ans;
	return 0;
}

