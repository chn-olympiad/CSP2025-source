#include<bits/stdc++.h>
#define pb push_back
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=5e5+10,mod=998244353;
int n,m,k,T,a[N],vis[N],f[N],ans,c[N],xx,jie[N];
void dfs(int g){
	if(g>n){
		int cnt=0;
		rep(i,1,n){
			if(a[i]==0){
				cnt++;
			}else if(cnt>=c[f[i]]){
				cnt++;
			}
		}if(n-cnt>=m) ans++;
	return;
	}rep(i,1,n){
		if(vis[i]) continue;
		vis[i]=1;f[g]=i;
		dfs(g+1);
		vis[i]=0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n){
    	char s;cin>>s;
    	a[i]=s-'0';
		if(a[i]==0)xx++;
	}rep(i,1,n){
		cin>>c[i];
	}if(n<=10){
		dfs(1);cout<<ans;
	}else{
		if(m==n){
			rep(i,1,n) if(c[i]==0) xx++;
			if(xx!=0) cout<<0;
		}else{
			jie[0]=1;
			rep(i,1,n) jie[i]=jie[i-1]*i%mod;
			cout<<jie[n];
		}
	}
	return 0;
}
