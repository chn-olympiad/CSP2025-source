#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int N=1e4+5;
const int M=1e6+5;
const int K=15;
int n,m,k,fa[N],d;
ll c[K],x,y,z,ans=0,res=0,p=0;
bool vis[N]; 
struct oops{
	int val,id;
	bool operator < (const oops &u) const{
		return val<u.val;
	}
}a[K][N],tmp[N];
struct edge{
	int u,v,w;
}e[M];
struct node{
	int to,w;
	bool operator < (const node &u) const{
		return w>u.w;
	} 
};
vector<node> vec[N];
int findf(int x){
	return fa[x]==x?x:fa[x]=findf(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void kruskal(){
	int cnt=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(cnt==n-1) break;
		int x=e[i].u,y=e[i].v,z=e[i].w;
		int fx=findf(x),fy=findf(y);
		if(fx==fy) continue;
		ans+=z;
		fa[fx]=fy;
		cnt++;
		vec[x].push_back(node{y,z});
		vec[y].push_back(node{x,z});
	}
}
void dfs(int u,int fa,int maxx,int ed){
//	printf("%d\n",u);
	if(u==ed){
		d=maxx;
		return ;
	}
	for(int i=0;i<vec[u].size();i++){
		int v=vec[u][i].to;
		if(v==fa) continue;
		dfs(v,u,max(maxx,vec[u][i].w),ed);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		e[i]=edge{x,y,z};
	}
	kruskal();
	
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<vec[i].size();j++){
//			printf("%d ",vec[i][j].to);
//		}
//		puts("");
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<vec[i].size();j++){
//			printf("%d ",vec[i][j].w);
//		}
//		puts("");
//	}
	
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j].val);
			a[i][j].id=j;
			tmp[j]=a[i][j];
		}
		sort(tmp+1,tmp+n+1);
		for(int j=1;j<=n;j++) a[i][j]=tmp[j];
	}
	
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++) printf("%d ",a[i][j].val);
//		puts("");
//	}
//	for(int i=1;i<=k;i++){
//		for(int j=1;j<=n;j++) printf("%d ",a[i][j].id);
//		puts("");
//	}
	
	res=ans;
	for(int i=1;i<=k;i++){
		dfs(a[i][1].id,0,0,a[i][2].id);
//		printf("%d\n",d);
		ll q=-d+a[i][1].val+a[i][2].val+c[i];
//		printf("%lld\n",q);
		if(q<0) p+=q;
		//res=min(res,ans+p);
	}
	printf("%lld",ans+p);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
