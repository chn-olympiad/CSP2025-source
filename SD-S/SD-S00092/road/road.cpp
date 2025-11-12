#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e7;
int a[N],b[N],w[N];
vector<int> v[N],c[N];
int fa[N];
bool vis[N];
int n,m,k;
int d[20][N];
int ans=0x3f3f3f3f;
int tot;
struct node{
	int a,b,w;
}q[M];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=find(fa[x]);
} 
void dfs(int x){
	if(x==k+1){
		int res=0;
		tot=m;
		for(int i=1;i<=n;i++){
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			q[i].a=a[i];
			q[i].b=b[i];
			q[i].w=w[i];
		}
		for(int qwq=1;qwq<=k;qwq++){
			if(vis[qwq]){
				res+=d[qwq][0];
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						tot++;
						q[tot].a=i;
						q[tot].b=j;
						q[tot].w=d[qwq][j]+d[qwq][i];
					}
				}
			}
		}
		sort(q+1,q+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			if(find(q[i].a)!=find(q[i].b)){
				int fx=find(q[i].a),fy=find(q[i].b);
				fa[fx]=fy;
				res+=q[i].w;
			}
		}
		ans=min(ans,res);
		return ;
	}
	vis[x]=0;
	dfs(x+1);
	vis[x]=1;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>d[i][j];
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}

