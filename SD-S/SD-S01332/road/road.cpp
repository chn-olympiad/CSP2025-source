#include<bits/stdc++.h>
#define file(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
using namespace std;
typedef long long ll;
namespace FastIO{
	template<typename T=int>T read(){
		T x=0;int f=1;char c=getchar();
		while(!isdigit(c)){if(c=='-') f=~f+1;c=getchar();};
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		return x*f;
	}
	template<typename T>void write(T x){
		if(x<0) putchar('-'),x=~x+1;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
	template<typename T>void Write(T x,char c='\n'){
		write(x),putchar(c);
	}
}
using namespace FastIO;
const int maxm=1e6+5;
const int maxn=1e4+25;
struct Node{
	int u,v,w;
}e[maxm];
int c[12],a[12][maxn],f[maxn],id[12];
int get(int x){
	return f[x]==x?x:f[x]=get(f[x]);
}
void Yorushika(){
	int n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1,[](Node A,Node B){return A.w<B.w;});
	for(int i=1;i<=n;i++) f[i]=i;
	ll ans=0;
	vector<Node>pre;
	for(int i=1;i<=m;i++){
		int u=get(e[i].u),v=get(e[i].v);
		if(u==v) continue;
		ans+=e[i].w,f[u]=v,pre.push_back(e[i]);
	}
	for(int i=0;i<k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	for(int S=0;S<1<<k;S++){
		vector<Node>E;
		int N=n,now=0;ll ret=0;
		for(int j=0;j<k;j++) id[j]=0;
		for(int j=0;j<k;j++) if(S&(1<<j)) id[j]=++N,ret+=c[j];
		for(int i=1;i<=N;i++) f[i]=i;
		for(int i=0;i<pre.size();i++) E.push_back(pre[i]);
		for(int j=0;j<k;j++) if(id[j])
			for(int i=1;i<=n;i++) E.push_back((Node){id[j],i,a[j][i]});
		sort(E.begin(),E.end(),[](Node A,Node B){return A.w<B.w;});
		for(int i=0;i<E.size();i++){
			int u=get(E[i].u),v=get(E[i].v);
			if(u==v) continue;
			f[u]=v,ret+=E[i].w,now++;
			if(now==N-1) break;
		}
		ans=min(ans,ret);
	}
	write(ans);
}
int main(){
	file("road");
	int Tc=1;
	while(Tc--) Yorushika();
	return 0;
}
