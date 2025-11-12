#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,fa[10005],c[15][10005];
struct node{
	int u,v,w;
}edge1[N],edge2[N],edge3[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(fa[x]==x)	return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int f=0;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>edge1[i].u>>edge1[i].v>>edge1[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i][1]; 
		if(c[i][1]!=0)	f=1;
		for(int j=1;j<=n;j++){
			cin>>c[i][j+1];
			if(c[i][j+1]!=0)	f=1;
		}
	}
	if(!f){
		cout<<0;
		return 0;
	}	
	int n2=0,sum=0,ii=0,ans=0;
	sort(edge1+1,edge1+m+1,cmp);
	while(n2<n-1){
		ii++;
		if(find(edge1[ii].u)!=find(edge1[ii].v)){
			n2++;
			edge2[n2]=edge1[ii];
			ans+=edge1[ii].w;
			fa[find(edge1[ii].u)]=find(edge1[ii].v);
		}
	}
	cout<<ans;
	return 0;
}

