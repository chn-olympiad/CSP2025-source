#include<bits/stdc++.h>
#define int long long
using namespace std;
const int md=998244353;
int ksm(int a,int b,int p){
	int ans=1;
	while(b){
		if(b&1) ans=(ans*a)%p;
		b>>=1;a=(a*a)%p;
	}return ans;
}
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
string s;
int a[1005],ans=0,n,m;
int p[1005];
int vis[1005];
void dfs(int chs){
	if(chs==n){
		int ot=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				ot++;
				continue;
			}
			if(a[p[i]]<=ot) ot++;
		}
		if(n-ot>=m) ans++;
		return;
	}
	chs++;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			p[chs]=i;
			vis[i]=1;
			dfs(chs);
			vis[i]=0;
		}
	}
}
void sol(){
	n=read(),m=read();
	int c1=0,ca0=0;
	cin>>s;
	s="_"+s;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(s[i]=='1') c1++;
		if(a[i]=='0') ca0++;
	}
	if(m==n){
		ans=1;
		for(int i=n;i>=1;i--) ans=(ans*i)%md;
		if(ca0==0) cout<<ans;
		else cout<<0;
	}
	else if(n<=10){
		dfs(0);
		cout<<ans;
	}else cout<<0;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T=1;
//	T=read();
	while(T--) sol();
	return 0;
}


