#include<bits/stdc++.h>
using namespace std;
const int N=1e4+30,M=1e6+10;
int n,m,k;
int h[N],idx=1;
struct T{
	int h,e,ne,w,from;
}t[M],p[M];
int fa[N];
int r=0;
int g[N][N];
int c[N][N];
bool f[N][N];
bool cmp(T x,T y){
	return x.w<y.w;
}
void add(int a,int b,int l){
	t[idx].e=b;
	t[idx].from=a;
	t[idx].w=l;
	t[idx].ne=h[a];
	h[a]=idx++;
}
int find(int k){
	return fa[k]==k?k:fa[k]=find(fa[k]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n+15;i++){
		fa[i]=i;
	}
	memset(g,0x3f,sizeof g);
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(x>y){
			swap(x,y);
		}
		add(x,y,z);
	}
	sort(t+1,t+1+m,cmp);
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>c[i][j];
			if(j&&!c[i][j]){
				merge(i+n,j);
			}
		}
	}
	for(int i=1;i<=m;i++){
		int u=t[i].from;
		int v=t[i].e;
		int x=find(u);
		int y=find(v);
		if(x!=y){
			fa[x]=y;
			r+=t[i].w;
		}
	}
	cout<<r;
	return 0;
}
