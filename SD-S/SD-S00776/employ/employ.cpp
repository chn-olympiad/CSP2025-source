#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
const ll mod=998244353;
namespace abc_{

int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
void print(ll x){
	if(x<0) putchar('-'),x=-x;
	if(x>9) print(x/10);
	putchar('0'+x%10);
	return ;
}

int n,m,c[N],rd[N];
ll ans;
bool can[N],vis[N];
string s;
void dfs(int x){
	if(x>n){
		int cnt=0,tot=0;
		for(int i=1;i<=n;++i){
			if(c[rd[i]]>tot&&can[i]==1) cnt++;
			else tot++;
			if(cnt>=m){
				ans++;
				return ;
			}
			if(cnt+n-i<m) return ;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		rd[x]=i;
		dfs(x+1);
		rd[x]=0;
		vis[i]=false;
	}
}
int my_main(){
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;++i) c[i]=read();
	for(int i=1;i<=n;++i) can[i]=(s[i-1]=='1');
	dfs(1);
	ans%=mod;
	print(ans);
	return 0;
}

}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	abc_::my_main();
	return 0;
}
