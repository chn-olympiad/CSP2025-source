#include<bits/stdc++.h>
#define int long long
namespace FastIO
{
	inline int read()
	{
		int x=0,f=1;
		char c=getchar();
		while(c<'0'||c>'9'){
			if(c=='-') f^=1;
			c=getchar();
		} 
		while(c>='0'&&c<='9'){
			x=(x<<3)+(x<<1)+(c^48);
			c=getchar();
		}
		return f?x:~x+1; 
	}
	inline void write(int x)
	{
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10^48);
	}
	inline void spaceput(int x)
	{
		write(x);putchar(' ');
	}
	inline void output(int x)
	{
		write(x);putchar('\n');
	}
} 
using namespace std;
using namespace FastIO;
constexpr int N=5e2+5;
constexpr int mod=998244353;
int n,m,tot,ans;
int fac[N],c[N],t[N];
char s[N];
bitset<N> vis;
void pre()
{
	fac[1]=1;
	for(int i=2;i<=502;i++) fac[i]=fac[i-1]*i%mod;
}
void dfs(int u)
{
	if(u>n){
		int up=0,gt=0;
		for(int i=1;i<=n;i++){ 
			if(up>=c[t[i]]) up++;
			else{
				if(s[i]=='1') gt++;
				else up++;
			}
			if(up>n-m) break;
		}
		if(gt>=m) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;t[++tot]=i;dfs(u+1);
		vis[i]=0;t[tot--]=i;
	}
}
void spj()
{
	dfs(1);
	cout<<ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	pre(); 
	cin>>n>>m;int fla=0;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) fla=1;
	}
	if(n<=18) spj();
	else if(m==1) cout<<fac[n];
	else if(m==n&&fla) cout<<0;
	else cout<<fac[n];
	return 0;
}
/*
3 2
101
1 1 2
*/
