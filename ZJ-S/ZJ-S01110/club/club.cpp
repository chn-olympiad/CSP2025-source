#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
ll n,m,k,ans;
ll num[10];
struct node{
	ll a,b,c;
}a[N];
void dfs(ll step,ll sum){
	if(step>n){
//		cout<<sum<<' '<<num[1]<<' '<<num[2]<<' '<<num[3]<<"\n";
		ans=max(ans,sum);
		return ;
	}
	if(num[1]<n/2) num[1]++,dfs(step+1,sum+a[step].a),num[1]--;
	if(num[2]<n/2) num[2]++,dfs(step+1,sum+a[step].b),num[2]--;
	if(num[3]<n/2) num[3]++,dfs(step+1,sum+a[step].c),num[3]--;
}
void solve2(){
	for(ll i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		a[i].a=max(a[i].a,max(a[i].b,a[i].c));
	}
	for(ll i=1;i<=n;i++) ans+=a[i].a;
	cout<<ans<<"\n";
}
void solve(){
	cin>>n;
	ans=0;
	if(n>16){
		solve2();
		return ;
	}
	num[1]=num[2]=num[3]=0;
	for(ll i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
/*

*/
