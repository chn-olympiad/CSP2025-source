#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
	x=0;char v=getchar();int f=1;
	while(v<'0'||v>'9'){
		if(v=='-') f=-1;
		v=getchar();
	}
	while(v>='0'&&v<='9'){
		x=(x<<1)+(x<<3)+(v&15);
		v=getchar(); 
	}
	x*=f;
}
const int N = 1000010;
int n,m,k;
int u,v,w;
int c[N],a;
struct edge{
	int nxt,to,val;
}E[N];
int h[N],cnt;
void add(int u,int v,int w){
	cnt++;
	E[cnt].to=v;
	E[cnt].val=w;
	E[cnt].nxt=h[u];
	h[u]=cnt;
	return ;
}
struct node{
	int id,val;
	bool operator < (const node &x) const{
		if(val==x.val) return id<x.id;
		return val<x.val;
	}
};
int dis[N],vis[N];
int us[N];
void dij(int s){
	priority_queue<node> q;
	memset(vis,0,sizeof vis);
	q.push((node){s,0});
	for(int i=1;i<=n+k*n;i++) dis[i]=INT_MAX;
	for(int j=1;j<=k;j++) dis[j+n]=c[j+n];
	while(!q.empty()){
		node v=q.top();
		q.pop();
//		cout<<v.id<<' '<<v.val<<endl;
		if(vis[v.id]) continue;
		vis[v.id]=1;
		for(int i=h[v.id];i;i=E[i].nxt){
			int to=E[i].to;
			if(dis[to]>E[i].val+v.val){
//				cout<<1<<'s';
				if(v.id>n) us[v.id];
				else us[v.id]=0;
				dis[to]=E[i].val+v.val;
				q.push((node){to,dis[to]});
			}
		}
	}
}
struct edg{
	int u,v,w=INT_MAX;
}e[N];
int f[N];
int find(int x){
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
bool cmp(edg x,edg y){
	return x.w<y.w;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++){
		read(u),read(v),read(w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		read(c[i+n]);
		for(int j=1;j<=n;j++){
			read(a);
			add(i+n,j,a);
			add(j,i+n,a);
		}
	}
	int len=0;
	for(int i=1;i<=n;i++){
		dij(i);
		for(int j=i+1;j<=n;j++){
//			cout<<dis[j]<<' '<<j<<' '<<i<<endl;
			len++;
			e[len].u=i,e[len].v=j,e[len].w=min(e[len].w,dis[j]);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+1+len,cmp);
	for(int i=1;i<=len;i++){
		int x=find(e[i].u),y=find(e[i].v); 
		if(x!=y){
//			cout<<e[i].w<<endl;
			f[x]=y;
			ans+=e[i].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}