#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int M=1e6+10;
int n,m,k;
int f[N][N],tt[N][N];
int fa[N];
int ct,c[N];
bool v[N],vt[N];
int ans,cnt;
struct ed{
	int u,v,w,dt;
}a[M*4];
int qfind(int x){
	return (fa[x]==x)?x:fa[x]=qfind(fa[x]);
}
void add_d(int x,int y){
	fa[qfind(x)]=fa[qfind(y)];
}
bool cmp(ed x,ed y){
	return x.w<y.w;
}
void prim(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(a+1,a+cnt+1,cmp);
	int sum=0;
	for(int i=1;i<=cnt;i++){
		if(qfind(a[i].u)!=qfind(a[i].v)){
			add_d(a[i].u,a[i].v);
			if(!v[a[i].u])
				sum++,v[a[i].u]=1;
			if(!v[a[i].v])
				sum++,v[a[i].v]=1;
			vt[a[i].dt]=true;
			ans+=a[i].w;
		}
			
	}
	for(int i=1;i<=k;i++)
		if(vt[i])
			ans+=c[i];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		f[u][v]=w;
		f[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		cin>>ct;
		for(int j=1;j<=n;j++)
			cin>>c[j];
		bool fg=false;
		for(int j=1;j<n;j++)
			for(int p=j+1;p<=n;p++)
				if(!f[j][p]||f[j][p]>=c[j]+c[p]+ct || (fg && f[j][p]>=c[j]+c[p])){
					f[j][p]=f[j][p]=c[j]+c[p];
					tt[j][p]=ct;
					fg=true;
				}	
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++){
			a[++cnt]=(ed){
				i,j,f[i][j],tt[i][j]
			};
		}
	prim();
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

