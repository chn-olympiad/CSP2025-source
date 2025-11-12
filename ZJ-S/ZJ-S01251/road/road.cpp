#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=1e13;
const int maxn=1e4+100;
struct node{
	int u,v;
	ll val;
	friend bool operator<(node a,node b){
		if (a.val<b.val) return false;
		return true;
	}
};
int n,m,k;
priority_queue<node> aq;
int fa[maxn];
int pay[15];
int ak[maxn][15];
void init(){//O(n+k)
	for (int i=1;i<maxn;i++){
		fa[i]=i;
	}
}
//O(logn)
int find(int x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}int merge(int x,int y){
	int fx=find(x),fy=find(y);
	fa[max(fx,fy)]=min(fx,fy);
}
ll ans;
ll cost;
void prim(priority_queue<node> q,int need_n){//(O((m+n*k)*log(m+n*k));->1e8
	init();
	int edge=0;
	while (edge!=need_n-1){
		node fr=q.top();
		q.pop();
		int u=fr.u,v=fr.v,val=fr.val;
		if (find(u)!=find(v)){
			merge(u,v);
			edge++;
			cost+=val;
			if (cost>=ans) return;
		}
	}ans=min(ans,cost);
}
void solve(){//->1e11
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++){
		int u,v,val;
		cin>>u>>v>>val;
		aq.push((node){u,v,val});
	}
	for (int j=1;j<=k;j++){
		cin>>pay[j];
		for (int i=1;i<=n;i++){
			cin>>ak[i][j];
		}
	}ans=INF;
	
	int maxs=(1<<k)-1;
	for (int flag=0;flag<=maxs;flag++){
		cost=0;
		int tmp=flag;
		priority_queue<node> tmpq=aq;
		vector<int> deal;
		int t=1;
		while (tmp){
			if (tmp&1){
				deal.push_back(t);
			}t++;
			tmp>>=1;
		}
		for (int i=0;i<deal.size();i++){
			int add_pos=deal[i];
			cost+=pay[add_pos];
			for (int j=1;j<=n;j++){
				tmpq.push((node){j,n+i+1,ak[j][add_pos]});
			}
		}
		prim(tmpq,n+deal.size());
	}
	cout<<ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
