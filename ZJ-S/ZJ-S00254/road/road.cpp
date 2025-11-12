

#include<iostream>
#include<algorithm>

using namespace std;

#define MAXN 4000099

int head[MAXN];
int cnt = 0;

struct Edge{
	int val;
	int u;
	int to;
	int nxt;
}edge[MAXN];

void addedge(int u,int v,int w){
	edge[++cnt].val = w;
	edge[cnt].to = v;
	edge[cnt].u = u;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

int c1[MAXN];

bool cmp(Edge x,Edge y){
	return x.val < y.val;
}

int p[MAXN];
int r[MAXN];

void Init(int n){
	for(int i = 1;i<=n;i++){
		p[i] = i;
		r[i] = 0;
	}	
}

int find(int x){
	return p[x] == x ? x : p[x] = find(p[x]);
}

void Union(int x,int y){
	if(r[x] > r[y]){
		p[y] = x;
	}else if(r[x] < r[y]){
		p[x] = y;
	}else{
		p[x] = y;
		r[y]++;
	}
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	int n = 0;
	int m = 0;
	int k = 0;
	int c = 0;
	int u = 0;
	int v = 0;
	long long ans = 0;
	int w = 0;
	
	cin >> n >> m >> k;
	
	for(int i=1;i<=m;i++){
		cin >> u >> v >> w;
		addedge(u,v,w);
	}
	
	for(int i=1;i<=k;i++){
		cin >> c;
		
		for(int j=1;j<=n;j++){
			cin >> c1[j];
		}
		
		for(int j=1;j<=n;j++){
			for(int j1 = j+1;j1<=n;j1++){
				addedge(j,j1,c+c1[j]+c1[j1]);
			}
		}
	}
	
	sort(edge+1,edge+cnt+1,cmp);
	
	Init(n);
	
	for(int i=1;i<=cnt;i++){
		if(find(edge[i].u) == find(edge[i].to))continue;
		ans += edge[i].val;
		Union(find(edge[i].u),find(edge[i].to));
	}
	
	cout << ans;
	
	return 0;
}
