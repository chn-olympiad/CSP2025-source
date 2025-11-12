#include<bits/stdc++.h>
using namespace std;

const int maxn=10086;
const int maxm=2110000;

int c[maxn];
int a[maxn][maxn];
int ww[maxn][maxn];
int v[maxn];

int n,m,k;

int fa[maxn];

struct Asta{
	int u,v,w;
}e[maxm];
int cnt=0;

bool cmp(Asta x,Asta y){
	return x.w<y.w;
}

void add(int u,int v,int w){
	e[++cnt].u=u;
	e[cnt].v=v;
	e[cnt].w=w;
}

int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}

void fc(){
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		if(cnt==n-1)break;
		int x=find(e[i].u);
		int y=find(e[i].v);
		if(x==y)continue;
		fa[x]=y;
		cnt++;
		ans+=e[i].w;
//		cout<<i<<" "<<e[i].u<<" "<<e[i].v<<"\n";
	}
	cout<<ans<<"\n";
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		ww[u][v]=ww[v][u]=w;
	}
	if(k==0){
		fc();
		return 0;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]==0)v[i]=j;
		}
		for(int p=1;p<=n;p++){
			if(p!=v[i]){
				m++;
				add(p,v[i],a[i][p]);
			}
		}
		for(int j=1;j<=n;j++){
			for(int p=1;p<j;p++){
				if(j!=v[i]){
					if(ww[i][p]>a[i][j]+a[i][p]){
						m++;
						add(j,p,a[i][j]+a[i][p]);
					}
				}
			}
		}
	}
	fc();
	return 0;
}
/*

4 4 1
1 4 6
2 3 7
1 3 5
4 3 4
0 3 3 3 0



*/
