#include<bits/stdc++.h>
using namespace std;
const int N=10010;
const int M=1000010;
int a[N][N];
int n,m,k;
int p[15][N];
int c[15];
bool vis[N];
int d[N];int sum;long long ans=0;
void prim(){
	int minn=INT_MAX;
	int pos;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(d[i]<minn){
				minn=d[i];
				pos=i;
			}
		}
	}
	vis[pos]=1;
	d[pos]=minn;sum++;
	for(int i=1;i<=n;i++){
		if(!vis[i])	d[i]=min(d[i],a[i][pos]);
	}
}
int read(){
	char x;x=getchar();
	int f=1;
	while(x<'0'||x>'9'){
		if(x=='-')	f=-1;
		x=getchar();
	}
	int sum=0;
	while(x>='0'&&x<='9'){
		sum=sum*10+(x-'0');
		x=getchar();
	}
	return sum*f;
} 
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=m;i++){
		int u,v,w;u=read();v=read();w=read();
		//scanf("%d%d%d",&u,&v,&w);
		a[u][v]=min(a[u][v],w);
		a[v][u]=min(a[v][u],w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			//scanf("%d",&p[i][j]);
			p[i][j]=read();
		}
	}
	for(int jj=1;jj<=k;jj++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				a[j][i]=min(a[j][i],p[jj][i]+p[jj][j]);
				a[i][j]=min(a[i][j],p[jj][i]+p[jj][j]);
			}
		}
	}
	vis[1]=1;d[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=a[1][i];
	}
	sum++;
	while(sum<n){
		prim();
	}
	for(int i=1;i<=n;i++){
		ans+=d[i];
	}
	cout<<ans<<'\n';
	return 0;
} 
