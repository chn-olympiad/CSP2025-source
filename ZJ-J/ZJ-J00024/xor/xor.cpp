#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
bool flag[N];
long long a[N];
#define ll long long
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
			if(a[i]==k){
				ans++;
				flag[i]=true;
			}
	}
	ll g,w;
	for(ll i=1;i<=n;i++){
			if(flag[i]==false){
						g=a[i];
						break;
			}
	}
	for(ll i=1;i<=n;i++){
			if(a[i]==g){
				w=i;
			}
	}
	for(ll i=w+1;i<=n;i++){
			if(flag[i]==false){
					g=g^a[i];
			}
			if(g==k){
					ans++;
					ll rhl=0;
					for(ll j=i+1;j<=n;j++){
						if(flag[i]==false){
								rhl++;
								g=a[j];
								w=j;
								break;
						}
					}
					if(rhl==0){
							cout<<ans;
							return 0;
					}
			}
			if(flag[i]==true){
					if(g==k){
							ans++;
					}
					ll rhl=0;
					for(ll j=i+1;j<=n;j++){
						if(flag[i]==false){
								rhl++;
								g=a[j];
								w=j;
								break;
						}
					}
					if(rhl==0){
							cout<<ans;
							return 0;
					}
			}
			
			
	}
	if(g==k){
			ans++;
	}
	cout<<ans;
	return 0;
}
