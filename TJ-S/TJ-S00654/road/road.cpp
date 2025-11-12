#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
const int M = 1e6+10;

int ans=1e15,ncost,yc;
int n,m,k;
int cst[N],father[N],sz[N],mined[15],bn=-1;

struct node2{
	int cs;
	int id;
}b[15];

bool cmp2(node2 x,node2 y){
	return x.cs<y.cs;
}

struct Edge{
	int u,v,w;
};

struct cmp{
	bool operator() (const Edge &x,const Edge &y){
		return x.w>y.w;
	}
};

priority_queue<Edge,vector<Edge>,cmp> q;
vector<Edge> edge;

struct node{
	int to,w;
};
vector<node> vll[15];

void init_f(){
	for(int i=1;i<=n+k;i++){
		father[i]=i;
		sz[i]=1;
	}
}
int find(int x){
	return (x==father[x]?x:father[x]=find(father[x]));
}
void join(int x,int y){
	int fx=find(x),fy=find(y);
	if(sz[fx]>sz[fy]) swap(fx,fy);
	father[fx]=fy;
}

void buildtree(int num,int cnt=0){
	init_f();
	while(!q.empty()&&cnt<num-1){
		Edge cur=q.top();
		q.pop();
		int fx=find(cur.u),fy=find(cur.v);
		if(fx==fy) continue;
		++cnt;
		join(fx,fy);
		ncost+=cur.w;
	}
	b[++bn].cs=ncost,b[bn].id=bn;
	ans=min(ncost,ans);
	while(!q.empty()){
		q.pop();
	}
}

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Edge tmp;
		tmp.u=u,tmp.v=v,tmp.w=w;
		edge.push_back(tmp);
		q.push(tmp);
	}
	for(int i=1;i<=k;i++){
		cin>>cst[i];
		for(int j=1;j<=n;j++){
			int cc;
			cin>>cc;
			node tmp;
			tmp.to=j,tmp.w=cc;
			vll[i].push_back(tmp);
		}
	}
	buildtree(n);
	for(int i=1;i<=k;i++){
		ncost=0;
		ncost+=cst[i];
		for(int a=0;a<vll[i].size();a++){
			Edge tmp;
			tmp.u=n+1,tmp.v=vll[i][a].to,tmp.w=vll[i][a].w;
			q.push(tmp);
		}
		for(int i=0;i<m;i++){
			q.push(edge[i]);
		}
		buildtree(n+1);
	}
	sort(b+1,b+k+1,cmp2);
	for(int l=1;l<=k;l++){
		int i=b[l].id;
		ncost=0;
		while(!q.empty()){
			q.pop();
		}
		for(int j2=1;j2<=l;j2++){
			int j=b[j2].id;
			ncost+=cst[j];
			for(int a=0;a<vll[j].size();a++){
				Edge tmp;
				tmp.u=n+j2,tmp.v=vll[j][a].to,tmp.w=vll[j][a].w;
				q.push(tmp);
			}
		}
		
		for(int i=0;i<m;i++){
			q.push(edge[i]);
		}
		buildtree(n+l);
		if(ncost>ans) break;
	}
	cout<<ans;
	return 0;
} 
