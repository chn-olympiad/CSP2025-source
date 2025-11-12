//赵子晗 SN-S00678 西安市曲江第二中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll N=1e5+10;

ll t,g[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	while(t--){
		ll n,ans=0;
		cin>>n;
		ll u,v;
		for(int i=1;i<=n;i++) cin>>g[i]>>u>>v;
		sort(g+1,g+n+1);
		for(int i=n;i>n/2;i--) ans+=g[i];
		cout<<ans<<"\n";
	}
	
	return 0;
}
