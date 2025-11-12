#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define pii pair<int,int>
#define fr first
#define sc second
#define gtc getchar
#define ptc putchar
inline ll read(){
	ll x=0,f=1; char ch=gtc();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=gtc(); }
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gtc();
	return x*f;
}
inline void write(ll x){
	if(x<0) ptc('-'),x=-x;
	if(x>9) write(x/10);
	ptc(x%10+'0');
}
inline void println(ll x){ write(x),ptc('\n'); }
inline void printsp(ll x){ write(x),ptc(' '); }
const int maxn=500+6;
int n,m,vis[maxn],rk[maxn],c[maxn];
char s[maxn];
int ans=0;

void dfs(int dep){
	if(dep==n+1){
		int now=0;
		for(int i=1;i<=n;i++){
			if(now>=c[rk[i]]){
				now++;
				continue;
			}
			if(s[i]=='0') now++;
		}
		if(now<=n-m){
			ans++;
//			for(int i=1;i<=n;i++) cout<<rk[i]
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			rk[dep]=i;
			dfs(dep+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>(s+1);
	for(int i=1;i<=n;i++) c[i]=read();
	dfs(1);
	println(ans);
	return 0;
}
/*
3 2
101
1 1 2
*/
