#include<bits/stdc++.h>
using namespace std;
#define N 10050
#define fi first
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
int n,m,k;
int u,v;
ll w;
ll g[N][N];
ll c[20];
bool vis[20];
ll a;
int size[N];
int fa[N];
priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>> > q;
struct node{
	int x,y;
};
vector<node> q1;
ll sum;
ll sum2=inf;

bool cmp(node x,node y){
	if(g[x.x][x.y]<g[y.x][y.y]){
		return 1;
	}
	return 0;
}

int getfa(int x){
	if(fa[x]==x){
		return x;
	}
	return getfa(fa[x]);
}

void merge(int u,int v){
	int fau=getfa(u);
	int fav=getfa(v);
	if(size[fau]>size[fav]){
		fa[v]=fau;
		size[fau]+=size[fav];
	}
	else{
		fa[u]=fav;
		size[fav]+=size[fau];
	}
}

void ksk(){
	while(!q.empty()){
		auto it=q.top();
		int w=it.fi;
		int u=it.se.fi;
		int v=it.se.se;
		q.pop();
		if(fa[u]==fa[v]){
			continue;
		}
		sum+=w;
		merge(u,v);
	}
}

bool check(){
	int tmp=fa[1];
	for(int i=2;i<=n;i++){
		if(fa[i]!=tmp){
			return 0;
		}
	}
	return 1;
}

void ksk1(){
	while(q1.size()>0){
		int u=q1[0].x;
		int v=q1[0].y;
		q1.erase(q1.begin(),q1.begin()+1);
		if(fa[u]==fa[v]){
			continue;
		}
		if(check()){
			break;
		}
		sum2+=g[u][v];
		if(u>n&&!vis[u-n]){
			vis[u-n]=1;
			for(int i=1;i<=n;i++){
				g[u][i]-=c[u-n];
				g[i][u]=g[u][i];
			}
			sort(q1.begin(),q1.end(),cmp);
		}
		if(v>n&&!vis[v-n]){
			vis[v-n]=1;
			for(int i=1;i<=n;i++){
				g[v][i]-=c[v-n];
				g[i][v];
			}
			sort(q1.begin(),q1.end(),cmp);
		}
		merge(u,v);
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[u][v]=g[v][u]=w;
		q.push({w,{u,v}});
		q1.push_back({u,v});
	}	
	for(int i=1;i<=n;i++){
		fa[i]=i;
		size[i]=1;
	}
	ksk();
	if(k){
		int f;
		sum2=0;
		for(int i=1;i<=k;i++){
			f=0;
			cin>>c[i];
			if(c[i]==0){
				f++;
			}
			for(int j=1;j<=n;j++){
				cin>>a;
				if(a==0){
					f++;
				}
				g[n+i][j]=a+c[i];
				g[j][n+i]=a+c[i];
				q1.push_back({n+i,j});
			}
			if(f==n+1){
				cout<<0;
				return 0;
			}
		}
		sort(q1.begin(),q1.end(),cmp);
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
			size[i]=1;
		}
		ksk1();
	}
	cout<<min(sum,sum2);
	return 0;
}