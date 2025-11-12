#include<bits/stdc++.h>
using namespace std;
long long n,m,k,vis[10015],V[15],vis2[15];long long d[10015],e=2e18;
struct node{
	long long v,l;
	bool operator <(const node &x)const{
		return l>x.l;
	}
};
struct node2{
	long long v,l;
};
vector<node2> a[10005];
priority_queue<node> Q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		a[u].push_back({v,w});
		a[v].push_back({u,w});
	}
	int cnt=0;
	for(int i=1;i<=k;i++){
		int y;
		cnt++;
		cin>>V[n+cnt];
		for(int i=1;i<=n;i++){
			cin>>y;
			a[i].push_back({n+cnt,y});
			a[n+cnt].push_back({i,y});
		}
	}
	for(int p=1;p<=n;p++){
		for(int i=1;i<=n+k;i++){
			d[i]=1e9;
		}
		d[p]=0;
		memset(vis,0,sizeof(vis));
		Q.push({p,0});
		while(Q.size()){
			node U=Q.top();
			long long u=U.v;
			Q.pop();
			if(vis[u])continue;
			vis[u]=1;
			for(int i=0;i<a[u].size();i++){
				int f=0;
				int v=a[u][i].v;
				long long l=a[u][i].l;
				if(v>n){
					if(!vis2[v-n]){
						if(d[v]>d[u]+l+V[v-n]){
							d[v]=d[u]+l+V[v-n];
							Q.push({v,d[v]});
							vis2[v-n]=1;
							f=1;
						}
						else continue;
					}		
				}
				if(!f) 
				if(d[v]>d[u]+l){
					d[v]=d[u]+l;
					Q.push({v,d[v]});
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		if(d[i]!=1e9)
		ans+=d[i];
		if(ans<e)e=ans;
	}
	cout<<e<<"\n";
	return 0;
}
/*
5 6 0
1 2 1
1 4 3
2 4 2
2 3 6
2 5 1
4 5 5

4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/