#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

typedef unsigned int uint;
typedef long long llint;
typedef unsigned long long ullint;

struct edge{
	int to,q;
	
	bool operator<(const edge& other) const{
		return q>other.q;
	}
}; 
vector<edge> a[10050];
bool vis[10050]; 
int n,m,k;
llint uu[12]={};

llint Prim(int s,int tk){
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	priority_queue<edge> pq;
	for(int i=0;i<a[s].size();i+=1){
		pq.push(a[s][i]);
	}
	edge t;
	llint ans=0;
	while(!pq.empty()){
		t=pq.top();
		pq.pop();
		if(vis[t.to]){
			continue;
		}
		
		if(t.to>n && (((1<<(t.to-n-1))&tk)==0)){
			continue;
		}
		//fprintf(stderr,"%d %d %d %d\n",t.to,t.q,n,tk);
		ans+=t.q;
		vis[t.to]=1;
		for(int i=0;i<a[t.to].size();i+=1){
			pq.push(a[t.to][i]);
		}
	}
	return ans;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=0;i<m;i+=1){
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w}); 
	}
	for(int i=0;i<k;i+=1){
		cin>>uu[i];
		for(int j=1;j<=n;j+=1){
			cin>>w;
			a[n+i+1].push_back({j,w});
			a[j].push_back({n+i+1,w});
		}
	}
	llint ans=0x7f7f7f7f7f7f7f7f,tt;
	//fprintf(stderr,"%d\n",k);
	for(int t=0;t<(1<<k);t+=1){
		tt=0;
		for(int i=0;i<k;i+=1){
			if(t&(1<<i)){
				tt+=uu[i];
			}
		}
		//fprintf(stderr,"%d,",tt);
		tt+=Prim(1,t);
		//fprintf(stderr,"%d\n",tt);
		if(tt<ans){
			ans=tt;
		}
	}
	cout<<ans<<endl;
	return 0;
}

