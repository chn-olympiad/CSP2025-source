#include<bits/stdc++.h>
using namespace std;
#define int long long
const int _=1010;
int x,y,z,ans,n,m,k,i,b[_][_],fx,fy,c[_],f[_],used[_][_],
dis[_][_],cnt;
struct no{
	int x,y,z;
}a[2000010];
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
bool cmp(no q,no h){
	return q.z<h.z;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	memset(dis,127,sizeof(dis));
	int M=m;m=0;
	for(i=1;i<=M;i++){
		cin>>x>>y>>z,
		dis[x][y]=
		dis[y][x]=
		min(dis[x][y],z);
		if(used[x][y]==0){
			a[++m].x=x;
			a[m].y=y;
			used[x][y]=used[y][x]=1;
		}
	}
	for(i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	}
	for(i=1;i<=k;i++){
		for(int x=1;x<=n;x++)
			for(int y=x+1;y<=n;y++){
				dis[x][y]=dis[y][x]=
				min(dis[x][y],b[i][x]+b[i][y]+c[i]);
				if(used[x][y]==0){
					a[++m].x=x;
					a[m].y=y;
					used[x][y]=used[y][x]=1;
				}
			}
	}
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<=m;i++)
		a[i].z=dis[a[i].x][a[i].y];
	sort(a+1,a+m+1,cmp);
	ans=0;
	for(i=1;i<=m;i++){
		fx=find(a[i].x);fy=find(a[i].y);
		if(fx!=fy){
			f[fx]=fy;
			ans+=a[i].z;
			cnt++;
		}
		if(cnt==n-1){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
}
