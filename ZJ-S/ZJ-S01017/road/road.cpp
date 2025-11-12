#include<bits/stdc++.h>
using namespace std;
long long n,m,k,c[15],tot,fa1[10005],ans,dis[20][10005],p[10005],d[10005],b[20005],f[20005][20],euler[10005],cnt,size[10005];
bool vis[100005];
struct data{
	int u,v;
	long long w;
}a[10100005];
struct node{
	int t,v;
};
vector<node>g[10005];
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
bool cmp(data a,data b){
	return a.w<b.w;
}
int getfa(const int x){
	if(fa1[x]==x)return x;
	return fa1[x]=getfa(fa1[x]);
}
//int min1(int x,int y){
//	return d[x]<d[y]?x:y;
//}
//void dfs(int x,int fa){
//	b[++cnt]=x;
//	d[x]=d[fa]+1;
//	euler[x]=cnt;
//	for(int i=0;i<g[x].size();++i){
//		if(g[x][i].t==fa)continue;
//		dfs(g[x][i].t,x);
//		b[++cnt]=x;
//	}
//}
//int query(int x,int y){
//	if(x>y)swap(x,y);
//	int k=log2(y-x+1);
//	return min1(f[x][k],f[y-(1<<k)+1][k]);
//}
//void bfs(){
//	queue<int>q;
//	q.push(1);
//	p[1]=0;
//	while(!q.empty()){
//		int x=q.front();
//		vis[x]=true;
//		q.pop();
//		for(int i=0;i<g[x].size();++i){
//			if(vis[g[x][i].t])continue;
//			p[g[x][i].t]=p[x]+g[x][i].v;
//			q.push(g[x][i].t);
//		}
//	}
//}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i)fa1[i]=i,size[i]=1;
	for(int i=1;i<=m;++i){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	for(int i=1;i<=k;++i){
		c[i]=read();
		for(int j=1;j<=n;++j){
			dis[i][j]=read();
		}
		for(int j=1;j<=n;++j){
			for(int p=j+1;p<=n;++p){
				m++;
				a[m].u=j;
				a[m].v=p;
				a[m].w=dis[i][j]+dis[i][p]+c[i];
			}
		}
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;++i){
		int fx=getfa(a[i].u),fy=getfa(a[i].v);
		if(fx!=fy){
			if(size[fx]>size[fy])swap(fx,fy);
			size[fx]+=size[fy];
			fa1[fx]=fy;
			tot++;
			ans+=a[i].w;
//			g[a[i].u].push_back({a[i].v,a[i].w});
//			g[a[i].v].push_back({a[i].u,a[i].w});
		}
		if(tot==n-1){
			break;
		}
	}
	cout<<ans<<'\n';
	return 0;
//	if(k==0){
//		cout<<ans<<'\n';
//		return 0;
//	}
//	bfs();
//	dfs(1,0);
//	for(int i=1;i<=cnt;++i)f[i][0]=b[i];
//	int k=log2(cnt);
//	for(int j=1;j<=k;++j){
//		for(int i=1;i<=cnt-(1<<j)+1;++i){
//			f[i][j]=min1(f[i][j-1],f[i+(1<<(j-1))][j-1]);
//		}
//	}
//	for(int i=1;i<=k;++i){
//		for(int j=1;j<=n;++j){
//			
//		}
//	}
//	cout<<ans<<'\n';
//	return 0;
}
/*
4 4 0
1 2 2
2 3 3
1 3 1
3 4 1
*/
