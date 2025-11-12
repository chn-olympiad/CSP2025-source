#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n;
ll a[5010];
int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	cin>>n;
	ll maxn=0;
	ll sum=0;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum+=a[i];
	}
	if(n<=3){
		if(sum>2*maxn){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		ll cnt=0;
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				for(ll k=j+1;k<=n;++k){
					ll mn=max(max(a[i],a[j]),a[k]);
					if(a[i]+a[j]+a[k]>2*mn){
						cnt=(cnt+1)%mod;
					}
				}
			}
		}
		if(n==3){
			cout<<cnt;
			return 0;
		}
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				for(ll k=j+1;k<=n;++k){
					for(ll o=k+1;o<=n;++o){
						ll mn=max(max(max(a[i],a[j]),a[k]),a[o]);
						if(a[i]+a[j]+a[k]+a[o]>2*mn){
							cnt=(cnt+1)%mod;
						}
					}
				}
			}
		}
		if(n==4){
			cout<<cnt;
			return 0;
		}
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				for(ll k=j+1;k<=n;++k){
					for(ll o=k+1;o<=n;++o){
						for(ll x=o+1;x<=n;++x){
							ll mn=max(max(max(max(a[i],a[j]),a[k]),a[o]),a[x]);
							if(a[i]+a[j]+a[k]+a[o]+a[x]>2*mn){
								cnt=(cnt+1)%mod;
							}
						}
					}
				}
			}
		}
		if(n==5){
			cout<<cnt;
			return 0;
		}
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				for(ll k=j+1;k<=n;++k){
					for(ll o=k+1;o<=n;++o){
						for(ll x=o+1;x<=n;++x){
							for(ll y=x+1;y<=n;++y){
								ll mn=max(max(max(max(max(a[i],a[j]),a[k]),a[o]),a[x]),a[y]);
								if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]>2*mn){
									cnt=(cnt+1)%mod;
								}
							}
						}
					}
				}
			}
		}
		if(n==6){
			cout<<cnt;
			return 0;
		}
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				for(ll k=j+1;k<=n;++k){
					for(ll o=k+1;o<=n;++o){
						for(ll x=o+1;x<=n;++x){
							for(ll y=x+1;y<=n;++y){
								for(ll s=y+1;s<=n;++s){
									ll mn=max(max(max(max(max(max(a[i],a[j]),a[k]),a[o]),a[x]),a[y]),a[s]);
									if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[s]>2*mn){
										cnt=(cnt+1)%mod;
									}
								}
							}
						}
					}
				}
			}
		}
		if(n==7){
			cout<<cnt;
			return 0;
		}
		for(ll i=1;i<=n;++i){
			for(ll j=i+1;j<=n;++j){
				for(ll k=j+1;k<=n;++k){
					for(ll o=k+1;o<=n;++o){
						for(ll x=o+1;x<=n;++x){
							for(ll y=x+1;y<=n;++y){
								for(ll s=y+1;s<=n;++s){
									for(ll v=s+1;v<=n;++v){
										ll mn=max(max(max(max(max(max(max(a[i],a[j]),a[k]),a[o]),a[x]),a[y]),a[s]),a[v]);
										if(a[i]+a[j]+a[k]+a[o]+a[x]+a[y]+a[s]+a[v]>2*mn){
											cnt=(cnt+1)%mod;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if(n==8){
			cout<<cnt;
			return 0;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
