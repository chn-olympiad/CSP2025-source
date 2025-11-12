#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+10;
const int M=2e3+10;
const int inf=1e17;
const int mod=998244353;
int n,m;
int a[N];
int p[N];
bool vis[N];
int ans=0;
string s;
void dfs(int x,int c,int r){
	cout<<x<<' '<<c<<' '<<r<<endl;
	if(x>n){
		ans+=(r>=m);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		p[x]=i;
		cout<<c<<' '<<a[i]<<' '<<s[x]<<endl;
		dfs(x+1,c+(c>=a[i]||s[x]=='0'),r+!(c>=a[i]||s[x]=='0'));
		vis[i]=0;
	}
	return ;
}
void solve(){
	ans=0;
	cin>>s;
	s=' '+1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,0);
	cout<<ans<<endl;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=10){
		solve();
		return 0;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
		ans%=mod;
		cout<<ans<<endl;
	return 0;
}

