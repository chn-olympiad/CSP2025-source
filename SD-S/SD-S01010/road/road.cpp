#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!(c>='0'&&c<='9')){c=getchar();}
	while((c>='0'&&c<='9')){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
struct edge{
	int u,v,w;
}a[2005000];
bool operator<(const edge& a,const edge& b){
	return a.w<b.w;
}
int b[15][20005],fa[20050];
int find(int u){
	while(u!=fa[u]) u=fa[u]=fa[fa[u]];
	return u;
}
vector<edge> v,q;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read(),m=read(),k=read();
	long long res=0;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		a[i].u=read(),a[i].v=read(),a[i].w=read();
	}
	for(int i=1;i<=k;++i){
		b[i][0]=read();
		for(int j=1;j<=n;++j){
			b[i][j]=read();
		}
	}
	int ans=0;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		int fu=find(a[i].u),fv=find(a[i].v);
		if(fu==fv) continue;
		fa[fu]=fv;
		res+=a[i].w;
		v.push_back(a[i]);
	}
	for(int bit=0;bit<(1<<k);++bit){
		long long ans=0;
		int cnt=0,cnnn=0;
		for(int i=1;i<=n+k;++i) fa[i]=i;
		q=v;
		for(int i=1;i<=k;++i){
			if((bit>>i)&1){
				for(int j=1;j<=n;++j) q.push_back((edge){i+n,j,b[i][j]});
				ans+=b[i][0];
				++cnt;
			}
		}
		sort(q.begin(),q.end());
		for(auto c:q){
			int fu=find(c.u),fv=find(c.v);
			if(fu==fv) continue;
			fa[fu]=fv;
			ans+=c.w;
			++cnnn;
			if(cnnn>=cnt+n) break;
		}
		res=min(res,ans);
	}
	cout<<res;
}
