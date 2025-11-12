#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,ans;
struct no{
	ll a,b,c;
}x[100005];
int c[100005];
void dfs(ll t){
	if(t==n){
		ll ta,tb,tc; 
		ta=tb=tc=0;
		ll cnt=0;
		for(int i=0;i<n;i++){
			if(c[i]==0){
				cnt+=x[i].a;
				ta++;
			}else if(c[i]==1){
				cnt+=x[i].b;
				tb++;
			}else{
				cnt+=x[i].c;
				tc++;
			}
		}
		if(ta<=n/2&&tb<=n/2&&tc<=n/2){
			ans=max(ans,cnt);
		}
		return ;
	}
	c[t]=0;
	dfs(t+1);
	c[t]=1;
	dfs(t+1);
	c[t]=2;
	dfs(t+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll T;
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
		} 
		ans=0;
		dfs(0);
		cout<<ans<<endl;
	}
	return 0;
} 
