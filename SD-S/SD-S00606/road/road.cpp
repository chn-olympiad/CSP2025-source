#include<bits/stdc++.h>
using namespace std;
const int N=1e6+20;
const int M=12;
struct edge{
	int a,b,w;
	bool operator < (const edge &W){
		return w<W.w;
	}
}edges[N],edgess[2*N];
long long ans=1e18;
int n,m,k,p[N],c[M][N];
bool vis[M];
int find(int x){
	if(p[x]!=x){
		p[x]=find(p[x]);
	}
	return p[x];
}
void Kru(){
	for(int i=1;i<=m;i++){
		edgess[i].a=edges[i].a;
		edgess[i].b=edges[i].b;
		edgess[i].w=edges[i].w;
	}
	int nn=n,mm=m;
	long long res=0;
	for(int i=1;i<=k;i++){
		if(vis[i]==true){
			res+=c[i][0];
			++nn;
			for(int j=1;j<=n;j++){
				++mm;
				edgess[mm].a=nn;
				edgess[mm].b=j;
				edgess[mm].w=c[i][j];
			}
		}
	}
	for(int i=1;i<=nn;i++){
		p[i]=i;
	}
	sort(edgess+1,edgess+1+mm);
	for(int i=1;i<=mm;i++){
		int a=edgess[i].a,b=edgess[i].b,w=edgess[i].w;
		a=find(a);
		b=find(b);
		if(a!=b){
			p[a]=b;
			res+=w;
		}
	}
	ans=min(ans,res);
	return ;
}
void dfs(int u){
	if(u==k+1){
		Kru();
		return ;
	}
	vis[u]=false;
	dfs(u+1);
	vis[u]=true;
	dfs(u+1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>edges[i].a>>edges[i].b>>edges[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
		}
	}
	if(k==0){
		long long res=0;
		sort(edges+1,edges+1+m);
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a=edges[i].a,b=edges[i].b,w=edges[i].w;
			a=find(a);
			b=find(b);
			if(a!=b){
				p[a]=b;
				res+=w;
			}
		}
		cout<<res<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
