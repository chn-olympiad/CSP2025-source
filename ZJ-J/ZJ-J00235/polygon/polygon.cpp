#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[5010],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n<=8){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll k=j+1;k<=n;k++){
					ll Max=max({a[i],a[j],a[k]}),sum=a[i]+a[j]+a[k];
					if(sum>Max*2)ans++;
					for(ll p=k+1;p<=n;p++){
						ll Max=max({a[i],a[j],a[k],a[p]}),sum=a[i]+a[j]+a[k]+a[p];
						if(sum>Max*2)ans++;
						for(ll q=p+1;q<=n;q++){
							ll Max=max({a[i],a[j],a[k],a[p],a[q]}),sum=a[i]+a[j]+a[k]+a[p]+a[q];
							if(sum>Max*2)ans++;
							for(ll x=q+1;x<=n;x++){
								ll Max=max({a[i],a[j],a[k],a[p],a[q],a[x]}),sum=a[i]+a[j]+a[k]+a[p]+a[q]+a[x];
								if(sum>Max*2)ans++;
								for(ll y=x+1;y<=n;y++){
									ll Max=max({a[i],a[j],a[k],a[p],a[q],a[x],a[y]}),sum=a[i]+a[j]+a[k]+a[p]+a[q]+a[x]+a[y];
									if(sum>Max*2)ans++;
									for(ll z=y+1;z<=n;z++){
										ll Max=max({a[i],a[j],a[k],a[p],a[q],a[x],a[y],a[z]}),sum=a[i]+a[j]+a[k]+a[p]+a[x]+a[y]+a[z];
										if(sum>Max*2)ans++;
										for(ll t=z+1;t<=n;t++){
											ll Max=max({a[i],a[j],a[k],a[p],a[q],a[x],a[y],a[z],a[t]}),sum=a[i]+a[j]+a[k]+a[p]+a[q]+a[x]+a[y]+a[z]+a[t];
											if(sum>Max*2)ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout<<ans;
		return 0;
	}
	
	return 0;
}

