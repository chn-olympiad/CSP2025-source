#include<bits/stdc++.h>
#define endl '\n'
//#define int long long
using namespace std;
int n,m,k;
struct node{
	int from,to,val;
};
struct node2{
	int x,w;
};
vector<node> e,tree;
int newv[20][10010],ans=0;
vector<node2> v[10010]; 
queue<int> q; 
bitset<10010> vis;
int money[20],fa[10010],dis[10010][10010];
int find(int x){
	if(fa[x]==x){
		return x;
	}
	return x=find(fa[x]);
}
bool query(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy){
		return true;
	}
	return false;
}
void update(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
bool cmp(node x,node y){
	return x.val<y.val;
}
void kruskal(){
	sort(e.begin(),e.end(),cmp);
//	for(int i=0;i<m;i++){
//		cout<<e[i].from<<" "<<e[i].to<<" "<<e[i].val<<endl;
//	}
//	cout<<query(e[0].to,e[0].from)<<endl;
	for(int i=0;i<m;i++){
		if(!query(e[i].to,e[i].from)){
//			cout<<"success"<<endl;
			update(e[i].to,e[i].from);
			ans+=e[i].val;
			tree.push_back({e[i].from,e[i].to,e[i].val});
		}
//		for(int i=1;i<=n;i++){
//			cout<<find(i)<<" ";
//		}
//		cout<<endl;
	}
}
//void init(){
//	for(int i=0;i<tree.size();i++){
//		v[tree[i].to].push_back({tree[i].from,tree[i].val});
//		v[tree[i].from].push_back({tree[i].to,tree[i].val}); 
//	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			dis[i][j]=2e9;
//		}
//		dis[i][i]=0;
//	}
//}
//void dijkstra(int x){
//	q.push(x);
//	while(!q.empty()){
//		int t=q.front();
//		q.pop();
//		if(vis[t]){
//			continue;
//		}
//		vis[t]=1;
//		for(int i=0;i<v[t].size();i++){
////			cout<<(v[t][i])<<endl;
//			if(dis[x][v[t][i].x]>dis[x][t]+v[t][i].w){
//				dis[x][v[t][i].x]=dis[x][t]+v[t][i].w;
//				q.push(v[t][i].x);
//			}
//		}
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		e.push_back({x,y,w});
	} 
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
//	cout<<find(3)<<endl;
	for(int i=1;i<=k;i++){
		cin>>money[i];
		for(int j=1;j<=n;j++){
			cin>>newv[i][j];
		}
	}
	kruskal();
//	for(int i=0;i<tree.size();i++){
//		cout<<tree[i].from<<" "<<tree[i].to<<" "<<tree[i].val<<endl;
//	}
//	init();
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			vis[j]=0;
//		}
//		while(!q.empty()){
//			q.pop();
//		}
//		dijkstra(i);
//	}
////	for(int i=1;i<=n;i++){
////		for(int j=1;j<=m;j++){
////			cout<<dis[i][j]<<" ";
////		}
////		cout<<endl;
////	}
////	cout<<dis[1][4]<<" "<<dis[4][3]<<" "<<dis[4][2]<<endl; 
	///请输入代码 
	cout<<ans<<endl;
	return 0;
} 
//k很小，考虑从k下手
//我们考虑若k=0，则kruskal即可
//考虑升级以后所带来的收益是什么
//就是将w[i][j]缩小为w[i][k]+w[k][j]
//所以可以预处理出w[i][j]
//但是不难发现w[i][j]的贡献构成边可能有重边 
//可以预处理出最小生成树,然后在树上统计新建这个点及联通的最小代价 
//坏了写了这么多然后没考虑138行的情况导致挂了） 
//O(mlogn)(应该是)，期望得分 10 pts. 
//hyw
//AFO.
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/ 
