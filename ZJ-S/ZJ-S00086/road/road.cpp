#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e4+1;
struct Edge{
	int u;int v;int w;
	//bool used;
	bool operator <(Edge b) const{
		return w>b.w;
	}
};
int n,m,k,ans=0x3f3f3f3f;
priority_queue<Edge> mode;
//vector<Edge>mp[N];
int super[11][N];
int fat[N];
void init(int n){
	for(int i=1;i<=n;i++){
		fat[i]=i;
	}
}
int fa(int id){
	if(fat[id]==id);
	else {
		fat[id]=fa(fat[id]);
	}return fat[id];
}
bool is_m(int a,int b){
	return fa(a)==fa(b);
}
void merge(int a,int b){
	fat[fa(b)]=fa(a);
}
bool vis[11];

long long count(){
	init(n);priority_queue<Edge> que;
	long long cost_by_develop=0;
	long long ans=0;
	que=mode;Edge edge;
	for(int i=1;i<=k;i++){
		if(vis[i]){
			cost_by_develop+=super[i][0];
			for(int x=1;x<=n;x++){
				edge.u=x;
				for(int j=1;j<=n;j++){
					if(x==j)continue;
					edge.v=j;
					edge.w=super[i][j]+super[i][x];
					que.push(edge);
				}
			}
			//edge.u=i;
			
			
			
			
		}
	}
	//printf("cost %d on development\n",cost_by_develop);
	while(!que.empty()){
		Edge cur=que.top();
		que.pop();
		if(!is_m(cur.u,cur.v)){
			//printf("road from %d to %d with price %d has added\n",cur.u,cur.v,cur.w);
			merge(cur.u,cur.v);
			ans+=cur.w;
		}
	}
	return ans+cost_by_develop;
}
long long dfs(int dep=1){
	if(dep>k){
		long long ret=count();
		//cout<<ret<<endl;
		return ret;
	}
	long long ans=0x7f7f7f7f7f7f7f7f;
	vis[dep]=1;
	ans=min(ans,dfs(dep+1));
	vis[dep]=0;
	ans=min(ans,dfs(dep+1));
	return ans;
}
bool cmp(Edge a,Edge b){
	return a.w<b.w;
}
int main(){
	freopen("road2.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	init(n);
	priority_queue<Edge>que;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		Edge edge;
		edge.u=u;
		edge.v=v;
		edge.w=w;
		//edge.used=false;
		que.push(edge);
	}
	mode=que;
	
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++)cin>>super[i][j];
	}
	//cout<<count();
	cout<<dfs()<<endl;
	
	
}
