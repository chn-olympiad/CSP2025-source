#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a)
#define put(a) printf("%lld\n",a)
#define scan(a,b) scanf("%lld%lld",&a,&b)
int n,m,k,t,ans,cnt;
int T;
const int inf=1e17;
const int N=2e5+20;
const int mod=998244353;

int a[N],x,y,w,c[N],b[N];
bool vis[N];
string s1;
void dfs(int x){
	if(x==n+1){
		int now=0;
		rep(i,1,n){
			if(a[i]==0)now++;
			else if(c[b[i]]<=now)now++;
		}
		if(n-now>=m) ans++;
		if(ans>=mod) ans-=mod;
		return ;
	}
	rep(i,1,n){
		if(!vis[i]){
			b[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}

}

void solve(){
	bool flg=1;

	scan(n,m);
	rep(i,1,n){
		scanf("%1lld",&a[i]);
		if(a[i]!=1)flg=0;
	}
	rep(i,1,n){
		sc(c[i]);
		
	}
	dfs(1);
	put(ans);
	
	
	


	
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	solve();
	
	return 0;
}
