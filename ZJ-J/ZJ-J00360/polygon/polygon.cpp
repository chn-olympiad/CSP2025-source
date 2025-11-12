#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=51000,mod=998244353;
ll n,a[5100],b[N],c[N],ans=0;
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++){
		for (int k=1;k<=N-100;k++) c[k]=0;
		for (int k=1;k<=N-100;k++){
			if (b[k]) c[a[i]+k]=b[k];
		} 
		b[a[i]]++;
		
		for (int k=1;k<=N-100;k++){
			b[k]+=c[k];
			b[k]%=mod;
			c[k]=c[k-1]+b[k];
			c[k]%=mod;
	
		}
		ll t=(c[N-100]+mod-c[a[i+1]])%mod;
		ans+=t;
		ans%=mod;
	}
	cout<<ans;
}
