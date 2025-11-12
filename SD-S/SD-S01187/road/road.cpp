#include<bits/stdc++.h>
using namespace std;
const int N=10010,M=1000010;
#define int long long
inline int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct edge{
	int u,v,w;
}e[M<<1];
int cnt;
int vis[1010][1010];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int f[N],size[N];
int find(int x){
	if( f[x]==x )return x;
	return f[x]=find(f[x]);
}
int n,m,k,c[20],a[20][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		++cnt;
		e[cnt].u=read(),e[cnt].v=read(),e[cnt].w=read();
		vis[e[cnt].u][e[cnt].v]=vis[e[cnt].u][e[cnt].v]=1;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=k;j++){
			e[i].w=min( e[i].w,a[j][e[i].u]+a[j][e[i].v] );
		}
	}
	for(int i=1;i<=n;i++){
		if(k==0)break;
		for(int j=1;j<=n;j++){
			if(!vis[i][j]){
				e[++cnt]={i,j,0x3f3f3f3f3f3f3f3f};
				for(int p=1;p<=k;p++){
					e[cnt].w=min(e[cnt].w,a[p][i]+a[p][j]);
				}
				vis[j][i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if( fu!=fv ){
			f[fu]=fv;
			size[fv]+=size[fu]+e[i].w;
		}
	}
	cout<<size[find(1)]<<endl;
	return 0;
}
/*

*/
