#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n,m,c[505],a[505],ans;
string s;
bool vis[505];
void dfs(int k){
	if(k==n+1){
		int cnt=0;
		for(int i=1;i<=n;i++) if(cnt>=c[a[i]]||s[i]=='0') cnt++;
		(ans+=(n-cnt>=m))%=mod;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[k]=i;
		dfs(k+1);
		vis[i]=0;
	}
}
//int qpow(int a,int b){
//	if(!b) return 1;
//	int tmp=qpow(a,b/2);
//	if(b&1) return tmp*tmp%mod*a%mod;
//	else return tmp*tmp%mod;
//}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=20){
		dfs(1);
		cout<<ans,exit(0);
	}
	if(m==n){
		for(int i=1;i<=n;i++) if(s[i]=='0'||c[i]==0) cout<<0,exit(0);
		ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
		cout<<ans,exit(0);
	}
	if(m==1){
		int ip=0;
		for(int i=1;i<=n;i++) if(s[i]=='1'){
			ip=i;break;
		}
		int cnt=0;
		for(int i=1;i<=n;i++) if(c[i]>=ip) cnt++;
		if(!ip||!cnt) cout<<0,exit(0);
		for(int i=1;i<n;i++) (cnt*=i)%=mod;
		cout<<cnt,exit(0);
	}
	ans=1;
	for(int i=1;i<=n;i++) (ans*=i)%=mod;
	cout<<ans;
	return 0;
}
