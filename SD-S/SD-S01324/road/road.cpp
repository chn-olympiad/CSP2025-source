#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{
	int x,y,z;
};
node p[10000010];
bool cmp(node a,node b){
	return a.z<b.z;
}
int a[10][100010];
int c[11];
int ans=9e18;
int vis[1000010];
int f[1000010];
int find(int x){
	if(f[x]!=x){
		f[x]=find(f[x]);
	}
	return f[x];
}
int cnt;
int n,m,k;
int v[100];
void dfs(int now){
	if(now==k+1){
		int sum=0;
		int s=n;
		for(int i=1;i<=k;i++){
			if(vis[n+i]){
				f[n+i]=n+i;
				s++;
				sum+=c[i];
			}
		}
		for(int i=1;i<=n+k;i++)f[i]=i;
		for(int i=1;i<=cnt;i++){
			if(!vis[p[i].x]||!vis[p[i].y])continue;
			int fx=find(p[i].x);
			int fy=find(p[i].y);
			if(fx!=fy){
				sum+=p[i].z;
				f[fx]=fy;
				s--;
				if(s==1){
					ans=min(ans,sum);
					return;
				}
			}
		}
		return;
	}
	vis[n+now]=1;
	dfs(now+1);
	vis[n+now]=0;
	dfs(now+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>p[i].x>>p[i].y>>p[i].z;
	}
	cnt=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			p[++cnt]={n+i,j,a[i][j]};
		}
	}
	for(int i=1;i<=n;i++)vis[i]=1;
	sort(p+1,p+cnt+1,cmp);
	dfs(1);
	cout<<ans;
	return 0;
}
