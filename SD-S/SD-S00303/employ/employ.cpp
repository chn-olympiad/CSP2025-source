#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const ll N=500+5;
ll n,m,c[N],ans=0;
bool vis[N];
string s;
void dfs(ll x,ll res,ll cnt){
	if(x>=n){
		ans=(ans+(res>=m))%mod;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=true;
		if(cnt<c[i])dfs(x+1,res+(s[x]=='1'),cnt+(s[x]=='0'));
		else dfs(x+1,res,cnt+1);
		vis[i]=false;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++)cin>>c[i];
	dfs(0,0,0);
	cout<<ans<<"\n";
	return 0;
}
