#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int u;
	int v;
	int w;
}edges[1005005];
int pa[1005005];
int c[105];
int a[100005];
int find(int x){
	if(pa[x]==x){
		return x;
	}else{
		pa[x]=find(pa[x]);
		return pa[x];
	}
}
void merge(int x,int y){
	int p1=find(x);
	int p2=find(y);
	if(p1!=p2)
		pa[p1]=p2;
	return ;
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<=1005005;++i)
		pa[i]=i;
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i){
		cin>>edges[i].u>>edges[i].v>>edges[i].w;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i];
		}
		for(int j=1;j<=m;++j){
			int x=edges[j].u;
			int y=edges[j].v;
			int v=edges[j].w;
			if(a[x]+a[y]+c[i]<=v){
				edges[j].w=a[x]+a[y]+c[i];
			}
		}
	}
	sort(edges+1,edges+1+m,cmp);
	int ans=0;
	for(int i=1;i<=m;++i){
		int x=edges[i].u;
		int y=edges[i].v;
		if(find(x)!=find(y)){
			merge(x,y);
			//cout<<i<<" "<<x<<" "<<y<<endl;
			ans+=edges[i].w;
		}
	}
	cout<<ans;
	return 0;
}

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
100 1 3 2 4
*/

