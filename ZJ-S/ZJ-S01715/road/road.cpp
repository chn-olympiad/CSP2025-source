#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+10;
int n,m,k,x,y,z,cnt,dls,ans;
int fa[N],c[N],b[N][N],f[N][N],vis[N][N],flag[N];
struct node{
	int u,v,w;
}a[N*N];
bool cmp(node i,node j){
	return i.w<j.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		f[x][y]=min(f[x][y],z);
		f[y][x]=min(f[y][x],z);
	}
	for(int i=1;i<=n;i++) f[i][i]=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			for(int l=1;l<=n;l++){
				if(j==l) continue;
				if(c[i]+b[i][j]+b[i][l]<f[l][j]) f[l][j]=f[j][l]=min(f[l][j],c[i]+b[i][j]+b[i][l]),vis[l][j]=vis[j][l]=i;
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[i][j]!=f[0][0]){
				a[++cnt].u=i;
				a[cnt].v=j;
				a[cnt].w=f[i][j];
			}
	sort(1+a,1+a+cnt,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt;i++){
		int r1=find(a[i].u),r2=find(a[i].v);
		if(r1!=r2){
			fa[r1]=r2;
			ans+=a[i].w;
			if(flag[vis[a[i].u][a[i].v]]) ans-=c[vis[a[i].u][a[i].v]];
			if(vis[a[i].u][a[i].v]) flag[vis[a[i].u][a[i].v]]=1;
			dls++;
		}
		if(dls==n-1) break;
	}
	cout<<ans;
	return 0;
}