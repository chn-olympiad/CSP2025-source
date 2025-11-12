#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m,k,u,v,w,minl[N],cnt,tn[12][N],cost[12];
bool f[N];
vector <int> a[N];
//struct road{
//	int u,v,w;
//}r[1000005];
map <pair<int,int>,int> c;
long long ans;
void bfs(){
	int u;
	queue<int > q;
	q.push(1);
	while(!q.empty()){
		u=q.front();
		
		for(int i=1;i<a[u].size();i++){
			if(c[make_pair(u,a[u][i])]==minl[u]){
				ans+=minl[u];
				q.push(a[u][i]);
			}
		}
		q.pop();
	}
}

int main(){
//	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		a[u].push_back(v),a[v].push_back(u);
		if(c[make_pair(u,v)]!=0)c[make_pair(u,v)]=c[make_pair(v,u)]=min(m,c[make_pair(u,v)]);
		else c[make_pair(u,v)]=c[make_pair(v,u)]=w;
		if(minl[u]!=0) minl[u]=min(minl[u],w);
		else minl[u]=w;
		if(minl[v]!=0) minl[v]=min(minl[v],w);
		else minl[v]=w; 
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&cost[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&tn[i][j]);
		}
	}
	cout<<ans;
	return 0;
}
