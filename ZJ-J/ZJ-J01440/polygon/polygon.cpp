#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
ll mod=998244353;
ll n,ar[5005];
ll vis[5005];
ll res[5005];
ll ans=0;
ll quick_power(ll x,ll po){
	ll base=x,anss=1;
	while(po){
		if(po&1) {
			anss=anss*base%mod;
		}
		base=base*base%mod;
		po>>=1;
	}
	return anss%mod;
}
void dfs(int k){
	if(k==n+1){
		ll sum=0,maxn=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				sum+=ar[i];
				maxn=max(maxn,ar[i]);
			}
		}
		if(sum>maxn*2){
			 ans++;
		}
		return ;
	}
	vis[k]=1;
	dfs(k+1);
	vis[k]=0;
	dfs(k+1);
}
ll C(ll a,ll b){
	//cout<<res[a];
	ll f=res[b]*res[a-b]%mod;
	ll x=(res[a]*quick_power(f,mod-2))%mod;
	return x;
}
int main(){ 
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n;
//	cout<<quick_power(3);
	ll amx=0;
	for(int i=1;i<=n;i++){
		cin>>ar[i];amx=max(amx,ar[i]);
	}	
	res[0]=res[1]=1;
	for(int i=2;i<=5001;i++){

		res[i]=res[i-1]*i%mod;
	} 		
//	cout<<A(2,1);

	if(n<=10){
		
		dfs(1);
		cout<<ans%mod<<endl;
	}

	else if(amx==1){
		for(int i=3;i<=n;i++){
			for(int j=2;j<=i-1;j++){
				if(i>=j){
				//	cout<<res[i]<<' '<<res[j]<<endl;
					ans=(ans+C(i-1,j))%mod;
				}
			}
		}
		cout<<ans%mod;
	} 
	return 0;
}
