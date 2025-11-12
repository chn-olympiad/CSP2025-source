#include<bits/stdc++.h>
using namespace std;
struct node{
	int dis,u,v,w,id;
}vu[1100025];
int n,m,k,fa[10005],cnt;
bool cmp(node x,node y){
	return x.dis+x.w<y.dis+y.w;
}
int findfa(int x){
	if(fa[x]==x) return x;
	return fa[x]=findfa(fa[x]);
}
int shengcheng(int a,int b){
	int ans=0;
	int num=0;
	for(int i=1;i<=m;i++){
		int aa=findfa(vu[i].v),bb=findfa(vu[i].u);
		if(aa!=bb){
			fa[aa]=bb;
			ans+=vu[i].dis+vu[i].w;
			num++;
			if(num==n-1) return ans;
		}
	}
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>vu[i].v>>vu[i].u>>vu[i].dis;
		vu[i].w=0;
	}
	sort(vu+1,vu+m+1,cmp);
	cout<<shengcheng(1,n);
	return 0;
} 
