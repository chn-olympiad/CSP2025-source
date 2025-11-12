#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
int n,m,k,ans,csum;
const int maxn = 2e4+1000;
int head[maxn],to[maxn*4],nxt[maxn*4],w[maxn*4],tot;
int head2[maxn],to2[maxn*4],nxt2[maxn*4],w2[maxn*4],tot2;
int nm[maxn],dis[maxn];
int c[maxn/2],a[maxn/2][maxn/2];
bitset<maxn> active,flag[maxn],vis;
struct Node{
	int u,v,w;
	bool friend operator < (Node a,Node b){
		return a.w<b.w;
	}
}dis2[maxn];
vector<Node> toedge;
void add_edge(int U,int V,int W){
	nxt[++tot]=head[U];
	head[U]=tot;
	to[tot]=V;
	w[tot]=W;
	toedge.push_back((Node){U,V,W}); 
}
void add_edge2(int U,int V,int W){
	nxt2[++tot2]=head2[U];
	head2[U]=tot2;
	to2[tot2]=V;
	w2[tot2]=W;
}
int findx(int x){
	if(nm[x]!=x) return nm[x]=findx(nm[x]);
	return x;
}
void gugugu(){
	for(auto a:toedge){
		//cout<<"edge "<<a.w<<endl;
		if(findx(a.u)!=findx(a.v)){
			//cout<<findx(a.u)<<" "<<findx(a.v)<<endl;
			//cout<<"aa";
			//if(a.u>n&&(a.u-n-1-a.v||!active[a.u-n-1-a.v])) continue;
			//if(a.v>n) active[a.v-n-1-a.u]=1;
			//cout<<"connect "<<a.u<<" "<<a.v<<" "<<a.w<<endl;
			ans+=a.w;
			nm[findx(a.u)]=findx(a.v);
		}
	}
}
struct Node2{
	int dis,node;
	bool friend operator < (Node2 a,Node2 b){
		return a.dis<b.dis;
	}
};
priority_queue<Node2> q;
void kukuku(){
	memset(dis,0x3f,sizeof(dis));
	q.push((Node2){0,1});
	dis[1]=0;
	//vis[1]=1;
	while(!q.empty()){
		Node2 c=q.top();q.pop();
		if(vis[c.node]) continue;
		vis[c.node]=0;
		for(int i=head[c.node];i;i=nxt[i]){
			if(dis[to[i]]>dis[c.node]+w[i]){
				dis[to[i]]=dis[c.node]+w[i];
				dis2[to[i]]=(Node){to[i],c.node,w[i]};
			}
			q.push((Node2){dis[to[i]],to[i]});
			vis[c.node]=1;
		}
	}
	for(int i=1;i<=n;i++) ans+=dis[i];
	//for(int i=1;i<=n;i++) cout<<"dis2 "<<i<<" "<<dis2[i].v<<endl;
	/**
	memset(dis2,0x3f,sizeof(dis2));
	q.push((Node2){0,1});
	vis.reset();
	dis2[1]=0;
	while(!q.empty()){
		Node2 c=q.top();q.pop();
		if(vis[c.node]) continue;
		vis[c.node]=1;
		for(int i=head[c.node];i;i=nxt[i]){
			if(dis2[to[i]]>dis2[c.node]+w[i]){
				dis2[to[i]]=dis2[c.node]+w[i];
				if(dis2[to[i]]==dis[to[i]]){
					add_edge2(to[i],c.node,w[i]);
					add_edge2(c.node,to[i],w[i]);
				}
			}
			q.push((Node2){dis2[to[i]],to[i]});
		}
	}**/
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	// ** 1~4 样例没给 
	ans=0;
	//memset(edge,0x3f,sizeof(edge));
	for(int i=0;i<=n;i++) nm[i]=i;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]==0){
			cout<<0;
			return 0;
		}
		csum+=c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	// 13~14样例3 A似乎有误，样例并不满足A，即cj都为0 
	if(k==0){
		gugugu();
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=k;i++){
		// build multi treeeeeeeee
		for(int d=1;d<=n;d++){
			add_edge(d,n+i+1+k*(i-1)+d,c[i]);
			nm[n+i+1+k*(i-1)+d]=n+i+1+k*(i-1)+d;
			for(int j=1;j<=n;j++){
				//add_edge(n+i+1+j,j,c[i]);
				add_edge(n+i+1+k*(i-1)+d,j,a[i][j]);
				//add_edge(j,n+i+1+k*(i-1),a[i][j]);
			}
		}
	}
	kukuku();
	cout<<ans<<endl;
	return 0;
}
