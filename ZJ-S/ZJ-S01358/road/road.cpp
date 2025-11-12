#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int N=1e4+105,M=1e6+105,K=15;
int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,k,a[K][N],c[K];
struct edge{
	int u,v;
	ll w;
}e[M],e2[K*N],e3[M+K*N];
bool operator <(edge a,edge b){
	return a.w<b.w;
}
int fa[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	for(int i=1;i<=k;i++){
		int pos=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0) pos=j;
		}
		for(int j=1;j<=n;j++){
			if(j!=pos) e[++m]=(edge){pos,j,a[i][j]};
		}
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	ll ans=0,cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		fa[fv]=fu;
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1) break;
	}
	cout<<ans<<'\n';
}
void solve2(){
	ll ans=1e18;
	sort(e+1,e+m+1);
	for(int i=0;i<(1<<k);i++){
		ll res=0,cnt=0,t=0,tmp=0;
		for(int j=0;j<k;j++){
			if(i&(1<<j)){
				t++;
				res+=c[j+1];
				for(int l=1;l<=n;l++) e2[++tmp]=(edge){n+j+1,l,a[j+1][l]};
			}
		}
		sort(e2+1,e2+tmp+1);
		ll u=1,v=1,len=0;
		while(u<=m||v<=tmp){
			if(e[u].w<e2[v].w||v>tmp){
				e3[++len].u=e[u].u;
				e3[len].v=e[u].v;
				e3[len].w=e[u].w;
				u++;
			}else{
				e3[++len].u=e2[v].u;
				e3[len].v=e2[v].v;
				e3[len].w=e2[v].w;
				v++;
			}
		}
		for(int j=1;j<=n+k;j++) fa[j]=j;
		for(int j=1;j<=len;j++){
			int fu=find(e3[j].u),fv=find(e3[j].v);
			if(fu==fv) continue;
			fa[fv]=fu;
			res+=e3[j].w;
			cnt++;
			if(cnt==n+t-1) break;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
int main(){	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(int i=1;i<=k;i++){
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read();
	}
	int pd=1;
	for(int i=1;i<=k;i++){
		int f=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]==0) f=1;
		}
		if(!f) pd=0;
	}
	if(pd||(k==0)) solve1();
	else solve2();
	return 0; 
}
/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4



*/

