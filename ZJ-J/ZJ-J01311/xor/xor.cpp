#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[1010],vis[1010],sum;
void dfs(ll m){
	for(ll i=m;i<=n;i++){
		for(ll j=i-m+1;j<=i;j++){
			ll s=0;
			for(ll r=j;r<=i;r++){
				s=s^a[r];
				if(vis[r]==1){
					s=-2e9;
					break;
				}
			}
			if(s==k){
				sum++;
				for(ll r=j;r<=i;r++){
					vis[r]=1;
			    }
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		dfs(i);
	}
	cout<<sum;
}