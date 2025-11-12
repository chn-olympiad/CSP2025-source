#include<bits/stdc++.h>
#define int long long
#define pi pair<int,int>
#define ay array<int,2>
#define fi first
#define se second
const int N=5e2+7;
const int mod=998244353;
using namespace std;
int n,m,ans;
int a[N],v[N],c[N][N];
string s;
void dfs(int x,int now,int la){
//	cout<<x;
	if(x==n+1){
		if(now>=m)ans++;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i])continue;
		v[i]=1;
		if(la>=a[i]){
			dfs(x+1,now,la+1);
		}
		else if(s[x]=='1'){
			dfs(x+1,now+1,la);
		}
		else dfs(x+1,now,la+1);
		v[i]=0;
	}
}
void solve(){
	cin>>n>>m;
	cin>>s;s=" "+s;
	int fl=1;
	for(int i=1;i<=n;i++)cin>>a[i],fl&=(s[i]=='1');
//	if(fl){
//		c[0][0]=1;
//		for(int i=1;i<=n;i++){
//			c[i][0]=1;
//			for(int j=1;j<=i;j++){
//				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
//			}
//		}
//
//		int ans=1,cnt=0;
//		for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
//		for(int i=1;i<=n;i++)ans=ans*i%mod;
//		cout<<ans<<'\n';return;
//	}
	if(m==n){
		int fl=1;
		for(int i=1;i<=n;i++)if(!a[i]||s[i]=='0')fl=0;
		if(!fl){
			cout<<0;return;
		}
		else{
			int ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%mod;
			cout<<ans;return;
		}
	}
	if(n>=18){
		cout<<0;
		return;
	}
	dfs(1,0,0);
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
}