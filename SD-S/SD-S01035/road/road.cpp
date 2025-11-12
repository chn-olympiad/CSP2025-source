#include<bits/stdc++.h>
/*
图论：
题目翻译：给定一张n点m边的无向连通图 求 *原图* 最小生成树的边权和
		特别的	
				在本题目中 可以选定任意j<=k个图外点，用cj代价加入图中 用 aij代价与第i个原图上的点建边 
*/
#define lnt long long
#define N 21145
#define pii pair<int,int> 
using namespace std;
// 16:00
struct node{
	int u,v,w;
};
vector<node> road; 
bool cmp(node i,node j){
	return i.w<j.w;
} 
map<pii ,int> cd[30];//经过ci点联通i，j的代价 
int n,m,k;
int c[30];

//并查集检疫合格 
int fa[N];
int find(int x){
	if(fa[x]==0){
		fa[x]=x;
		return x;
	} 
	if(fa[x]==x){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void add(int i,int j){
	i=find(i);
	j=find(j);
	if(i<j){
		swap(i,j);
	} 
	fa[i]=j;
}


int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		if(u>v){	
			swap(u,v);
		}
		road.push_back({u,v,w});
	}
	vector<int> a;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		a.clear();
		for(int j=1;j<=n;j++){
			int w=0;
			cin>>w;
			a.push_back(w);
		}
		for(int j=1;j<=n;j++){
			for(int kk=j+1;kk<=n;kk++){
				cd[i][{j,kk}]=a[j-1]+a[kk-1];
			}
			cd[i][{j,i+n}]=a[j-1];
		}
	}
	int ans=0;
	sort(road.begin(),road.end(),cmp);
	for(node x:road){
		int u=x.u,v=x.v,w=x.w;
		if(find(u)==find(v)){
			continue;
		}
		add(u,v);
		ans+=w;
	}
	cout<<ans<<"\n";
	return 0;
}


