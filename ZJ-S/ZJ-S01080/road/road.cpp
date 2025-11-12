#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+1e2;
int n,m,k,cnt,maxx;
struct node{
int x,y,z;
};
node a[N],b[N];
int fa[N],c[N],p[N],minn=2e9;
int v[15][N];
bool cmp(node x,node y){
	return x.z<y.z;
}
int find(int x){
//	cnt++;
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
int ku(int p){
	sort(b+1,b+1+p,cmp);
	int ans=0;
	for(int i=1;i<=p;i++) fa[i]=i;
	for(int i=1;i<=p;i++){
		int fx=find(b[i].x);
		int fy=find(b[i].y);
		if(fx!=fy){
			fa[fx]=fy;
			ans+=b[i].z;
		}
	}
	return ans;
}
void dfs(int x,int y){
	if(x>k){
		memset(b,0,sizeof(b));
		int s=m;
		for(int i=1;i<=m;i++) b[i]=a[i];
		for(int i=1;i<=k;i++){
			if(p[i]==1){
				for(int j=1;j<=n;j++)
					b[++s].z=v[i][j],b[s].x=i+n,b[s].y=j;
			}
		}
		minn=min(minn,ku(s)+y);
		return;
	}
	p[x]=1;
	dfs(x+1,y+c[x]);
	p[x]=0;
	dfs(x+1,y);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y>>b[i].z;
		cout<<ku(m);
		return 0;
	}
	for(int i=1;i<=m;i++){
//		int x,y,z;
//		cin>>x>>y>>z;
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>v[i][j],maxx=max(maxx,v[i][j]);
	}
	if(maxx==0){
		cout<<0;
		return 0;
	}
//	cout<<maxx<<"\n";
	dfs(1,0);
	cout<<minn;
//	cout<<"\n"<<cnt;
}
