#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10020,M = 1100000+5;
int n,m,k,cnt,u,v,w,f[N],c[15],a[15][N],ans,uu,mnn=1e18;
bool vi[13];
struct node{
	int x,y,w;
}edge[M<<1];
/*int ver[M<<1],edg[M<<1],nxt[M<<1],h[N],tot;
void add(int u,int v,int w){
	ver[++tot] = v,edg[tot] = w,nxt[tot] = h[u],h[u]=tot;
}*/
bool cmp(node a,node b){
	return a.w < b.w;
}
int find(int x){
	if(x==f[x]) return x;
	else return find(f[x]);
}
int kruscal(){
	int res=0;
	sort(edge+1,edge+cnt+1,cmp);
	for(int i = 1;i <= cnt;i++){
		int w=edge[i].w;
		int fx=find(edge[i].x),fy=find(edge[i].y);
		if(fx==fy) continue;
		else{
			f[fx]=fy;
			res+=w;
		}
	}
	return res;
}
void dfs(int dep){
	if(dep==n){
		for(int i = 1;i <= n+k;i++) f[i]=i;
		ans=0,uu=cnt;
		for(int i = 1;i <= n;i++){
			if(vi[i]) {
				ans+=c[i];
				for(int j = 1;j <= n;j++){
					edge[++cnt].x=i+n,edge[cnt].y=j,edge[cnt].w=a[i][j];
					edge[++cnt].x=j,edge[cnt].y=i+n,edge[cnt].w=a[i][j];
				}
			}
		}
		int o = kruscal();
		//cout << o << "\n";
		mnn=min(mnn,o+ans);
		cnt=uu;
		return;
	}
	vi[dep+1]=1;
	dfs(dep+1);
	vi[dep+1]=0;
	dfs(dep+1);
}
signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m >> k;
	for(int i = 1;i <= n+k;i++) f[i]=i;
	for(int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		edge[++cnt].x=u,edge[cnt].y=v,edge[cnt].w=w;edge[++cnt].x=v,edge[cnt].y=u,edge[cnt].w=w;
		//add(u,v,w);
		//add(v,u,w);
	}
	bool t=1;
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		if(c[i]!=0) t=0;
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j]!=0) t=0;
		}
	}
	if(k<=0){
		cout << kruscal() << "\n";
		return 0;
	}
	else if(t){
		cout << 0 << "\n";
	}
	else{
		dfs(0);
		cout << mnn << "\n";
	}
	return 0;
}
