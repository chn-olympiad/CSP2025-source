//我问我自己。 
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,c[505],_1,zj[15],sum[505];
long long ans;
string s;
bool vis[15];
void dfs(int step){
	if(step==n+1){
		int die=0;
		for(int i=1;i<=n;i++) if(s[i]=='0'||(s[i]=='1'&&die>=c[zj[i]])) die++;
		if(n-die>=m) ans++;
		return ;
	} for(int i=1;i<=n;i++) if(!vis[i]){
		zj[step]=i;
		vis[i]=true;
		dfs(step+1);
		vis[i]=false;
	}
}
void solve(){
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==m){
		bool zj=true;
		for(int i=1;i<=n;i++) if(s[i]=='0'||!c[i]){
			zj=false;
			break;
		} if(zj){
			ans=1;
			for(int i=1;i<=n;i++) (ans*=i)%=mod;
			cout<<ans<<"\n";
		} else cout<<"0\n";
		return ;
	} for(int i=1;i<=n;i++) if(s[i]=='0') _1++;
	if(m==1){
		long long lxt=1;
		int cnt=0;
		ans=1;
		for(int i=1;i<=n;i++) sum[c[i]]++,(ans*=i)%=mod;
		for(int i=1;i<=n;i++) sum[i]+=sum[i-1];
		for(int i=1;i<=n;i++) if(s[i]=='1') (lxt*=(sum[i-1]-cnt))%=mod,cnt++;
		for(int i=1;i<=_1;i++) (lxt*=i)%=mod;
		return cout<<(ans-lxt+mod)%mod<<"\n",void();
	} if(n<=10){
		dfs(1);
		return cout<<ans<<"\n",void();
	} return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
