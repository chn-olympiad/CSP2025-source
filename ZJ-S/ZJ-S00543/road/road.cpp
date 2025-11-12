#include <bits/stdc++.h>
#define int long long
using namespace std;
int p,ans,nn,tt,ff[200],n,m,k,g[2000010],i,x,y,z,f[1010][1010],a[2000010],b[15][200010],sum,mi;
int find(int x){
	if(g[x]==x)return g[x];
	return g[x]=find(g[x]);
}
struct no{
	int x,y,z;
}d[2000010],c[2000010];
bool cmp(no x,no y){
	return x.z<y.z;
}
void K(){
	int i;
	for(i=1;i<=nn;i++)d[i].x=c[i].x,d[i].y=c[i].y,d[i].z=f[c[i].x][c[i].y];
	sort(d+1,d+1+nn,cmp);
	int t=0;
	for(i=1;i<=tt;i++)g[i]=i;
	for(i=1;i<=nn;i++){
		int fx=find(d[i].x),fy=find(d[i].y);
//		if(fx>fy)swap(fx,fy);
		if(fx!=fy)g[fx]=fy,sum+=d[i].z,t++;
//		if(sum>=mi)return ;
//		if(t==n-1)break;
	}
//	cout<<sum<<"\n"<<nn<<" "<<tt<<"\n";
//	for(i=1;i<=k;i++)cout<<ff[i]<<" ";
//	cout<<"\n";
//	for(i=1;i<=nn;i++)
//		cout<<d[i].x<<" "<<d[i].y<<" "<<f[d[i].x][d[i].y]<<"\n";
//	cout<<"\n\n\n\n";
	mi=min(mi,sum);
}
void solve(){
	int i,j;
	sum=0;
	for(i=1;i<=k;i++)
		if(ff[i]==1)sum+=a[i];
//	for(i=1;i<=m;i++)
//		for(j=1;j<=k;j++)
//			if(ff[j]==1){
//				int x=c[i].x,y=c[i].y;
//				f[y][x]=f[x][y]=min(f[x][y],b[j][x]+b[j][y]);
//			}
	nn=m+n;tt=n+1;
	
	for(j=1;j<=k;j++)
		if(ff[j]==1)for(i=1;i<=n;i++)f[n+1][i]=min(f[n+1][i],b[j][i]);
	if(f[n+1][1]==1e18)nn=m,tt=n;
	for(i=n+1;i<=n+m;i++)c[i].x=n+1,c[i].y=i-n,c[i].z=f[n+1][i];
//	for(i=1;i<=k;i++)
//		if(ff[i]==1)
//			for(tt++,j=1;j<=n;j++)
//				c[++nn].x=tt,c[nn].y=j,f[j][tt]=f[tt][j]=b[i][j];
	K();
	for(i=1;i<=n;i++)f[n+1][i]=1e18;
//	for(i=1;i<=m;i++){
//		int x=c[i].x,y=c[i].y;
//		f[y][x]=f[x][y]=c[i].z;
//	}
}
void dfs(int t){
	int i,j;
	if(t>k){
		solve();
		return ;
	}
	ff[t]=0;
	dfs(t+1);
	ff[t]=1;
	dfs(t+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(i=1;i<=n+1;i++)for(int j=1;j<=n;j++)f[i][j]=1e18;
	mi=1e18;
	for(i=1;i<=m;i++)
		cin>>x>>y>>z,f[x][y]=f[y][x]=z,c[i].x=x,c[i].y=y,c[i].z=z;
	for(i=1;i<=k;i++){
		cin>>a[i];ans=a[i];
		for(int j=1;j<=n;j++)
			cin>>b[i][j],ans+=b[i][j];
		if(ans==0)return cout<<0,0;
		if(mi>ans)mi=ans;        
		p+=a[i];  
	}
	if(p==0){
		for(i=1;i<=k;i++)ff[i]=1;
		solve();
		return cout<<mi,0;
	}
	dfs(1);
	cout<<mi;
}
