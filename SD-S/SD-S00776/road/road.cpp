#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e7+10;
const int M=1e3+10;
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

struct edge{
	int from,to,val,ty;
}e[N];
bool cmp(edge x,edge y){
	return x.val<y.val;
}
int n,m,k,tot,mon[33],low[33][M],fa[M];
pair<int,int> g[M][M];
bool can[33];
ll ans,sum;
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
bool flag;
void kruskal(){
	flag=false;
	sort(e+1,e+tot+1,cmp);
	for(int i=1;i<=tot;++i){
		int u=e[i].from,v=e[i].to;
		if(find(u)==find(v)) continue;
		if(!can[e[i].ty]){
			can[e[i].ty]=true;
			sum+=mon[u];
			for(int a=1;a<=n;++a){
				if(u>a) swap(u,a);
				e[++tot]={u,a,g[u][a].first-mon[u],u};
			}
			flag=true;
			break;
		}
		fa[u]=v;
		ans+=e[i].val;
	}
	if(flag) kruskal();
	return ;
}
int my_main(){
	n=read();m=read();k=read();
	can[0]=true;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=m;++i){
		int u,v,w;
		u=read(),v=read(),w=read();
		if(u>v) swap(u,v);
		e[++tot]={u,v,w,0};
	}
	for(int i=1;i<=k;++i){
		mon[i]=read();
		for(int j=1;j<=n;++j){
			low[i][j]=read();
		}
		for(int a=1;a<=n;a++){
			for(int b=a+1;b<=n;b++){
				if(g[a][b].first==0||g[a][b].first>low[i][a]+low[i][b]+mon[i])
					g[a][b]={low[i][a]+low[i][b]+mon[i],i};
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			e[++tot]={i,j,g[i][j].first,g[i][j].second};
		}
	}
	kruskal();
	print(ans+sum);
	return 0;
}

}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	abc_::my_main();
	return 0;
}
