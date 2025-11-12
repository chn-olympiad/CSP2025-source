#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,w,c;
long long ans;
bool f[10100];
struct node{
	int dis;
	int vis;
	bool operator<(const node &x)const{
		return x.dis<dis;
	}
};
struct pa{
	int c;
	int s;
};
priority_queue<node> l;
vector<pa> a[10100];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&u,&v,&w);
		a[u].push_back((pa){v,w});
		a[v].push_back((pa){u,w});
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			a[n+i].push_back((pa){j,w});
			a[j].push_back((pa){n+i,w});
		}
	}
	n+=k;
	l.push((node){0,1});
	while(!l.empty()){
		node g=l.top();
		l.pop();
		if(f[g.vis]) continue;
		ans+=g.dis;
		f[g.vis]=1;
		int maxx=a[g.vis].size();
		for(int i=0;i<maxx;i++){
			if(f[a[g.vis][i].c]) continue;
			l.push((node){a[g.vis][i].s,a[g.vis][i].c});
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
