#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> pi;
const int N=1e4+10,M=1e6+10;
int n,m,k;
struct node{
	int x,y,z;
}aw[M];
//struct edge{
//	int to,len,next;
//}a[M*5];
//int pre[N],totk=0;
int fa[N];
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
bool cmp(node a,node b){
	return a.z<b.z;
}
//void add(int u,int v,int len){
//	a[++totk]={v,len,pre[u]};
//	pre[u]=totk;
//}
//priority_queue<pi,vector<pi>,greater<pi>> q;
//bool f[N];
//int d[N];
//void dijkstra(int s){
//	q.push({0,s});
//	d[s]=0;
//	while(!q.empty()){
//		int p=q.top().second;q.pop();
//		if(f[p]) continue;
//		f[p]=true;
//		for(int i=pre[p];i;i=a[i].next){
//			int to=a[i].to;
//			if(d[p]+a[i].len<d[to]){
//				d[to]=d[p]+a[i].len;
//				q.push({d[to],to});
//			}
//		}
//	}
//}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&aw[i].x,&aw[i].y,&aw[i].z);
//		add(aw[i].x,aw[i].y,aw[i].z);
//		add(aw[i].y,aw[i].x,aw[i].z);
	}
//	dijkstra(1);
//	cout<<d[n]<<endl;
	for(int i=1,dian;i<=k;i++){
		scanf("%lld",&dian);
		for(int j=1,xy;j<=n;j++){
			scanf("%lld",&xy);
//			add(n+dian,j,xy);
//			add(j,n+dian,xy);
		}
//		add(0,n+dian,0);
	}
	sort(aw+1,aw+m+1,cmp);
	if(k==0){
		//最小生成树
		for(int i=1;i<=n;i++) fa[i]=i;
		int ans=0;
		for(int i=1;i<=n;i++){
			int fx=find(aw[i].x),fy=find(aw[i].y);
			if(fx!=fy){
				fa[fx]=fy;
				ans+=aw[i].z;
			}
		}
		printf("%lld\n",ans);
		return 0;
	}
//	int mi=LLONG_MAX;
//	for(int i=1;i<=n;i++) mi=min(mi,d[i]);
//	printf("%lld\n",mi);
	return 0;
}

