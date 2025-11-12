#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define fir first
#define sec second
#define file(_1) freopen(_1".in","r",stdin),freopen(_1".out","w",stdout);
#define error(_) cerr<<_<<endl
#define look_memory cerr<<(&m2-&m1)/1024.00/1024.0<<"MB"<<endl;
#define look_time cerr<<(t2-t1)/1000.0<<"s"<<endl;
using namespace std;
template <typename T>
inline void read(T &x){
	T f=1,c=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)){
		c=(c<<3)+(c<<1)+(ch^48);
		ch=getchar();
	}
	x=f*c;
}

template<typename T,typename ...Args>
inline void read(T &x,Args &...args){
	read(x),read(args...);
}
namespace white_carton{
	const int mod=998244353;
	int n,m,c[510],vis[510],fac[510],w[510],ans;
	string s;
	void dfs(int u,int sum){
		if(sum==m){
			ans+=fac[n-u+1];
			return;
		}
		if(u==n+1){
			if(sum>=m){
				ans++;
			}
			return;
		}
		if(sum+(n-u+1)-w[u]<m){
			return;
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				continue;
			}
			vis[i]=1;
			if(s[u]=='0'){
				dfs(u+1,sum);
			}
			else{
				if(c[i]<=u-1-sum){
					dfs(u+1,sum);
				}
				else{
					dfs(u+1,sum+1);
				}
			}
			vis[i]=0;
		}
	}
	void solve(){
		cin>>n>>m;
		fac[0]=1;
		for(int i=1;i<=n;i++){
			fac[i]=fac[i-1]*i%mod;
		}
		cin>>s;
		s="0"+s;
		for(int i=n;i>=1;i--){
			w[i]=w[i+1]+(s[i]=='0');
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		if(n<=18){
			dfs(1,0);
			cout<<ans<<endl;
			return;
		}
		if(n==m){
			int flag=0;
			for(int i=1;i<=n;i++){
				if(c[i]==0){
					flag=1;
				}
			}
			if(flag){
				cout<<0<<endl;
			}
			else{
				cout<<fac[n]<<endl;
			}
			return;
		}
	}
}
int T=1;
signed main(){
	file("employ");
//	T=read();
	while(T--){
		white_carton::solve();
	}
}
//1.快读
//2.注意空间
//3.多测清数据
//4.对拍
//5.打满暴力
//6.文件
//7. RP++;



//starback24

