#include<bits/stdc++.h>
using namespace std;
struct point{
	int no;
	int val;
	bool vis;//建树访问点
}a[10015];
struct e{
	int u,v,w;
}edge[110005];
int fa[10005];
int n,m,k;
int find(int x){
	return x==fa[x] ? fa[x]:fa[x]=find(fa[x]);
}
bool cmp(e x,e y){
	return x.w<y.w;
}
int ans;
int main(){
	freopen("road0.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w),a[edge[i].u].no=edge[i].u,a[edge[i].v].no=edge[i].v;
	for(int i=m+1;i<=m+k;i++){//几个改造
		scanf("%d",&a[i].val);//带权点
		for(int j=1*(i-m);j<=(i-m)*n;j++){//建立到城市的边
			scanf("%d",&edge[m+j].w);
			edge[m+j].u=m+j;
			edge[m+j].v=j;
			a[edge[m+j].u].no=edge[m+j].u;
			a[edge[m+j].v].no=edge[m+j].v;
			a[edge[m+j].w].no=edge[m+j].w;
			while(j%k==0)break;
		}
	}
	sort(edge+1,edge+m+n*k+1,cmp);
	for(int i=1;i<=m+n*k;i++){
		if(find(edge[i].u)!=find(edge[i].v)){
			fa[edge[i].u]=find(edge[i].v);
			if(!a[edge[i].u].vis){
				a[edge[i].u].vis=true;
				edge[i].w+=a[edge[i].u].val;
			}
			if(!a[edge[i].v].vis){
				a[edge[i].v].vis=true;
				edge[i].w+=a[edge[i].v].val;
			}
			ans+=edge[i].w;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}