#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10,mod=998244353;

ll n,m,ans;
string s;
ll c[N],a[N];
bool vis[N];

bool check(){
	ll x=0,r=0;
	for(int i=1;i<=n;i++){
		if(c[a[i]]<=x){
			x++;
			continue;
		}
		if(s[i]=='0') x++;
		else r++;
	}
	return r>=m;
}
void dfs(ll step){
	if(step==n){
		if(check()){
			ans++;
			ans%=mod;
		}
		return;
		
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[step+1]=i;
		dfs(step+1);
		vis[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(),cout.tie();
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(0);
	cout<<ans%mod;
	return 0;
}
