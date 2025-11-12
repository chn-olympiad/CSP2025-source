#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
const int maxn=1e4+10,maxm=1e6+10,MAX=1e15;
struct edgel{
	int u,v,w;
};
int n,m,k,fa[maxn],cnt,ans,rd[maxm][5],twn[15][maxn],c[15],bian[1010][1010],chice[15],bianl[1010][1010];
edgel edg[maxm];
int read(){
	char ch=getchar();
	int ansl=0;
	while(ch>'9' || ch<'0') ch=getchar();
	while(ch<='9' && ch>='0'){
		ansl*=10;
		ansl+=ch-'0';
		ch=getchar();
	}
	return ansl;
}
int fnd(int a){
	if(fa[a]==a) return a;
	fa[a]=fnd(fa[a]);
	return fa[a];
}
bool cmp(edgel a,edgel b){
	return a.w<b.w;
} 
void add(int u,int v,int w){
	edgel temp;
	temp.u=u,temp.v=v,temp.w=w;
	cnt++;
	edg[cnt]=temp;
}
void solve1(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		add(u,v,w);
	}
	sort(edg+1,edg+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=edg[i].u,v=edg[i].v;
		if(fnd(u)!=fnd(v)){
			fa[fnd(u)]=fnd(v);
			ans+=edg[i].w;
		}
	}
	cout<<ans;
	exit(0);
}
void solve2(){
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) bian[i][j]=MAX;
	}
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		bian[u][v]=w;
		bian[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) twn[i][j]=read();
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int o=1;o<=n;o++){
				bian[j][o]=min(bian[j][o],twn[i][j]+twn[i][o]);
			}
		}
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			add(i,j,bian[i][j]);
		}
	}
	sort(edg+1,edg+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=edg[i].u,v=edg[i].v;
		if(fnd(u)!=fnd(v)){
			fa[fnd(u)]=fnd(v);
			ans+=edg[i].w;
		}
	}
	cout<<ans;
	exit(0);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0) solve1();
	if(n<=1000) solve2();
	return 0;
}
