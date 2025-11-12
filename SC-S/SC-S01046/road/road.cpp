//別搞啊ccf 真的燃盡了
#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;

const int N=1e5+7;
int n,m,k,tot,c[N],a[N],fa[N],cc[N],result[N];
struct Node{
	int nxt,to,w;
}e[N<<1];

bool cmp(Node x,Node y){
	return x.w<y.w;
}

void add(int u,int v,int w){
	e[++tot].nxt=u;e[tot].to=v;e[tot].w=w;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

int kruskul(){
	int cnt=1,ans=0;
	for(int i=1;i<=tot;i++){
		int u=e[i].nxt,v=e[i].to,w=e[i].w;
		if(find(u)==find(v))continue;
		cnt++;ans+=w;
		fa[find(u)]=find(v);
//		cout<<u<<' '<<v<<' '<<w<<'\n';
	}
	return ans;
}

signed main(){
	freopen("road.in","r",stdin);freopen("road.out","w",stdout);
	ios::sync_with_stdio(NULL);cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++){
		int u,v,dis;cin>>u>>v>>dis;
		add(u,v,dis);add(v,u,dis);
	}
	sort(e+1,e+1+tot,cmp);
	result[0]=kruskul();
	
	for(int i=1,id=n+1;i<=k,id<=n+k;i++,id++){
		for(int it=1;it<=n+k;it++)fa[it]=it;
		cin>>c[i];
		cc[i]=cc[i-1]+c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			add(j,id,a[j]);add(id,j,a[j]);
		}
		sort(e+1,e+1+tot,cmp);
		result[i]=kruskul();
	}
	
	int ans_min=0x7fffffff;
	for(int i=0;i<=k;i++)ans_min=min(result[i]+cc[i],ans_min);
	cout<<ans_min;
	
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/