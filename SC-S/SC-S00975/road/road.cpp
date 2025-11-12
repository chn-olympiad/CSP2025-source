#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int fa[100100],f[100010];
struct node{
	int u,v,w;
}a[100100];
int find(int x){
	return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
bool merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy){
		fa[x]=fy;
		return 1;
	}
	return 0;
}
bool cmp(node q,node qq){
	return q.w<qq.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		int fei=0;
		cin>>fei;
		for(int j=1;j<=n;j++){
			int s;
			cin>>s;
		}
	}
	sort(a+1,a+m+1,cmp);
	int sum=0;
	for(int i=1;i<=m;i++){
		if(merge(a[i].u,a[i].v)){
			sum+=a[i].w;
		}
	}
	cout<<sum;
}
