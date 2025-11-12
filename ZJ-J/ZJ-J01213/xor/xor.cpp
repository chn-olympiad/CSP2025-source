#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[500009],ans;
ll sum[500009];
bool vis[500009];
int main(){
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>a[i];	
		sum[i]=sum[i-1]^a[i];
	}
	for(ll len=1;len<=n;len++){
		for(ll l=1;l+len-1<=n;l++){
			ll r=l+len-1;
			bool fl=0;
			for(ll o=l;o<=r;o++){
				if(vis[o]){
					fl=1;
					break;
				}
			}
			if(fl) continue;
			cout<<(sum[r]^sum[l-1])<<"\n";
			if((sum[r]^sum[l-1])==k){
				ans++;
				for(ll o=l;o<=r;o++) vis[o]=1;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}
