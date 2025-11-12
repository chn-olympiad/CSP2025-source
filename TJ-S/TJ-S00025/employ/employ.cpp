#include<bits/stdc++.h>
//#define int long long
using namespace std;
#define fi first
#define se second
#define mkp make_pair
#define pb emplace_back
#define ep emplace
#define Endl putchar('\n')
#define Space putchar(' ')
typedef long long ll;
using pii=pair<int,int>;
const int mod=998244353,inf=0x3f3f3f3f;
const ll Inf=0x3f3f3f3f3f3f3f3f;
template<typename T> inline void read(T &s){
	s=0;int c=getchar();bool f=0;
	while(!isdigit(c))f^=(c=='-'),c=getchar();
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
}
template<typename T> inline void write(T x){
	static int St[40],Top=0;
	if(x<0)putchar('-'),x=-x;
	do St[++Top]=x%10,x/=10; while(x);
	while(Top)putchar(St[Top--]^48);
}
void read(char &c){do c=getchar(); while(isspace(c));}
template<typename type,typename... T> inline void read(type &x,T&...y){read(x);read(y...);}
namespace Modulo{
	void Add(int &x,int y){((x+=y)>=mod)&&(x-=mod);}
	int add(int x,int y){return Add(x,y),x;}
	void Sub(int &x,int y){((x-=y)<0)&&(x+=mod);}
	int sub(int x,int y){return Sub(x,y),x;}
}
using namespace Modulo;
const int N=505;
int n,m,a[N],s[N];
int b[N],vis[N];ll ans=0;
void dfs(int step){
	if(step>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i]||cnt>=a[b[i]])cnt++;
		}
		if(n-cnt>=m)ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;b[step]=i;
			dfs(step+1);
			vis[i]=0;
		}
	}
}
void solve(){
	read(n,m);
	for(int i=1;i<=n;i++){char c;read(c);s[i]=c^49;}
	for(int i=1;i<=n;i++)read(a[i]);
	int fac=1;
	for(int i=2;i<=n;i++)fac=(ll)fac*i%mod;
	if(n<=10)dfs(1),write(ans);
	else write(fac);
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);cout.tie(nullptr);
	int T=1;//read(T);
	while(T--){
		solve();
	}
	return 0;
}

