#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+10,M=2e6+10;
ll n,k;
ll a[N],b[N],l[M];
vector<ll>g[M];
ll ans,maxx;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	g[0].push_back(0);
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
		g[b[i]].push_back(i);
	}
//	for(ll i=1;i<=n;i++){
//		cout<<b[i]<<" ";
//	}
    for(ll i=1;i<=n;i++){
    	ll mb=b[i]^k;
    	if(g[mb].empty())continue;
    	ll p;
    	if(l[mb]==g[mb].size())continue;
    	if(g[mb][g[mb].size()-1]<i){
    		p=g[mb].size()-1;
		}
    	else{
    		p=lower_bound(g[mb].begin()+l[mb],g[mb].end(),i)-g[mb].begin();
    		if(p==0)continue;
    		p--;
		}
		ll v=g[mb][p];
		if(v<maxx)continue;
		ans++;
		maxx=i;
		l[mb]=p+1;
//		cout<<v+1<<" "<<i<<endl;
	}
	cout<<ans;
	return 0;
}
//4 3
//2 1 0 3
//2 3 3 0
//1 0 0 3

