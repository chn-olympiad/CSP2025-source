#include<bits/stdc++.h>
#define int long long
#define MOD 998244353LL
#define N 505
using namespace std;
int n,m,b[N],f[N],t[N],D=1LL,ans;
int CNT,MAXN;
string s;
bool vis[N],flagA;
void get_f(){
	f[0]=1LL;
	for(int i=1;i<=500;i++) f[i]=f[i-1]*i%MOD;
}
void solve(){
	sort(b+1,b+n+1);
	do{
		int cnt=0LL,c=0LL;
		for(int i=1;i<=n;i++){
			if(c>=b[i]){c=(c+1LL)%MOD;continue;}
			if(s[i-1]=='1') cnt=(cnt+1LL)%MOD;
			else c=(c+1LL)%MOD;
		}
		if(cnt>=m) ans=(ans%MOD+D%MOD)%MOD;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans%MOD<<'\n';
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	get_f();
	cin>>n>>m>>s;
	CNT=0,MAXN=0;
	for(char c:s) if(c=='0') flagA=1;
	for(int i=1;i<=n;i++){
		cin>>b[i],t[b[i]]++;
		MAXN=max(MAXN,b[i]);
		if(b[i]==0) CNT++;
	}
	for(int i=1;i<=n;i++){
		if(vis[b[i]]) continue;
		vis[b[i]]=1;
		D=D*f[t[b[i]]]%MOD;
	}
	solve();
	return 0;
}
