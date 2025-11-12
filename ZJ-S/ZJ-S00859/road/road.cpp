#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f
const int N=1e6+5,M=1e4+5;

ll n,m,k,ans,f[M][M];

ll opt[N],c[N];

bool flag;

struct node {
	ll u;
	ll v;
	ll w;
	bool operator<(const node &a)const {
		return w>a.w;
	}
};

priority_queue<node> q;


void kruskal() {
	int cnt=0;
	while(cnt<n-1) {
		ans+=q.top().w;
		q.pop();
		cnt++;
	}
}

void kruskal2(){
	int cnt=0;
	while(cnt<n+k-1) {
		ans+=q.top().w;
		q.pop();
		cnt++;
	}
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	flag=false;
	for(int i=1; i<=n+k; i++) {
		for(int j=1; j<=n+k; j++) {
			f[i][j]=INF;
		}
	}
	for(int i=1; i<=m; i++) {
		ll u,v,w;
		cin>>u>>v>>w;
		if(u>v) swap(u,v);
		f[u][v]=min(f[u][v],w);
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0) {
			flag=true;
		}
		for(int j=1; j<=n; j++) {
			cin>>opt[j];
		}
	}
	if(flag) {
		for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				for(int to=j+1; to<=n; to++) {
					f[j][to]=min(f[j][to],opt[j]+opt[to]+c[i]);
				}
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				if(f[i][j]!=INF) q.push({i,j,f[i][j]});
			}
		}
		kruskal();
		cout<<ans;
	}
    else{
    	for(int i=1; i<=k; i++) {
			for(int j=1; j<=n; j++) {
				f[j][n+i]=min(f[j][n+i],opt[j]);
			}
		}
		for(int i=1; i<=n+k; i++) {
			for(int j=1; j<=n+k; j++) {
				if(f[i][j]!=INF) q.push({i,j,f[i][j]});
			}
		}
		kruskal2();
		cout<<ans;
	}
}